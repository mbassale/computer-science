import os
import psutil
import logging
from pathlib import Path
from llama_index.core import SimpleDirectoryReader, Settings
from llama_index.core.extractors import TitleExtractor
from llama_index.core.node_parser import SentenceSplitter
from llama_index.core.ingestion import IngestionPipeline, IngestionCache
from llama_index.llms.llama_cpp import LlamaCPP
from llama_index.core.schema import TransformComponent


class CustomTransformation(TransformComponent):
    def __call__(self, nodes, **kwargs):

        return nodes


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

logging.basicConfig(level=logging.DEBUG)

process = psutil.Process(os.getpid())
start_mem = process.memory_info().rss / (1024 * 1024)
logging.info("Initial memory usage: %s MB", start_mem)


# --- Load and process document ---
data_dir = Path(__file__).parent.parent / "data"
file_path = data_dir / "short.txt"
reader = SimpleDirectoryReader(input_files=[file_path], recursive=False)
documents = reader.load_data()
logging.info("Loaded document: %s", file_path)
logging.info("Document metadata: %s", documents[0].get_metadata_str())
try:
    cached_hashes = IngestionCache.from_persist_path(str(data_dir / "cache.json"))
except FileNotFoundError:
    cached_hashes = None

pipeline = IngestionPipeline(
    transformations=[
        CustomTransformation(),
        SentenceSplitter(),
        TitleExtractor(),
    ],
    cache=cached_hashes,
)

nodes = pipeline.run(documents=documents, show_progress=True)
pipeline.cache.persist(str(data_dir / "cache.json"))
end_mem = process.memory_info().rss / (1024 * 1024)
logging.info("Memory usage after processing: %s MB", end_mem)
