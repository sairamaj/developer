import spacy
from termcolor import colored
# python -m spacy download en_core_web_sm

# Load the spaCy model for English
nlp = spacy.load("en_core_web_sm")

# Sample text
text = "Hugging Face is a company based in New York City, founded by Clem Delangue in November 2016."

# Process the text with spaCy
doc = nlp(text)

# Define color codes based on entity labels
label_colors = {
    "ORG": "blue",   # Organizations in blue
    "GPE": "green",  # Geopolitical entities in green (e.g., countries, cities)
    "PERSON": "yellow",  # Persons in yellow
    "MONEY": "cyan",   # Money in cyan
}

print([(w.text, w.pos_) for w in doc])

str = ", ".join([f"{w.text}, {w.pos_})" for w in doc])
print(str)

print('-------------------------')
# Print entities with color coding
# for ent in doc.ents:
    # # Get the color for the entity label
    # color = label_colors.get(ent.label_, "white")  # Default color if not defined
    # print(colored(f"{ent.text} ({ent.label_})", color))
