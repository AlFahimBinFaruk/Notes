import boto3
import os
import io
import logging
from PIL import Image

logger = logging.getLogger()
logger.setLevel(logging.INFO)

s3_client = boto3.client("s3")

# ── Configuration ──────────────────────────────────────────────────────────────
INPUT_PREFIX = "input/"
OUTPUT_PREFIX = "output/"
TARGET_SIZE = (800, 800)  # Max width x height (aspect ratio preserved)
OUTPUT_FORMAT = "JPEG"  # JPEG | PNG | WEBP
OUTPUT_QUALITY = 85  # 1–95 (JPEG / WEBP only)
# ──────────────────────────────────────────────────────────────────────────────

SUPPORTED_FORMATS = {".jpg", ".jpeg", ".png", ".webp", ".bmp", ".gif", ".tiff"}
# UPD 22


def lambda_handler(event, context):
    for record in event["Records"]:
        bucket = record["s3"]["bucket"]["name"]
        key = record["s3"]["object"]["key"]

        # Only process files inside the input/ folder
        if not key.startswith(INPUT_PREFIX):
            logger.info(f"Skipping {key} — not in '{INPUT_PREFIX}' folder.")
            continue

        # Check file extension
        ext = os.path.splitext(key)[1].lower()
        if ext not in SUPPORTED_FORMATS:
            logger.info(f"Skipping {key} — unsupported format '{ext}'.")
            continue

        try:
            resized_key = _build_output_key(key)
            logger.info(
                f"Processing: s3://{bucket}/{key} → s3://{bucket}/{resized_key}"
            )

            # Download original image
            response = s3_client.get_object(Bucket=bucket, Key=key)
            image_data = response["Body"].read()

            # Resize
            resized_data, content_type = _resize_image(image_data, TARGET_SIZE)

            # Upload resized image
            s3_client.put_object(
                Bucket=bucket,
                Key=resized_key,
                Body=resized_data,
                ContentType=content_type,
            )

            logger.info(
                f"Successfully uploaded resized image to s3://{bucket}/{resized_key}"
            )

        except Exception as e:
            logger.error(f"Error processing {key}: {str(e)}")
            raise

    return {"statusCode": 200, "body": "Image resizing complete."}


def _build_output_key(input_key: str) -> str:
    """
    Replace the input prefix with the output prefix.
    e.g. "input/photos/cat.jpg" → "output/photos/cat.jpg"
    """
    relative_path = input_key[len(INPUT_PREFIX) :]  # strip "input/"
    filename, _ = os.path.splitext(relative_path)
    output_ext = f".{OUTPUT_FORMAT.lower()}"
    # Normalize JPEG extension
    if output_ext == ".jpeg":
        output_ext = ".jpg"
    return f"{OUTPUT_PREFIX}{filename}{output_ext}"


def _resize_image(image_data: bytes, max_size: tuple) -> tuple[bytes, str]:
    """
    Resize image to fit within max_size while preserving aspect ratio.
    Returns (image_bytes, content_type).
    """
    with Image.open(io.BytesIO(image_data)) as img:
        # Convert palette/RGBA images for JPEG output
        if OUTPUT_FORMAT == "JPEG" and img.mode in ("RGBA", "P", "LA"):
            img = img.convert("RGB")

        img.thumbnail(max_size, Image.LANCZOS)

        buffer = io.BytesIO()
        save_kwargs = {"format": OUTPUT_FORMAT}
        if OUTPUT_FORMAT in ("JPEG", "WEBP"):
            save_kwargs["quality"] = OUTPUT_QUALITY
            save_kwargs["optimize"] = True

        img.save(buffer, **save_kwargs)
        buffer.seek(0)

    content_type_map = {
        "JPEG": "image/jpeg",
        "PNG": "image/png",
        "WEBP": "image/webp",
    }
    return buffer.getvalue(), content_type_map.get(OUTPUT_FORMAT, "image/jpeg")
