from llama_index.readers.database import DatabaseReader
import os

current_dir = os.path.abspath(os.path.dirname(__file__))
parent_dir = os.path.dirname(current_dir)
db_path = os.path.join(parent_dir, "data", "example.db")
db_url = f"sqlite:///{db_path}"
print(f"Database URL: {db_url}")
reader = DatabaseReader(
    uri=db_url,
)
query = "SELECT * FROM products"
documents = reader.load_data(query=query)
for doc in documents:
    print(doc.get_content())
