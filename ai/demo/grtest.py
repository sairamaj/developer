import gradio as gr
import spacy
from transformers import pipeline

sentiment_analsysis = pipeline("sentiment-analysis")
ner = pipeline("ner")
nlp = spacy.load("en_core_web_sm")

def predict_sentiment(text):
	result = sentiment_analsysis(text)
	return result[0]['label'],result[0]['score']

def ner_using_spacy(text):
	doc = nlp(text)
	str = ", ".join([f"{w.text}, {w.pos_})" for w in doc])
	return str
	
def ner_using_hf_default_model(text):
    results = ner(text)
    str = ", ".join([f"{entity['entity']} -{entity['word']})" for entity in results])
    return str
	
with gr.Blocks() as demo:
    with gr.Accordion("NER",open=False):
        gr.Markdown("Named Entity Recognition")
        input = gr.Textbox(lines=2, placeholder="Type your text here")
        output_using_web_sm =gr.Text(label='NER-Using en_core_web_sm')
        output_using_hf_default =gr.Text(label='NER-Using Hugging Face (default model)')
        submit = gr.Button("Submit")
        submit.click(fn=ner_using_spacy,inputs=[input],outputs=[output_using_web_sm]) 
        submit.click(fn=ner_using_hf_default_model,inputs=[input],outputs=[output_using_hf_default]) 
    with gr.Accordion("Sentiment Analysis",open=False):
        gr.Markdown("Uses pipeline to do sentiment analysis")
        input = gr.Textbox(lines=2, placeholder="Type your text here")
        submit = gr.Button("Submit")
        sentiment =gr.Text(label='Sentiment')
        score = gr.Text(label='Score')
		
        submit.click(fn=predict_sentiment,inputs=[input],outputs=[sentiment,score]) 
    with gr.Accordion("Classification",open=False):
        gr.Markdown("Classify the images")
    with gr.Accordion("Search",open=False):
        gr.Markdown("Uses Search")

demo.launch()
