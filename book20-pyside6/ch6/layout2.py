import sys

from PySide6.QtWidgets import QApplication, QMainWindow, QHBoxLayout, QWidget
from color_widget import Color


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Layout2 Example")

        layout = QHBoxLayout()
        layout.addWidget(Color("red"))
        layout.addWidget(Color("green"))
        layout.addWidget(Color("blue"))
        layout.setSpacing(5)
        layout.setContentsMargins(5, 5, 5, 5)

        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
