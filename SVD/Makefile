INC=-I/usr/local/include # the directory that contains opencv header files
LIB=-L/usr/local/lib	 # the directory that contains opencv lib.so files
libs=-lopencv_core -lopencv_imgproc -lopencv_highgui

all:main.cpp
	g++ main.cpp -o svd -O2 -llapack -lblas ${INC} ${LIB} ${libs}
