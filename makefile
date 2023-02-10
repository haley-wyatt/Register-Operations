#Name: Wyatt Haley
#Class: Computer Architecture
#File name: makefile

OUTPUT = executable
SOURCE = driver.cpp
all: $(OUTPUT)


$(OUTPUT): $(OUTPUT).o
	g++ -o $@ $@.o -std=c++11
	


$(OUTPUT).o: $(SOURCE)
	g++ -c $< -std=c++11 -o $@

clean:
	rm *.o executable
