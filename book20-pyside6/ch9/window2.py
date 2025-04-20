import sys

from PySide6.QtWidgets import (
    QApplication,
    QLabel,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget,
)


class AnotherWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Another Window")
        layout = QVBoxLayout()
        label = QLabel("This is another window")
        layout.addWidget(label)
        self.setLayout(layout)


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Main Window")
        self.another_window = AnotherWindow()

        button = QPushButton("Open Another Window")
        button.clicked.connect(self.on_open_another_window)

        self.setCentralWidget(button)

    def on_open_another_window(self):
        print("Button clicked, opening another window")
        if self.another_window.isVisible():
            self.another_window.hide()
        else:
            self.another_window.show()


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
