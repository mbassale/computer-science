import sys

from PySide6.QtWidgets import QApplication, QMainWindow, QPushButton, QDialog


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Dialog Example")

        button = QPushButton("Click me!")
        button.clicked.connect(self.on_button_clicked)
        self.setCentralWidget(button)

    def on_button_clicked(self):
        print("Button clicked!")

        dlg = QDialog(self)
        dlg.setWindowTitle("Dialog")
        dlg.exec()


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
