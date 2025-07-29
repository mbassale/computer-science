import os
import psutil
import logging
from llama_index.core import Document, SummaryIndex
from llama_index.core.node_parser import SimpleNodeParser
from llama_index.readers.wikipedia import WikipediaReader

logging.basicConfig(level=logging.DEBUG)

process = psutil.Process(os.getpid())
start_mem = process.memory_info().rss / (1024 * 1024)

loader = WikipediaReader()
documents = loader.load_data(pages=["Messi Lionel"])
print(f"Loaded {len(documents)} documents from Wikipedia.")

parser = SimpleNodeParser.from_defaults()
nodes = parser.get_nodes_from_documents(documents)

index = SummaryIndex(nodes)
query_engine = index.as_query_engine()
print("Ask me anything about Lionel Messi!")
while True:
    query = input("Enter your question (or 'exit' to quit): ")
    if query.lower() == "exit":
        break
    response = query_engine.query(query)
    print(f"Response: {response}")

print("-----")
end_mem = process.memory_info().rss / (1024 * 1024)  # Convert to MB
print(f"Memory usage: {end_mem - start_mem:.2f} MB")
