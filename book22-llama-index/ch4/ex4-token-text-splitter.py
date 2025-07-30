import os
import psutil
import logging
from llama_index.core.node_parser import TokenTextSplitter
from llama_index.readers.file import FlatReader
from pathlib import Path

CHUNK_SIZE = 512
CHUNK_OVERLAP = 128

process = psutil.Process(os.getpid())
start_mem = process.memory_info().rss / (1024 * 1024)

logging.basicConfig(level=logging.DEBUG)

reader = FlatReader()
current_dir = Path(__file__).resolve().parent
parent_dir = current_dir.parent
file_path = parent_dir / "data" / "faust1.txt"
documents = reader.load_data(file_path)
logging.info("Loaded document: %s", file_path)
logging.info("Document metadata: %s", documents[0].get_metadata_str())

splitter = TokenTextSplitter(
    chunk_size=CHUNK_SIZE,
    chunk_overlap=CHUNK_OVERLAP,
    separator="\n",
    backup_separators=[".", "!", "?", ",", ";", ":", " ", "\n"],
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
