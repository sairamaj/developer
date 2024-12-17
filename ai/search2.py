# pip install faiss-cpu gensim
# pip install scikit-learn

# Load saved faiss index

import faiss

# Load the index from disk
index = faiss.read_index("doc_vectors.index")

# reload the vector model
from gensim.models import Word2Vec

# Load the pre-trained Word2Vec model
model = Word2Vec.load("word2vec.model")

# create search functionality
import numpy as np

def document_vector(doc, model):
    # Remove out-of-vocabulary words
    doc = [word for word in doc if word in model.wv.index_to_key]
    return np.mean(model.wv[doc], axis=0)

def search_documents(query, model, index):
    # Tokenize and create a vector for the query
    query_vector = document_vector(query.lower().split(), model).reshape(1, -1)

    # Search the index for the nearest neighbors
    distances, indices = index.search(query_vector, k=2)

    return indices.flatten(), distances.flatten()

# Example documents
documents = [
    "The quick brown fox jumps over the lazy dog.",
    "Never jump over the lazy dog quickly.",
    "Foxes are quick and they can jump high."
]

# Example search query
query = "not available"
indices, distances = search_documents(query, model, index)

# Display the results
for idx, dist in zip(indices, distances):
    print(f"Document: {documents[idx]}, Distance: {dist}")
