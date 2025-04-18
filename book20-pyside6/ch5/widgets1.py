import sys

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QApplication, QLabel, QMainWindow


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("My Application")

        # Create a label and set its text
        self.label = QLabel("Hello, World!")
        self.label.setAlignment(Qt.AlignCenter)
        font = self.label.font()
        font.setPointSize(30)
        self.label.setFont(font)
        self.label.setAlignment(
            Qt.AlignmentFlag.AlignHCenter | Qt.AlignmentFlag.AlignVCenter
        )

        # Set the label as the central widget of the main window
        self.setCentralWidget(self.label)

        # Set the size of the main window
        self.resize(800, 600)


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
