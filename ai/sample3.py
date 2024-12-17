import en_core_web_sm
import spacy
from spacy import displacy

from goose3 import Goose
g = Goose()
url = "https://en.wikipedia.org/wiki/Natural_language_processing"
article = g.extract(url)
print(article.title)
# print(article.cleaned_text)
# print(article.links)

nlp = spacy.load('en_core_web_sm')
document = nlp(article.cleaned_text)
# for token in document:
   # print(token.text, '-', token.pos_)
html = displacy.render(document, style = 'ent')

with open("c:\\temp\\test.html", "w") as f: f.write(html)