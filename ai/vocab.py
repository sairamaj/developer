
from gensim.models import Word2Vec

# Sample text documents
documents = [
    "The quick brown fox jumps over the lazy dog.",
    "Never jump over the lazy dog quickly.",
    "Foxes are quick and they can jump high."
]

# Tokenize the documents
tokenized_docs = [doc.lower().split() for doc in documents]

# Train the Word2Vec model
model = Word2Vec(sentences=tokenized_docs, vector_size=100, window=5, min_count=1, workers=4)

# Accessing the automatically generated vocabulary
vocabulary = model.wv.key_to_index
print(vocabulary)
