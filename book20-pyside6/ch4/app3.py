from PySide6.QtWidgets import QApplication, QWidget, QMainWindow, QPushButton
from PySide6.QtCore import QSize

import sys
from random import choice

window_titles = [
    "My Application",
    "My Application 2",
    "My Application 3",
    "My Application 4",
    "My Application 5",
]


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.n_times_clicked = 0

        self.setWindowTitle("My Application")

        self.button = QPushButton("Click Me!")
        self.button.clicked.connect(self.on_button_clicked)

        self.windowTitleChanged.connect(self.on_window_title_changed)

        self.setFixedSize(QSize(800, 600))
        self.setCentralWidget(self.button)

    def on_button_clicked(self):
        print("Button clicked!")
        self.n_times_clicked += 1
        print(f"Button clicked {self.n_times_clicked} times")
        self.setWindowTitle(choice(window_titles))

    def on_window_title_changed(self, title):
        print(f"Window title changed to: {title}")


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
