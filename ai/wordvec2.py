from gensim.models import Word2Vec

# Sample corpus for demonstration
sentences = [
    ['car', 'automobile'],
    ['car', 'road', 'vehicle'],
    ['banana', 'fruit'],
    ['good', 'positive'],
    ['bad', 'negative']
]

# Train the Word2Vec model
model = Word2Vec(sentences, vector_size=100, window=5, min_count=1, workers=4)

# Similarity examples
similarity_1 = model.wv.similarity('car', 'automobile')
similarity_0 = model.wv.similarity('car', 'banana')
# Assuming 'good' and 'bad' context exists
similarity_neg1 = model.wv.similarity('good', 'bad')

print("Similarity between 'car' and 'automobile':", similarity_1)
print("Similarity between 'car' and 'banana':", similarity_0)
print("Similarity between 'good' and 'bad':", similarity_neg1)
