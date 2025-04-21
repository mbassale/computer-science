import sys

from PySide6.QtGui import QMouseEvent
from PySide6.QtWidgets import QApplication, QMainWindow, QLabel


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Mouse Events")
        self.label = QLabel("Client in this window")
        self.setCentralWidget(self.label)

    def mouseMoveEvent(self, event: QMouseEvent):
        self.label.setText(f"Mouse moved to: {event.position()}")

    def mousePressEvent(self, event: QMouseEvent):
        self.label.setText(f"Mouse pressed at: {event.position()}")

    def mouseReleaseEvent(self, event: QMouseEvent):
        self.label.setText(f"Mouse released at: {event.position()}")

    def mouseDoubleClickEvent(self, event: QMouseEvent):
        self.label.setText(f"Mouse double-clicked at: {event.position()}")


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
