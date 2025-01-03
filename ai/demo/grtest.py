import gradio as gr

from transformers import pipeline

sentiment_analsysis = pipeline("sentiment-analysis")

def predict_sentiment(text):
	result = sentiment_analsysis(text)
	return result[0]['label'],result[0]['score']

with gr.Blocks() as demo:
    with gr.Accordion("NER-NLP",open=False):
        gr.Markdown("Uses Spacy to do NER")
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
