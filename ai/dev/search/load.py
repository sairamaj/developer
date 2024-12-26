from sentence_transformers import SentenceTransformer
from sklearn.preprocessing import normalize
import numpy as np
import faiss
import pickle

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

# Save documents for reference
with open("documents.pkl", "wb") as f:
    pickle.dump(documents, f)

# Initialize FAISS index
dimension = normalized_embeddings.shape[1]
index = faiss.IndexFlatIP(dimension)  # Inner Product for cosine similarity
index.add(normalized_embeddings)

# Save FAISS index
faiss.write_index(index, "document_index.faiss")

print("Embeddings and index saved successfully!")

# https://huggingface.co/sentence-transformers/all-MiniLM-L6-v2