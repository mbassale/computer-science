import sys

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QApplication,
    QDial,
    QMainWindow,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("QDial Example")

        self.dial = QDial()
        self.dial.setRange(0, 100)
        self.dial.setValue(50)
        self.dial.setNotchesVisible(True)
        self.dial.setWrapping(True)
        self.dial.setSingleStep(10)

        self.dial.valueChanged.connect(self.on_value_changed)

        self.setCentralWidget(self.dial)

    def on_value_changed(self, value):
        print(f"Value changed: {value}")


app = QApplication(sys.argv)
window = MainWindow()
window.show()

app.exec()
