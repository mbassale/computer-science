import sys

from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QPushButton,
    QDialog,
    QDialogButtonBox,
    QVBoxLayout,
    QLabel,
)


class CustomDialog(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)

        self.setWindowTitle("Custom Dialog")
        self.setModal(True)

        buttons = QDialogButtonBox.Ok | QDialogButtonBox.Cancel

        self.buttonBox = QDialogButtonBox(buttons)
        self.buttonBox.accepted.connect(self.accept)
        self.buttonBox.rejected.connect(self.reject)

        self.layout = QVBoxLayout()
        message = QLabel("Something happened, is that OK?")
        self.layout.addWidget(message)
        self.layout.addWidget(self.buttonBox)
        self.setLayout(self.layout)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Dialog Example")

        button = QPushButton("Click me!")
        button.clicked.connect(self.on_button_clicked)
        self.setCentralWidget(button)

    def on_button_clicked(self):
        print("Button clicked!")

        dlg = CustomDialog(self)
        if dlg.exec():
            print("Accepted")
        else:
            print("Rejected")


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
