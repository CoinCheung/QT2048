
This is a simple 2048 game written with python3 and c, the UI is created with PyQt5

1. build  

the packages that this game relies are: ctypes, numpy, cx-freeze. Before build this game, these packages are to be installed. Moreover, gcc is also required
```
    sudo python3 -m pip install numpy --upgrade
    sudo python3 -m pip install ctypes --upgrade
    sudo python3 -m pip install cx-freeze --upgrade
```

then just make in the shell
``` 
    $ make
```
and run the game:
```
    cd build/exe*
    ./main
```

2. to move the numbers left, right, up and down, the keys of a, d, w, s can be pressed
