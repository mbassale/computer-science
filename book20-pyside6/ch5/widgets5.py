import sys

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QApplication,
    QLineEdit,
    QMainWindow,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("QLineEdit Example")

        self.lineEdit = QLineEdit()
        self.lineEdit.setPlaceholderText("Type something here...")
        self.lineEdit.setMaxLength(20)

        self.lineEdit.returnPressed.connect(self.on_return_pressed)
        self.lineEdit.selectionChanged.connect(self.on_selection_changed)
        self.lineEdit.textChanged.connect(self.on_text_changed)
        self.lineEdit.textEdited.connect(self.on_text_edited)

        self.setCentralWidget(self.lineEdit)

    def on_return_pressed(self):
        print("Return pressed:", self.lineEdit.text())

    def on_selection_changed(self):
        print("Selection changed:", self.lineEdit.selectedText())

    def on_text_changed(self, text):
        print("Text changed:", text)

    def on_text_edited(self, text):
        print("Text edited:", text)


app = QApplication(sys.argv)
window = MainWindow()
window.show()

app.exec()
