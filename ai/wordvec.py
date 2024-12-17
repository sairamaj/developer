from gensim.models import Word2Vec

# Sample corpus
sentences = [
    ['the', 'cat', 'sat', 'on', 'the', 'mat'],
    ['the', 'dog', 'barked'],
    ['the', 'bird', 'sang']
]

# Train the Word2Vec model
model = Word2Vec(sentences, vector_size=100, window=5, min_count=1, workers=4)

# Get the vector for a word
vector = model.wv['cat']

# Find similar words
similar_words = model.wv.most_similar('cat')
print(similar_words)
