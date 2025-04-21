import sys

from PySide6.QtGui import QMouseEvent
from PySide6.QtWidgets import QApplication, QMainWindow, QLabel, QMenu


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Mouse Events")
        self.label = QLabel("Click in this window")
        self.setCentralWidget(self.label)

    def contextMenuEvent(self, event):
        context = QMenu(self)
        context.addAction("Option 1")
        context.addAction("Option 2")
        context.addAction("Option 3")
        context.exec(event.globalPos())


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
