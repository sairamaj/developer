from sentence_transformers import SentenceTransformer
from sklearn.preprocessing import normalize
import numpy as np
import faiss

# Load Sentence-BERT model
model = SentenceTransformer('all-MiniLM-L6-v2')

# Example documents
documents = [
    "The quick brown fox jumps over the lazy dog.",
    "Artificial Intelligence is shaping the future.",
    "OpenAI develops cutting-edge AI models."
]

# Generate and normalize embeddings
embeddings = model.encode(documents)
normalized_embeddings = normalize(embeddings, axis=1)

# Initialize FAISS index with Inner Product (cosine similarity)
dimension = normalized_embeddings.shape[1]
index = faiss.IndexFlatIP(dimension)
index.add(normalized_embeddings)

print("Documents indexed successfully!")

# Query the system
query = "should not match"
query_embedding = model.encode([query])
normalized_query_embedding = normalize(query_embedding, axis=1)

# Search for the top 3 matches
distances, indices = index.search(normalized_query_embedding, k=3)

# Apply threshold filtering
threshold = 0.4  # Adjust based on your requirements
for idx, distance in zip(indices[0], distances[0]):
    if distance >= threshold:  # Higher values indicate better matches
        print(f"Matched Document: {documents[idx]} with similarity: {distance}")

# https://huggingface.co/sentence-transformers/all-MiniLM-L6-v2