from PySide6.QtGui import QColor, QPalette
from PySide6.QtWidgets import QWidget


class Color(QWidget):
    def __init__(self, color: str):
        super().__init__()
        self.setAutoFillBackground(True)

        palette = QPalette()
        palette.setColor(QPalette.Window, QColor(color))
        self.setPalette(palette)
