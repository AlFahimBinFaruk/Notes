### Zip Creation Process

```bash

docker run --rm \
  -v $(pwd):/output \
  --platform linux/amd64 \
  python:3.10 \
  pip install Pillow -t /output/package

cp lambda_function.py package/
cd package && zip -r ../lambda.zip .
```
