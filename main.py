#!/usr/bin/python3
# -*- coding: utf-8 -*-


import os
import sys
from ctypes import *
import numpy as np
import ui2048
from PyQt5 import QtWidgets, QtCore
from PyQt5.QtWidgets import QMessageBox



#======================================================
# The class to implement the game
#======================================================
class Implement2048(QtWidgets.QMainWindow,ui2048.Ui_MainWindow):
    #initialization of the Class
    def __init__(self):
        super(Implement2048,self).__init__()
        self.lib = cdll.LoadLibrary(os.getcwd()+'/lib2048.so')
        self.setField()
        self.setupUi(self)
        self.initGameStatus()
        self.updateUI()



    # save the best score to file
    def storeBestScore(self):
        f = open('bestScore.ini','w')
        f.write(str(self.BestScore))
        f.close()
        print("best score saved")



    # create a 2D array and pass it to C program
    def setField(self):
        self.fields = np.zeros((4,4), dtype = np.int32)
        self.fields_p = c_void_p(self.fields.ctypes.data)
        self.lib.setField(self.fields_p,4,4)



    #initialization of the Status of the game
    def initGameStatus(self):
        # load the best Score from the storage file
        def loadScore():
            if os.path.exists('bestScore.ini'):
                f = open('bestScore.ini','r')
                self.lib.setBestScore(int(f.read()))
                f.close()

        self.lib.initGame()
        loadScore()
        self.BestScore = self.lib.getBestScore()



    # update the UI
    def updateUI(self):
        for i in range(4):
            for j in range(4):
                num = self.fields[i][j]
                if num == 0:
                    cmd = ''.join(['self.key',str(i),str(j),'.clear()'])
                    eval(cmd)
                else:
                    cmd = ''.join(['self.key',str(i),str(j),'.setText(str(num))'])
                    eval(cmd)
                    self.label_2.setText('Score  '+str(self.lib.getCurrentScore()))

                    self.label_3.setText('Best  '+str(self.lib.getBestScore()))



    # response method when any key is pressed
    def keyPressEvent(self,event):
        if event.key() == QtCore.Qt.Key_A:
            self.lib.keyLeft()
        elif event.key() == QtCore.Qt.Key_S:
            self.lib.keyDown()
        elif event.key() == QtCore.Qt.Key_D:
            self.lib.keyRight()
        elif event.key() == QtCore.Qt.Key_W:
            self.lib.keyUp()

        self.updateUI()

        # update the best score
        if self.BestScore < self.lib.getBestScore():
            self.BestScore = self.lib.getBestScore()

        # judge if the player wins or loses
        if self.lib.isWin() == 1:
            self.storeBestScore() # store the best score
            buttonReply = QMessageBox.question(self, 'You Win !!', "Congratulations!!! You win, want another game or not?", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
            if buttonReply == QMessageBox.Yes:
                print("Start a new Game!!")
            else:
                print("exit!!")
                sys.exit()


        if self.lib.isLost() == 1: # if the player loses
            self.storeBestScore()
            buttonReply = QMessageBox.question(self,'Game Over !!',' Such a big pity!! You have lost the game, would you like a new game ?',QMessageBox.Yes|QMessageBox.No,QMessageBox.No)
            if buttonReply == QMessageBox.Yes:
                self.NewGame()
            else:
                print("exit!!")
                sys.exit()



    # reponse method when the button 'NewGame' is clicked
    def NewGame(self):
        print("Start a new Game!!")
        self.initGameStatus()
        self.updateUI()


#===============================================================
# entrance of the program
#===============================================================
if __name__ == '__main__':
    import sys
    app = QtWidgets.QApplication(sys.argv)
    obj = Implement2048()
    obj.show()
  #  # debug
  #    import time
  #    time.sleep(40)

  #  #
    sys.exit(app.exec_())
