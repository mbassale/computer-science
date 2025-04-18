import sys

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QApplication,
    QComboBox,
    QMainWindow,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("QComboBox Example")

        widget = QComboBox()
        widget.addItems(["Option 1", "Option 2", "Option 3"])
        widget.setCurrentIndex(0)
        widget.currentIndexChanged.connect(self.index_changed)
        widget.currentTextChanged.connect(self.text_changed)
        widget.setToolTip("Select an option")
        widget.setEditable(True)
        widget.setInsertPolicy(QComboBox.InsertPolicy.InsertAlphabetically)

        self.setCentralWidget(widget)

    def index_changed(self, i):
        print(f"Index changed: {i}")

    def text_changed(self, text):
        print(f"Text changed: {text}")


app = QApplication(sys.argv)
window = MainWindow()
window.show()

app.exec()
