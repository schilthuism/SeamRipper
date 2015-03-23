# gpl license infos
#
# what should we put here?

import sys
#from PyQt4 import QtGui
#from PyQt4 import QtCore

from PyQt4.QtGui import *
from PyQt4.QtCore import *

class ScrollWindow(QWidget):
    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        self.scene = QGraphicsScene()
        self.view = QGraphicsView(self.scene)
        layout = QVBoxLayout()
        layout.addWidget(self.view)
        self.setLayout(layout)
        self.pixmap_item = QPainter()
        #self.pixmap_item.mousePressEvent = self.pixelSelect
        #self.click_positions = []
        self.pixmap_item.drawLine(2, 2, 10, 10)

    def pixelSelect(self, event):
        self.click_positions.append(event.pos())
        if len(self.click_positions) < 4:
            return
        pen = QPen(QtCore.Qt.red)
        self.scene.addPolygon(QPolygonF(self.click_positions), pen)
        for point in self.click_positions:
            self.scene.addEllipse(point.x(), point.y(), 2, 2, pen)
        self.click_positions = []

class MyMainWindow(QMainWindow):

    def __init__(self, parent=None):

        super(MyMainWindow, self).__init__(parent)
        self.form_widget = FormWidget(self) 
        self.setCentralWidget(self.form_widget) 

class FormWidget(QWidget):

    def __init__(self, parent):        
        super(FormWidget, self).__init__(parent)
        self.layout = QVBoxLayout(self)

        self.scrollwindow1 = QPainter()
        self.scrollwindow1.drawLine(2, 2, 10, 10)
        self.layout.addWidget(self.scrollwindow1)

        self.scrollwindow2 = ScrollWindow()
        self.layout.addWidget(self.scrollwindow2)

        self.scrollbar = QScrollBar(1)
        self.layout.addWidget(self.scrollbar)
        self.setLayout(self.layout)


#class Example(QWidget):
#    
#    def __init__(self):
#        super(Example, self).__init__()
#        
#        self.initUI()
#        
#    def initUI(self):      
#
#        self.text = u'\u041b\u0435\u0432 \u041d\u0438\u043a\u043e\u043b\u0430\
#\u0435\u0432\u0438\u0447 \u0422\u043e\u043b\u0441\u0442\u043e\u0439: \n\
#\u0410\u043d\u043d\u0430 \u041a\u0430\u0440\u0435\u043d\u0438\u043d\u0430'
#
#        self.setGeometry(300, 300, 280, 170)
#        self.setWindowTitle('Draw text')
#        self.show()
#
#    def paintEvent(self, event):
#
#        qp = QPainter()
#        qp.begin(self)
#        self.drawText(event, qp)
#        qp.end()
#        
#    def drawText(self, event, qp):
#      
#        qp.setPen(QColor(168, 34, 3))
#        qp.setFont(QFont('Decorative', 10))
#        qp.drawText(event.rect(), Qt.AlignCenter, self.text) 


app = QApplication([])
foo = MyMainWindow()
#foo = Example()
foo.show()
sys.exit(app.exec_())
