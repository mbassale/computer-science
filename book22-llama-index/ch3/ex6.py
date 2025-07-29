import os
import psutil

from llama_index.core import SummaryIndex, Document
from llama_index.core.schema import TextNode

process = psutil.Process(os.getpid())
start_mem = process.memory_info().rss / (1024 * 1024)  # Convert to MB

nodes = [
    TextNode(text="Lionel Messi is a football player from Argentina."),
    TextNode(text="Cristiano Ronaldo is a football player from Portugal."),
    TextNode(text="Neymar Jr. is a football player from Brazil."),
    TextNode(text="Lionel Messi's hometown is Rosario, Argentina."),
    TextNode(text="Cristiano Ronaldo's hometown is Funchal, Portugal."),
    TextNode(text="Neymar Jr.'s hometown is Mogi das Cruzes, Brazil."),
    TextNode(text="Lionel Messi was born on June 24, 1987."),
]
index = SummaryIndex(nodes)

query_engine = index.as_query_engine()
response = query_engine.query("What is Messi's hometown?")
print(response)

print("-----")
end_mem = process.memory_info().rss / (1024 * 1024)  # Convert to MB
print(f"Memory usage: {end_mem - start_mem:.2f} MB")
