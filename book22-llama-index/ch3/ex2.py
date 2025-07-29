from llama_index.readers.wikipedia import WikipediaReader
loader = WikipediaReader()
documents = loader.load_data(
    pages=[
        'Jupiter_(Planet)',
        'Saturn_(Planet)',
    ]
)
print(f"Loaded {len(documents)} documents.")
for doc in documents:
    print(f"Text: {doc.text[:100]}...")  # Print first 100 characters of the text
    print("-" * 40)  # Separator for readability
