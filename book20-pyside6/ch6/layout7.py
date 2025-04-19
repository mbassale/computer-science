import sys

from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QComboBox,
    QFormLayout,
    QLineEdit,
    QSpinBox,
    QWidget,
    QLabel,
)
from color_widget import Color


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("QFormLayout Example")

        layout = QFormLayout()

        self.data = {
            "name": "",
            "age": 18,
            "iceCream": "Vanilla",
        }

        self.name = QLineEdit()
        self.name.textChanged.connect(lambda text: self.data.update({"name": text}))
        self.name.textChanged.connect(self.validate)
        self.age = QSpinBox()
        self.age.setRange(0, 120)
        self.age.valueChanged.connect(lambda value: self.data.update({"age": value}))
        self.age.valueChanged.connect(self.validate)
        self.iceCream = QComboBox()
        self.iceCream.addItems(["Vanilla", "Chocolate", "Strawberry"])
        self.iceCream.currentTextChanged.connect(
            lambda text: self.data.update({"iceCream": text})
        )

        layout.addRow("Name", self.name)
        layout.addRow("Age", self.age)
        layout.addRow("Favorite Ice Cream", self.iceCream)

        self.error = QLabel()
        self.error.setStyleSheet("color: red;")
        layout.addWidget(self.error)

        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)

    def validate(self):
        if not self.name.text():
            self.error.setText("Name cannot be empty")
        elif self.age.value() < 10:
            self.error.setText("You must be at least 10 years old")
        else:
            self.error.setText("")


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
