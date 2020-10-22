from PyQt5.QtWidgets import QMainWindow, QApplication, QPushButton
import sys
from PyQt5 import QtGui
from PyQt5.QtCore import QRect
from PyQt5 import QtCore



class Window(QMainWindow):
    def __init__(self):
        super().__init__()

        self.title = "Pyqt window"
        self.top = 100
        self.left = 100
        self.width = 400
        self.height = 300
        self.InitWindow()




    def InitWindow(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        self.UiComp()

        self.show()

    def UiComp(self):
        
        button = QPushButton("click",self)
        #button.move(50,40)
        button.setGeometry(QRect(20,30,40,60))
        button.setIcon(QtGui.QIcon("icon4.png"))
        button.setIconSize(QtCore.QSize(40,40))
        button.setToolTip("tooooooooo")
        button.clicked.connect(self.ck)



    def ck(self):
        
        print("hello")
        button.setIcon(QtGui.QIcon("icon6.png"))
        #sys.exit()

App=QApplication(sys.argv)
window = Window()
sys.exit(App.exec())