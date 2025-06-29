from PySide6.QtWidgets import QApplication, QWidget, QMainWindow, QPushButton
from PySide6.QtCore import QSize

import sys


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Ch3: Initial State")

        self.button = QPushButton("Click Me!")
        self.button.clicked.connect(self.on_button_clicked)

        self.windowTitleChanged.connect(
            lambda title: print(f"Window title changed to: {title}")
        )

        self.setMinimumSize(QSize(800, 600))
        self.setCentralWidget(self.button)

    def on_button_clicked(self):
        print("Button clicked!")
        self.button.setText("Clicked!")
        self.button.setEnabled(False)
        self.setWindowTitle("Ch3: Button Clicked")


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
