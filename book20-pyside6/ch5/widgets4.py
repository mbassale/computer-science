import sys

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QApplication,
    QListWidget,
    QMainWindow,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("QListWidget Example")

        self.list = QListWidget()
        self.list.addItems(["Option 1", "Option 2", "Option 3"])
        self.list.setSelectionMode(QListWidget.MultiSelection)
        self.list.selectionModel().selectionChanged.connect(self.on_selection_changed)

        self.setCentralWidget(self.list)

    def on_selection_changed(self, selected, deselected):
        print("Selected items:", self.list.selectedItems())


app = QApplication(sys.argv)
window = MainWindow()
window.show()

app.exec()
