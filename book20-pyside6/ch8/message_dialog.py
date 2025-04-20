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

        dlg = QMessageBox(self, icon=QMessageBox.Icon.Critical)
        dlg.setWindowTitle("Message Dialog")
        dlg.setText("This is a message dialog.")
        dlg.setStandardButtons(
            QMessageBox.StandardButton.Yes
            | QMessageBox.StandardButton.No
            | QMessageBox.StandardButton.Cancel
        )
        result = dlg.exec()
        if result == QMessageBox.StandardButton.Yes:
            print("Yes!")
        elif result == QMessageBox.StandardButton.No:
            print("No!")
        elif result == QMessageBox.StandardButton.Cancel:
            print("Cancel!")


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
