from llama_index.core import Document

text = "The quick brown fox jumps over the lazy dog."
doc = Document(text=text, 
               metadata={"source": "ch3/ex1.py", "author": "Marco Bassaletti"},
               id_='1')
print(doc)
