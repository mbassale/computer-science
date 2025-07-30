import os
import psutil
import logging
from llama_index.core import Settings, SimpleDirectoryReader
from llama_index.core.node_parser import SentenceSplitter
from llama_index.core.extractors import TitleExtractor
from llama_index.llms.llama_cpp import LlamaCPP
from pathlib import Path

# --- Configure local LLM ---
models_dir = Path(__file__).parent.parent / "models"
model_path = models_dir / "Qwen3-4B-Q6_K.gguf"
llm = LlamaCPP(
    model_path=str(model_path),
    max_new_tokens=512,
    context_window=8192,
    model_kwargs={"n_gpu_layers": -1},
    verbose=True,
)
Settings.llm = llm

process = psutil.Process(os.getpid())
start_mem = process.memory_info().rss / (1024 * 1024)

logging.basicConfig(level=logging.DEBUG)

# --- Load and process document ---
data_dir = Path(__file__).parent.parent / "data"
file_path = data_dir / "short.txt"
reader = SimpleDirectoryReader(input_files=[file_path], recursive=False)
documents = reader.load_data()
logging.info("Loaded document: %s", file_path)
logging.info("Document metadata: %s", documents[0].get_metadata_str())

parser = SentenceSplitter.from_defaults(include_prev_next_rel=True)
nodes = parser.get_nodes_from_documents(documents)
logging.info("Number of nodes created: %d", len(nodes))

# --- Extract summaries from nodes ---
summary_extractor = TitleExtractor()
metadata_list = summary_extractor.extract(nodes)
logging.info("Number of metadata entries extracted: %d", len(metadata_list))
for metadata in metadata_list:
    logging.debug("---- Metadata ----")
    logging.debug("Metadata: %s", str(metadata))
    logging.debug("-----")


end_mem = process.memory_info().rss / (1024 * 1024)
logging.info("Memory usage: %s MB", end_mem - start_mem)
