* Models
  * LLama (Large Language Model by Meta AI)
  * GPT-4: Developed by OpenAI
  * Gemini: Developed by Google
* Parameters
* Context Length
* Embedding length
* Quantization
* Temparature

* Principles
  * Give direction
  * Specify Format
  * Provide examples
  * Evaluate Quality (iteration)
  * Divide labor (multiple steps)

```txt
Instructions
---

Example Output
---

Rules
---

```

* Prompts
  * Use --- for separation
  * Use : for dialog
  * Explain the text below like I'am five:
  * Continue (use this to get more info for the same topic you have already asked)
  * Use delimiters
* General
  * Use list to most
    * start with least information and expand on the items
  * Use detailed instructions
  * Specify the steps
    ```txt
      Step-1

      Step-2
    ```
  * Lets think step by step:
  * Role prompting
    * Act as a


[prompts](https://github.com/f/awesome-chatgpt-prompts)

[learnprompts](learnprompting.org)

[latent.space](latent.space)

[promptingguide](promptingguide.ai)

[promptsroyale](prompsroyale.com)

[Course](https://github.com/BrightPool/udemy-prompt-engineering-course)

* Meta Prompt
  * kind of reverse engineering.
  * from output to prompt
    ```txt
        Create a ChatGPT prompt that would have generated the following code.
    ```
* Chain of thought reasoning.

Traditional AI, often referred to as machine learning (ML), has primarily focused on analytic tasks like classification and prediction. Generative AI (gen AI) goes a step further with its ability to create new, original content


* AI is the broad field
* ML is a subset focused on learning from data, 
* NLP is a domain within AI/ML focused on language, and 
* LLMs are cutting-edge tools within NLP that leverage ML techniques to handle language tasks.

prompt(input) -> completion(output) through inference(process of generating)

___________

# NLP
 * Speech Transcription
 * Neural Machine Translaction
 * Chatbots
 * Q&A
 * Text summarization
 * Image captioning
 * Video captioning
 * Sentiment analysis

* Lemmatization
  * Meaning of the word based on the dictionary(morphological analysis) - extract the base word
* Stemming
  * extract the root of the word.
* Named-entity recognition (NER)
  * Identifies the Place, persons, dates etc.,
* Stopwords
 * Words that appear very often and don't help to understand the context of the document.
* Dependency Parsing
  * Parent-child relation

* Text Summarization
  1. Pre processing the texts
    * lowercase, remove stop wards
  2. Word frequency
  3. Weighted word frequency
  4. Sentence tokenization (tokenization at sentence level)
  5. Score the sentences
  6. Order the sentences
  7. Generate the summary.
____

* colab.research.google.com
  * display
    ```python
      from spacy import displacy
      displacy.render(document, style='dep', jupyter=True)
    ```
___
* Python
  * matplotlib.pyplot for plotting
  * spacy
  * wordCloud
  * ntlk
  * goose3
  * sumy (https://pypi.org/project/sumy)
  * sklearn
  * numpy
  
[TF-IDF-Cosine Similarity](https://janav.wordpress.com/2013/10/27/tf-idf-and-cosine-similarity/)

[resource-0](https://colab.research.google.com/drive/1IHGBdiLdR8TN5CMLwpObjGckFolDPaB_?usp=sharing)

[resources-1](https://colab.research.google.com/drive/1lRX8mGzfQqdgeLckhLxEMknt4_eaM6QB?usp=sharing)


[intro-to-llms-365](https://github.com/l-newbould/intro-to-llms-365)