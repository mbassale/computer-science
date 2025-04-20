import sys

from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QPushButton,
    QMessageBox,
)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Message Dialog Example")

        button = QPushButton("Click me!")
        button.clicked.connect(self.on_button_clicked)
        self.setCentralWidget(button)

    def on_button_clicked(self):
        print("Button clicked!")

        result = QMessageBox.question(
            self,
            "Question Dialog",
            "Do you want to continue?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No,
        )
        if result == QMessageBox.StandardButton.Yes:
            print("Yes!")
        elif result == QMessageBox.StandardButton.No:
            print("No!")


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
