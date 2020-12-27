[IAM explained](https://medium.com/@thomas.storm/aws-iam-deep-dive-chapter-2-users-groups-roles-policies-330bfac3b505)

## IAM
* 2 ways of user authentication
    * API acces key/secret -> used by aws cli and aws sdk
    * Login/Password - AWS console
* Role
    * Assume  (don't confuse as role attached to user/group here)    
    * Trust
        * Another Aws account
        * Cognito
* Policy
    * Set of statements
        * Statement
            * Effect (Allow/deny)
            * Action (API Calls)
            * Resource 
            * Condition 
# Sample
```json
    {
    "Version": "2012-10-17",
    "Sid": "AllowCreateBuckets",
    "Statement": [ 
        {
        "Effect": "Allow",
        "Action": "s3:*",
        "Resource": [
            "arn:aws:s3:::mybucket",
            "arn:aws:s3:::mybucket/*"
        ]
        },
        {
        "Effect": "Deny",
        "Action": "s3:Delete*",
        "Resource": [
            "arn:aws:s3:::mybucket/*",
            "arn:aws:s3:::mybucket"
        ]
        }
    ]
    }

    * Allow bucket __mybucket__
    * Allow operations within bucket
    * Deny delete bucket

```
    * Attached to User/Group/Role

### How credential read
* as part of SDK call
* Environment variable
* ~/.aws/credential file
* http://169.25.169.254  (instance metadata)
* If it is still empty, then exception

### Principal
* Entity which is allowed to perform API calls
    * AWS account and root user
    * IAM users
    * Federated users (using web identity or SAML federation)
    * IAM roles
    * Assumed-role sesions
    * AWS services
    * Anonmous users
    
    Specifying an AWS Account in Principal section allows to not only give access to calls within that account but also enable Cross-Account Roles
    
### AWS Organizations
    * mutliple accounts



