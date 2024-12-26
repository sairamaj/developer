import spacy
nlp = spacy.load("en_core_web_sm")
import en_core_web_sm
nlp = en_core_web_sm.load()
doc = nlp("Hugging Face is a company based in New York City, founded by Clem Delangue in November 2016.")
print([(w.text, w.pos_) for w in doc])