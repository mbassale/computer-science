import os
import psutil
import logging
from llama_index.core.node_parser import CodeSplitter
from llama_index.readers.file import FlatReader
from pathlib import Path

CHUNK_SIZE = 512
CHUNK_OVERLAP = 128

process = psutil.Process(os.getpid())
start_mem = process.memory_info().rss / (1024 * 1024)

logging.basicConfig(level=logging.DEBUG)

reader = FlatReader()
file_path = Path(__file__).resolve()
documents = reader.load_data(file_path)
logging.info("Loaded document: %s", file_path)
logging.info("Document metadata: %s", documents[0].get_metadata_str())

splitter = CodeSplitter.from_defaults(
    language="python", chunk_lines=5, chunk_lines_overlap=2, max_chars=CHUNK_SIZE
)
nodes = splitter.get_nodes_from_documents(documents)
logging.info("Number of nodes created: %d", len(nodes))
for node in nodes:
    logging.debug("---- Node ----")
    logging.debug("Node ID: %s", node.node_id)
    logging.debug("Node text: %s..", node.get_content())
    logging.debug("Node metadata: %s", node.get_metadata_str())
    logging.debug("Node length: %d", len(node.get_content()))

end_mem = process.memory_info().rss / (1024 * 1024)
logging.info("Memory usage: %s MB", end_mem - start_mem)
