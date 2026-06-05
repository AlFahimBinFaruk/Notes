# First Download the .pem file containing security cred's while creating EC2 instance if you don't have any from previous or you want to use new credentials for this ec2.

# The security file is needed proper permission.
chmod 0400 security-cred.pem

# "ec2-user" is the default user of AWS AMI.
ssh -i security-cred.pem ec2-user@public-ip-of-instance.

