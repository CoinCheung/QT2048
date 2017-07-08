#!/usr/local/bin/python3
# -*- coding: utf-8 -*-
# filename: setup.py


import sys
from cx_Freeze import setup,Executable


build_options = {
        'packages':['os','sys','numpy','ctypes','PyQt5'],
        'includes':['ui2048'],
        'include_files':['./build/lib/lib2048.so']
        }

base = 'Win32GUI' if sys.platform == 'win32' else None


setup(
    name = 'QT2048',
    version = '0.0.1',
    description = 'a 2048 game',
    author = 'Coin',
    options = {'build_exe':build_options},
    executables = [Executable('main.py',base = base)]

)
