# pip install gensim faiss-cpu

# prepare documents.
documents = [
    "The quick brown fox jumps over the lazy dog.",
    "Never jump over the lazy dog quickly.",
    "Foxes are quick and they can jump high."
]

# tokenize documents
tokenized_docs = [doc.lower().split() for doc in documents]

# train a word2vec model
from gensim.models import Word2Vec

# Train the Word2Vec model
model = Word2Vec(sentences=tokenized_docs, vector_size=100, window=5, min_count=1, workers=4)
# Save the model to a file
model.save("word2vec.model")

# create document vectors
import numpy as np

def document_vector(doc, model):
    # Remove out-of-vocabulary words
    doc = [word for word in doc if word in model.wv.index_to_key]
    return np.mean(model.wv[doc], axis=0)

# Create document vectors
doc_vectors = np.array([document_vector(doc, model) for doc in tokenized_docs])

# save documents
import faiss

# Create the Faiss index
index = faiss.IndexFlatL2(doc_vectors.shape[1])

# Add document vectors to the index
index.add(doc_vectors)

# Save the index to disk (optional)
faiss.write_index(index, "doc_vectors.index")


# implement a search

from sklearn.metrics.pairwise import cosine_similarity

def search_documents(query, model, index):
    # Tokenize and create a vector for the query
    query_vector = document_vector(query.lower().split(), model).reshape(1, -1)

    # Search the index for the nearest neighbors
    distances, indices = index.search(query_vector, k=2)

    return indices.flatten(), distances.flatten()

# Example search
query = "quick jump"
indices, distances = search_documents(query, model, index)

print(f"Indices of nearest neighbors: {indices}")
print(f"Distances to nearest neighbors: {distances}")

# Display the results
for idx, dist in zip(indices, distances):
    print(f"Document: {documents[idx]}, Distance: {dist}")
