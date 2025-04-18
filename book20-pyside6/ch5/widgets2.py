import sys

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QApplication,
    QCheckBox,
    QMainWindow,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Checkbox Example")

        # Create a checkbox and set its text
        self.checkbox = QCheckBox("Hello, World!")
        self.checkbox.setCheckState(Qt.CheckState.Checked)
        self.checkbox.stateChanged.connect(self.show_state)

        # Set the checkbox as the central widget of the main window
        self.setCentralWidget(self.checkbox)

        # Set the size of the main window
        self.resize(800, 600)

    def show_state(self, state):
        print(f"Checkbox state changed: {state}")
        print("Checked: ", Qt.CheckState(state) == Qt.CheckState.Checked)


app = QApplication(sys.argv)
window = MainWindow()
window.show()

app.exec()
