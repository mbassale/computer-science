from llama_index.readers.web import SimpleWebPageReader

urls = ["https://docs.llamaindex.ai"]
documents = SimpleWebPageReader(html_to_text=True).load_data(urls)
for doc in documents:
    print(doc.get_content())
