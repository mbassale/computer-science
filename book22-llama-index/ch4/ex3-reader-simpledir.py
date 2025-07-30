import os
import logging
from llama_index.core import SimpleDirectoryReader
from llama_index.core import VectorStoreIndex
import psutil

process = psutil.Process(os.getpid())
start_mem = process.memory_info().rss / (1024 * 1024)

logging.basicConfig(level=logging.DEBUG)

home_dir = os.path.expanduser("~")
DIRECTORY = os.path.join(home_dir, "Documents")
logging.info("Documents directory: %s", DIRECTORY)
if not os.path.exists(DIRECTORY):
    logging.error("Directory '%s' does not exist.", DIRECTORY)
    exit(1)

reader = SimpleDirectoryReader(
    input_dir=DIRECTORY,
    recursive=True,
    required_exts=[".pdf", ".md", ".txt", ".docx", ".html", ".csv"],
    num_files_limit=10,
)
documents = reader.load_data()
for doc in documents:
    logging.info("Document metadata: %s", doc.get_metadata_str())
logging.info("Loaded %d documents.", len(documents))

index = VectorStoreIndex.from_documents(documents)
logging.info("Index built successfully.")

qe = index.as_query_engine()
query = "What are the specific addresses covered in the lease agreement for Marco Bassaletti, enumerate the full addresses?"
response = qe.query(query)
logging.info("Query: %s", query)
logging.info("Response: %s", response)

logging.info("-----")
end_mem = process.memory_info().rss / (1024 * 1024)
logging.info("Memory usage: %s MB", end_mem - start_mem)
