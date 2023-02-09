#Name: Wyatt Haley
#Class: CS 219 w/ Bashira Akter Anima
#Date: 12/03/2022
#File name: makefile

# modify this makefile based on your requirement

OUTPUT = executable
#INCLIB=header.h #write your header file if you have any
SOURCE = driver.cpp #write your .cpp file name
all: $(OUTPUT)


$(OUTPUT): $(OUTPUT).o
	g++ -o $@ $@.o -std=c++11
	


$(OUTPUT).o: $(SOURCE) #$(INCLIB)
	g++ -c $< -std=c++11 -o $@

clean:
	rm *.o executable