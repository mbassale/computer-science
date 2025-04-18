import sys

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QApplication,
    QSlider,
    QMainWindow,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("QSlider Example")

        self.slider = QSlider(Qt.Horizontal)
        self.slider.setRange(0, 100)
        self.slider.setSingleStep(10)
        self.slider.setTickInterval(10)
        self.slider.setTickPosition(QSlider.TicksBelow)
        self.slider.setValue(50)
        self.slider.valueChanged.connect(self.on_value_changed)

        self.setCentralWidget(self.slider)

    def on_value_changed(self, value):
        print(f"Value changed: {value}")


app = QApplication(sys.argv)
window = MainWindow()
window.show()

app.exec()
