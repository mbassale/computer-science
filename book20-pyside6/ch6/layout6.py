import sys

from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QTabWidget,
)
from color_widget import Color


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Layout6 Example")

        tabs = QTabWidget()
        tabs.setTabPosition(QTabWidget.West)
        tabs.setDocumentMode(True)
        tabs.setMovable(True)

        for color in ["red", "green", "blue"]:
            widget = Color(color)
            tabs.addTab(widget, color.capitalize())

        self.setCentralWidget(tabs)


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
