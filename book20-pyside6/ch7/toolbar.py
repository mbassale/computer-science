import sys, os

from PySide6.QtCore import Qt, QSize
from PySide6.QtGui import QAction, QIcon
from PySide6.QtWidgets import QApplication, QMainWindow, QToolBar, QStatusBar, QLabel

basedir = os.path.dirname(os.path.abspath(__file__))
iconsdir = os.path.join(basedir, "../icons")


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Toolbar Example")

        label = QLabel("Hello!")
        label.setAlignment(Qt.AlignCenter)
        self.setCentralWidget(label)

        # Create a toolbar
        toolbar = QToolBar("My main toolbar")
        toolbar.setIconSize(QSize(16, 16))
        toolbar.toggleViewAction().setEnabled(False)
        toolbar.setToolButtonStyle(Qt.ToolButtonStyle.ToolButtonTextUnderIcon)
        self.addToolBar(toolbar)

        # Add actions to the toolbar
        button_action = QAction("Action 1", self)
        button_action.setStatusTip("This is Action 1")
        button_action.triggered.connect(self.on_button_clicked)
        toolbar.addAction(button_action)

        # Add a separator
        toolbar.addSeparator()

        # Add another action
        button_action2 = QAction(
            QIcon(os.path.join(iconsdir, "bug.png")),
            "Action 2",
            self,
        )
        button_action2.setStatusTip("This is Action 2")
        button_action2.triggered.connect(self.on_button_clicked)
        button_action2.setCheckable(True)
        toolbar.addAction(button_action2)

        self.setStatusBar(QStatusBar(self))

    def on_button_clicked(self):
        print("Button clicked!")


app = QApplication(sys.argv)
window = MainWindow()
window.show()
app.exec()
