from PySide6.QtWidgets import QApplication, QWidget, QMainWindow, QPushButton
from PySide6.QtCore import QSize

import sys


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.button_is_checked = True

        self.setWindowTitle("My Application")

        self.button = QPushButton("Click Me!")
        self.button.setCheckable(True)
        self.button.setChecked(self.button_is_checked)
        self.button.clicked.connect(self.on_button_clicked)
        self.button.clicked.connect(self.on_button_toggled)

        self.setFixedSize(QSize(800, 600))
        self.setCentralWidget(self.button)

    def on_button_clicked(self):
        print("Button clicked!")

    def on_button_toggled(self):
        self.button_is_checked = self.button.isChecked()
        print(f"Button toggled!: {self.button_is_checked}")


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
