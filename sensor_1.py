import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore

# Use a service account.
cred = credentials.Certificate('/workspace/TC104B/serviceAccount.json')

app = firebase_admin.initialize_app(cred)

db = firestore.client()

sensor_1_ref = db.collection(u'sensor_1')
docs = sensor_1_ref.stream()

for doc in docs:
    print(f'{doc.id} => {doc.to_dict()}')