from transformers import pipeline
from rich.console import Console
from rich.text import Text

def colored_text(text: str, color: str) -> Text:
    return Text(text, style=f"bold {color}")

# models: https://huggingface.co/models
# Load the pre-trained model for NER
#ner = pipeline("ner", model="dbmdz/bert-large-cased-finetuned-conll03-english", tokenizer="dbmdz/bert-large-cased-finetuned-conll03-english")
ner = pipeline("ner")


# Example text to extract entities from
#text = "Hugging Face is a company based in New York City, founded by Clem Delangue in November 2016."
print("user input")
text = input('please enter text')
# Perform NER
results = ner(text)

str = ", ".join([f"{entity['entity']} -{entity['word']})" for entity in results])
print(str)

# # Initialize console for colored output
# console = Console()

# # Print results with colored labels
# for entity in results:
    # color = "green" if "ORG" in entity['entity'] else "blue" if "LOC" in entity['entity'] else "yellow" if "PER" in entity['entity'] else "white"
    # console.print(colored_text(f"Entity: {entity['word']}, Label: {entity['entity']}, Score: {entity['score']}", color))

