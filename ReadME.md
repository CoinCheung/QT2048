
This is a simple 2048 game written with python3 and c, the UI is created with PyQt5

### Setup

1. To setup, just run the script in the terminal
```shell
    $ cd QT2048
    $ sh ./install.sh
```
This will compile the libraries required by the program and pack all the program and its dependencies into folder ./Pack. You can move this ./Pack to other directories and run the program there. 
```shell
    $ cp -riv ./Pack/ some/other/path
    $ cd some/other/path/Pack
    $ ./main
```

2. If you do not need to pack the program, you could simply build and run the program in the current directory.
```shell
    $ cd QT2048
    $ make
    $ python3 ./main.py
```


### Operations
The rule of the game is well known.
The direction keys are 'ADWS', so in order to move the numbers 'left', 'right', 'up' and 'down', the keys 'a', 'd', 'w', 's' can be pressed.
