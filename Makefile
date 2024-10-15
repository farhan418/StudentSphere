# Project: StudentSphere
# Makefile created by Dev-C++ 5.11

# CPP      = g++.exe -D__DEBUG__
CPP      = g++ -D__DEBUG__
# CC       = gcc.exe -D__DEBUG__
CC       = gcc -D__DEBUG__
# WINDRES  = windres.exe
OBJ      = src/main.o src/utility/Utility.o src/models/Student.o tests/testUtilityDate.o tests/testClassStudent.o src/models/DoublyLinkedList.o tests/testDoublyLinkedList.o
LINKOBJ  = src/main.o src/utility/Utility.o src/models/Student.o tests/testUtilityDate.o tests/testClassStudent.o src/models/DoublyLinkedList.o tests/testDoublyLinkedList.o
LIBS     = -L"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib" -L"lib" -g3
INCS     = -I"include"
CXXINCS  = -I"include"
# BIN      = StudentSphere.exe
BIN      = StudentSphere
CXXFLAGS = $(CXXINCS) -Og -std=c++11 -Wall -pedantic -g3
CFLAGS   = $(INCS) -Og -std=c++11 -Wall -pedantic -g3
# RM       = rm.exe -f
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

src/main.o: src/main.cpp
	$(CPP) -c src/main.cpp -o src/main.o $(CXXFLAGS)

src/utility/Utility.o: src/utility/Utility.cpp
	$(CPP) -c src/utility/Utility.cpp -o src/utility/Utility.o $(CXXFLAGS)

src/models/Student.o: src/models/Student.cpp
	$(CPP) -c src/models/Student.cpp -o src/models/Student.o $(CXXFLAGS)

tests/testUtilityDate.o: tests/testUtilityDate.cpp
	$(CPP) -c tests/testUtilityDate.cpp -o tests/testUtilityDate.o $(CXXFLAGS)

tests/testClassStudent.o: tests/testClassStudent.cpp
	$(CPP) -c tests/testClassStudent.cpp -o tests/testClassStudent.o $(CXXFLAGS)

src/models/DoublyLinkedList.o: src/models/DoublyLinkedList.cpp
	$(CPP) -c src/models/DoublyLinkedList.cpp -o src/models/DoublyLinkedList.o $(CXXFLAGS)

tests/testDoublyLinkedList.o: tests/testDoublyLinkedList.cpp
	$(CPP) -c tests/testDoublyLinkedList.cpp -o tests/testDoublyLinkedList.o $(CXXFLAGS)