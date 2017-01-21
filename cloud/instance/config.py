SITE = "127.0.0.1:5000"

# MongoDB Config
SECRET_KEY = 'hackathon'
MONGODB_DB = 'hackathon'
MONGODB_HOST = 'localhost'
MONGODB_PORT = 27017


# This breaks CSRF if True, since it ensures that cookies are always encrypted via SSL
SESSION_COOKIE_SECURE = False

WTF_CSRF_ENABLED = True
WTF_CSRF_SSL_STRICT = False

# UPLOADS
ALLOWED_EXTENSIONS = set(['png', 'jpg', 'jpeg', 'gif'])
UPLOAD_FOLDER = 'images/'
