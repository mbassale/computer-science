import sys

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QApplication,
    QSpinBox,
    QMainWindow,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("QSpinBox Example")

        self.spinBox = QSpinBox()
        self.spinBox.setRange(18, 99)
        self.spinBox.setPrefix("Age:")
        self.spinBox.setSuffix(" years")
        self.spinBox.setSingleStep(1)

        self.spinBox.valueChanged.connect(self.on_value_changed)

        self.setCentralWidget(self.spinBox)

    def on_value_changed(self, value):
        print(f"Value changed: {value}")


app = QApplication(sys.argv)
window = MainWindow()
window.show()

app.exec()
