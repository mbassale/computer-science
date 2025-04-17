from PySide6.QtWidgets import QApplication, QWidget, QMainWindow, QPushButton
from PySide6.QtCore import QSize

import sys


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("My Application")

        button = QPushButton("Click Me!")
        button.clicked.connect(self.on_button_clicked)

        self.setFixedSize(QSize(800, 600))
        self.setCentralWidget(button)

    def on_button_clicked(self):
        print("Button clicked!")


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
