from sentence_transformers import SentenceTransformer
from sklearn.preprocessing import normalize
import numpy as np
import faiss
import pickle

# Load documents
with open("documents.pkl", "rb") as f:
    documents = pickle.load(f)

# Load FAISS index
index = faiss.read_index("document_index.faiss")

# Load Sentence-BERT model
model = SentenceTransformer('all-MiniLM-L6-v2')

# Query the system
while True:
    query = input("Please enter your query (or type 'quit' to exit): ")
    if query.lower() == 'quit':
        break
    query_embedding = model.encode([query])
    normalized_query_embedding = normalize(query_embedding, axis=1)

    # Search for the top 3 matches
    distances, indices = index.search(normalized_query_embedding, k=3)

    # Apply threshold filtering
    found = False
    threshold = 0.4  # Adjust based on your requirements

    print('--------------------')
    for idx, distance in zip(indices[0], distances[0]):
        print(f"Matched Document: {documents[idx]} with similarity: {distance}")
    print('--------------------')
    for idx, distance in zip(indices[0], distances[0]):
        if distance >= threshold:  # Higher values indicate better matches
            print(f"Matched Document: {documents[idx]} with similarity: {distance}")
            found = True
    if not found:
        print("No matching documents found.")

# https://huggingface.co/sentence-transformers/all-MiniLM-L6-v2