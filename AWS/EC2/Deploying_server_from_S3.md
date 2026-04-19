```bash
#!/bin/bash

# ---- CONFIGURE THESE ----
S3_BUCKET="fm-backend-bucket"
S3_FOLDER="fm_backend"
APP_DIR="/home/ec2-user/fm_backend"
APP_ENTRY="main:app"
APP_PORT="80"
# -------------------------

echo ">>> Updating packages..."
sudo yum update -y

echo ">>> Installing Python & pip..."
sudo yum install python3-pip -y

echo ">>> Downloading app from S3..."
mkdir -p $APP_DIR
aws s3 cp s3://$S3_BUCKET/$S3_FOLDER/ $APP_DIR/ --recursive

echo ">>> Installing dependencies..."
pip3 install -r $APP_DIR/requirements.txt

echo ">>> Starting FastAPI app..."
cd $APP_DIR
sudo nohup uvicorn $APP_ENTRY --host 0.0.0.0 --port $APP_PORT > $APP_DIR/app.log 2>&1 &

echo ""
echo "✅ App running"
```