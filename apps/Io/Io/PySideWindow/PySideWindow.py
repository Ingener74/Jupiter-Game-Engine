# -*- coding: utf-8 -*-
from PySide.QtCore import (Qt, Signal)
from PySide.QtGui import (QIcon, QPixmap, QApplication, QMessageBox)
from PySide.QtOpenGL import (QGLWidget)

try:
    from OpenGL.GL import *
    from OpenGL.GLU import *
    from OpenGL.GLUT import *
except ImportError as e:
    app = QApplication(sys.argv)
    QMessageBox.critical(None, PLAYER_TITLE, u'Установи PyOpenGL', QMessageBox.Ok | QMessageBox.Default,
                         QMessageBox.NoButton)
    sys.exit(1)

from Io import PLAYER_TITLE, Io, j, WIDTH, HEIGHT, FPS


class OpenGLWidget(QGLWidget):

    on_close = Signal(object)

    def __init__(self, parent=None):
        QGLWidget.__init__(self, parent, None)
        self.setWindowIcon(QIcon(QPixmap(':/main.png')))

        self.fallingBox = None

    def initializeGL(self):
        self.setWindowTitle(PLAYER_TITLE)
        self.resize(WIDTH, HEIGHT)

        print 'Vendor   ', str(glGetString(GL_VENDOR))
        print 'Renderer ', str(glGetString(GL_RENDERER))
        print 'OpenGL   ', str(glGetString(GL_VERSION))
        print 'GLSL     ', str(glGetString(GL_SHADING_LANGUAGE_VERSION))

        glEnable(GL_TEXTURE_2D)
        glEnable(GL_DEPTH_TEST)
        glEnable(GL_BLEND)
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)

        try:
            j.startJupiter()
            self.fallingBox = Io(self)

            self.startTimer(1000.0 / FPS)

        except RuntimeError, e:
            raise SystemExit(u'Ошибка старта ' + str(e).decode('utf-8'))

    def paintGL(self):
        glClearColor(0.1, 0.3, 0.1, 1.0)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)

        try:
            if self.fallingBox and self.fallingBox.isReady():
                self.fallingBox.game.draw()

        except RuntimeError, e:
            raise SystemExit(str(e))

    def resizeGL(self, w, h):
        glViewport(0, 0, w, h)

    def timerEvent(self, event):
        self.update()

    def keyPressEvent(self, event):
        if event.key() == Qt.Key_F5:
            self.fallingBox = Io(self)
        if event.key() == Qt.Key_Escape:
            raise SystemExit
        self.fallingBox.game.keyboard(event.nativeScanCode())

    def closeEvent(self, e):
        j.endJupiter()
        self.on_close.emit(None)
