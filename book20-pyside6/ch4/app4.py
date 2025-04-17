from PySide6.QtWidgets import (
    QApplication,
    QWidget,
    QMainWindow,
    QPushButton,
    QBoxLayout,
    QLineEdit,
    QLabel,
)
from PySide6.QtCore import QSize

import sys
from random import choice


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.n_times_clicked = 0

        self.setWindowTitle("My Application")

        self.label = QLabel("[Placeholder]")
        self.input = QLineEdit()
        self.input.textChanged.connect(self.label.setText)

        layout = QBoxLayout(QBoxLayout.Direction.TopToBottom)
        layout.addWidget(self.input)
        layout.addWidget(self.label)

        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)

        self.setFixedSize(QSize(800, 600))


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
