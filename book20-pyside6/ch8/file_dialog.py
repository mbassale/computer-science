import sys

from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QPushButton,
    QFileDialog,
    QVBoxLayout,
    QWidget,
)

FILE_FILTERS = [
    "Text files (*.txt)",
    "Python files (*.py)",
    "All files (*.*)",
]


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("File Dialog Example")

        layout = QVBoxLayout()

        button = QPushButton("Open File Dialog")
        button.clicked.connect(self.on_open_file_clicked)
        layout.addWidget(button)

        button = QPushButton("Select Folder Dialog")
        button.clicked.connect(self.on_select_folder_clicked)
        layout.addWidget(button)

        container = QWidget()
        container.setLayout(layout)
        self.setCentralWidget(container)

    def on_open_file_clicked(self):
        print("Button clicked!")

        intial_filter = FILE_FILTERS[2]

        file_name, selected_filter = QFileDialog.getOpenFileName(
            self,
            "Select a file",
            filter=";;".join(FILE_FILTERS),
            selectedFilter=intial_filter,
        )
        print("File name:", file_name)
        print("Selected filter:", selected_filter)

    def on_select_folder_clicked(self):
        folder_name = QFileDialog.getExistingDirectory(
            self, "Select a folder", options=QFileDialog.ShowDirsOnly
        )
        print("Folder name:", folder_name)
        if folder_name:
            print("Selected folder:", folder_name)
        else:
            print("No folder selected")


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
