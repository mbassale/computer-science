import os
import psutil
from llama_index.core import Document
from llama_index.core.schema import TextNode, NodeRelationship, RelatedNodeInfo

process = psutil.Process(os.getpid())
start_mem = process.memory_info().rss / (1024 * 1024)  # Convert to MB

doc = Document(
    text="This is sentence 1. This is sentence 2. This is sentence 3.",
    metadata={"author": "Marco Bassaletti"},
)
print(doc)

n1 = TextNode(text="This is sentence 1.", node_id=doc.doc_id)
n2 = TextNode(text="This is sentence 2.", node_id=doc.doc_id)
n3 = TextNode(text="This is sentence 3.", node_id=doc.doc_id)
n1.relationships[NodeRelationship.NEXT] = n2.node_id
n2.relationships[NodeRelationship.PREVIOUS] = n1.node_id
n2.relationships[NodeRelationship.NEXT] = n3.node_id
n3.relationships[NodeRelationship.PREVIOUS] = n2.node_id
print(n1, n2, n3)
print("-----")
print(n1.relationships)
print(n2.relationships)
print(n3.relationships)

end_mem = process.memory_info().rss / (1024 * 1024)  # Convert to MB
print(f"Memory usage: {end_mem - start_mem:.2f} MB")
