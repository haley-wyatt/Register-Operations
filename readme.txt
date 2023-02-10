Name: Wyatt Haley
Class: Computer Architecture
File name: readme.txt

Instructions to run code:
    The makefile is set-up to use GNU c++ compiler
    In terminal run the following commands:
        make
        ./executable Programming-Project-3.txt


Included files:
    driver.cpp
    makefile
    Programming-Project-3.txt
    readme.txt

The driver.cpp has comments for each piece of logic to follow. Below is a summary of the program operation.

The  Programming-Project-2.txt file is passed in as a command line argument. 
The file is opened and an input file stream object is created.
The data is pulled from the Programming-Project-3.txt and each word is pushed into a string queue.
The queue is iterated through, operations and operands/register-locations are identified and separated.
The operation and operands are passed into functions that perform arithmetic.
Register values are printed after every operation is performed. 
The program ends.

Below is a summary of the results:

MOV R1 #0x72df9901
R0:0x0 R1:0x72DF9901 R2:0x0 R3:0x0
R4:0x0 R5:0x0 R6:0x0 R7:0x0

MOV R2 #0x2E0B484A
R0:0x0 R1:0x72DF9901 R2:0x2E0B484A R3:0x0
R4:0x0 R5:0x0 R6:0x0 R7:0x0

ADD R3 R1 R2
R0:0x0 R1:0x72DF9901 R2:0x2E0B484A R3:0xA0EAE14B
R4:0x0 R5:0x0 R6:0x0 R7:0x0

SUB R4 R3 R2
R0:0x0 R1:0x72DF9901 R2:0x2E0B484A R3:0xA0EAE14B
R4:0x72DF9901 R5:0x0 R6:0x0 R7:0x0

MOV R0 #0xAAA5555
R0:0xAAA5555 R1:0x72DF9901 R2:0x2E0B484A R3:0xA0EAE14B
R4:0x72DF9901 R5:0x0 R6:0x0 R7:0x0

AND R0 R0 R4
R0:0x28A1101 R1:0x72DF9901 R2:0x2E0B484A R3:0xA0EAE14B
R4:0x72DF9901 R5:0x0 R6:0x0 R7:0x0

ORR R0 R2 R3
R0:0xAEEBE94B R1:0x72DF9901 R2:0x2E0B484A R3:0xA0EAE14B
R4:0x72DF9901 R5:0x0 R6:0x0 R7:0x0

XOR R5 R3 R4
R0:0xAEEBE94B R1:0x72DF9901 R2:0x2E0B484A R3:0xA0EAE14B
R4:0x72DF9901 R5:0xD235784A R6:0x0 R7:0x0

MOV R6 #0xFFFFFFFF
R0:0xAEEBE94B R1:0x72DF9901 R2:0x2E0B484A R3:0xA0EAE14B
R4:0x72DF9901 R5:0xD235784A R6:0xFFFFFFFF R7:0x0

ASR R7 R6 #2
R0:0xAEEBE94B R1:0x72DF9901 R2:0x2E0B484A R3:0xA0EAE14B
R4:0x72DF9901 R5:0xD235784A R6:0xFFFFFFFF R7:0xFFFFFFFF

LSR R7 R6 #2
R0:0xAEEBE94B R1:0x72DF9901 R2:0x2E0B484A R3:0xA0EAE14B
R4:0x72DF9901 R5:0xD235784A R6:0xFFFFFFFF R7:0x3FFFFFFF

LSL R6 R7 #1
R0:0xAEEBE94B R1:0x72DF9901 R2:0x2E0B484A R3:0xA0EAE14B
R4:0x72DF9901 R5:0xD235784A R6:0x7FFFFFFE R7:0x3FFFFFFF
