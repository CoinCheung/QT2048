CC = gcc
CFLAGS = -fPIC -c -g
LFLAGS_SO = -shared 
BDIR = ./build
LIBDIR = $(BDIR)/lib


# build the shared lib
PRO: prepare $(LIBDIR)/lib2048.so

prepare:
	mkdir -p $(BDIR) $(LIBDIR)

$(LIBDIR)/lib2048.so: $(BDIR)/lib2048.o
	$(CC) $(LFLAGS_SO) -o $@ $<

$(BDIR)/lib2048.o: so2048.c
	$(CC) $(CFLAGS) $< -o $@

# pack the program
exe: PRO setup.py
	python3 setup.py build

clean:
	rm -rf ./build/ ./Pack bestScore.ini

