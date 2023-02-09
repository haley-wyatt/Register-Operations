/*
Name: Wyatt Haley
Class: CS 219 w/ Bashira Akter Anima
Date: 12/03/2022
Assignment: Programming Project 3
File name: driver.cpp
*/

// preprocessor directives
#include <iostream>
#include <fstream>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <queue>
#include <algorithm>

// function declarations
void solve(std::queue<std::string>& q);
int pullData(std::string file, std::queue<std::string>& q);
template<class ItemType>
ItemType mathFunction(std::string operation, ItemType operand1, ItemType operand2);
void printData(uint32_t r0, uint32_t r1,uint32_t r2,uint32_t r3,uint32_t r4,uint32_t r5,uint32_t r6,uint32_t r7);


// main function
int main(int argc, char const* argv[]){
    // variable declarations
    std::queue<std::string> q;

    // check that program run included text file
    if(argc != 2){
		std::cout << "Correct usage:" << std::endl << "./executable Programming-Project-3.txt" << std::endl;
		return 1;
	}

    // pull file name from command line argument
    std::string fileName = argv[1];
    
    //load data from file
    pullData(fileName, q);
    
    // perform program arithmetic
    solve(q);
    
    // main return statement        
    return 0;
}

// solve() iterates through the queue, calling mathFunction to perform arithmetic and printData to print output
void solve(std::queue<std::string>& q){
    std::string operation = "";
    uint32_t destinationRegister = 0;
    uint32_t operandOne = 0;
    uint32_t operandTwo = 0;
    uint32_t r0 = 0;
    uint32_t r1 = 0;
    uint32_t r2 = 0;
    uint32_t r3 = 0;
    uint32_t r4 = 0;
    uint32_t r5 = 0;
    uint32_t r6 = 0;
    uint32_t r7 = 0;

    while (!q.empty()){
        if(q.front() == "ADD" || q.front() == "SUB" || q.front() == "AND" || q.front() == "ORR" ||
            q.front() == "XOR"){

            // assign operation
            operation = q.front();
            q.pop();

            // assign destination register
            destinationRegister = std::stoul(q.front().erase(0,1), nullptr, 10);
            q.pop();
            operandOne = std::stoul(q.front().erase(0,1), nullptr, 10);
            q.pop();
            operandTwo = std::stoul(q.front().erase(0,1), nullptr, 10);
            q.pop();

            // print operation being performed
            std::cout << operation << " R" << destinationRegister << " R" << operandOne << " R" << operandTwo << std::endl;

            // assign operands the values from registers
            if( operandOne == 0){ operandOne = r0; }
            else if( operandOne == 1){ operandOne = r1; }
            else if( operandOne == 2){ operandOne = r2; }
            else if( operandOne == 3){ operandOne = r3; }
            else if( operandOne == 4){ operandOne = r4; }
            else if( operandOne == 5){ operandOne = r5; }
            else if( operandOne == 6){ operandOne = r6; }
            else if( operandOne == 7){ operandOne = r7; }
            if( operandTwo == 0){ operandTwo = r0; }
            else if( operandTwo == 1){ operandTwo = r1; }
            else if( operandTwo == 2){ operandTwo = r2; }
            else if( operandTwo == 3){ operandTwo = r3; }
            else if( operandTwo == 4){ operandTwo = r4; }
            else if( operandTwo == 5){ operandTwo = r5; }
            else if( operandTwo == 6){ operandTwo = r6; }
            else if( operandTwo == 7){ operandTwo = r7; }

            // perform operations and assign to desination register
            switch (destinationRegister){
            case 0:
                r0 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 1:
                r1 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 2:
                r2 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 3:
                r3 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 4:
                r4 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 5:
                r5 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 6:
                r6 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 7:
                r7 = mathFunction(operation, operandOne, operandTwo);
                break;
            default:
                std::cout << "Erroneous destination register value" << std::endl;
                break;
            }
        // print register values after operation
        printData(r0,r1,r2,r3,r4,r5,r6,r7);
        std::cout << std::endl;
        }
        else if (q.front() == "MOV"){
            // assign operation, destination register, and operand values
            operation = q.front();
            q.pop();
            destinationRegister = std::stoul(q.front().erase(0,1), nullptr, 10);
            q.pop();
            operandOne = std::stoul(q.front(), nullptr, 16);
            q.pop();
            
            // print operation being performed
            std::cout << operation << " R" << destinationRegister << " #0x" << std::hex << operandOne << std::endl;

            // perform operations and assign to desination register
            switch (destinationRegister){
            case 0:
                r0 = operandOne;
                break;
            case 1:
                r1 = operandOne;
                break;
            case 2:
                r2 = operandOne;
                break;
            case 3:
                r3 = operandOne;
                break;
            case 4:
                r4 = operandOne;
                break;
            case 5:
                r5 = operandOne;
                break;
            case 6:
                r6 = operandOne;
                break;
            case 7:
                r7 = operandOne;
                break;
            default:
                std::cout << "Erroneous destination register value" << std::endl;
                break;
            }
            // print register values
            printData(r0,r1,r2,r3,r4,r5,r6,r7);
            std::cout << std::endl;
        }
        
        else if(q.front() == "ASR" || q.front() == "LSR" || q.front() == "LSL"){
            // assign operation and operands
            operation = q.front();
            q.pop();
            destinationRegister = std::stoul(q.front().erase(0,1), nullptr, 10);
            q.pop();
            operandOne = std::stoul(q.front().erase(0,1), nullptr, 10);
            q.pop();
            operandTwo = std::stoul(q.front(), nullptr, 10);
            q.pop();
            
            // print operation being performed
            std::cout << operation << " R" << destinationRegister << " R" << operandOne << " #" << operandTwo << std::endl;

            // assign operands the values from registers
            if( operandOne == 0){ operandOne = r0; }
            else if( operandOne == 1){ operandOne = r1; }
            else if( operandOne == 2){ operandOne = r2; }
            else if( operandOne == 3){ operandOne = r3; }
            else if( operandOne == 4){ operandOne = r4; }
            else if( operandOne == 5){ operandOne = r5; }
            else if( operandOne == 6){ operandOne = r6; }
            else if( operandOne == 7){ operandOne = r7; }
            

            // perform operations and assign to desination register
            switch (destinationRegister){
            case 0:
                r0 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 1:
                r1 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 2:
                r2 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 3:
                r3 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 4:
                r4 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 5:
                r5 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 6:
                r6 = mathFunction(operation, operandOne, operandTwo);
                break;
            case 7:
                r7 = mathFunction(operation, operandOne, operandTwo);
                break;
            default:
                std::cout << "Erroneous destination register value" << std::endl;
                break;
            }
            // print register values
            printData(r0,r1,r2,r3,r4,r5,r6,r7);
            std::cout << std::endl;
        }
    }
}

// pullData() pulls all the data from the file and puts it into a queue
int pullData(std::string file, std::queue<std::string>& q){
    std::string s;
    std::ifstream fileIn(file);
    
    // check for successul file opening and exit if file failed to open
    if(!fileIn.is_open()){
        std::cout << "File failed to open. Did you spell it correctly?. Exiting program." << std::endl;
        return 1;
    } 

    //pull data from file and push into queue
    while(getline(fileIn, s)){
        std::istringstream ss(s);
        std::string word;
        while(ss >> word){
            if(word[0] == '0' && word[1] == 'x'){
                word.erase(0,2);
            }
            else if(word[0] == '#' && word[2] == 'x'){
                word.erase(0,3);
            }
            std::transform(word.begin(), word.end(), word.begin(), ::toupper);
            word.erase(std::remove(word.begin(), word.end(), ','), word.end());
            word.erase(std::remove(word.begin(), word.end(), '#'), word.end());
            q.push(word);
        }
    }

    // close file
    fileIn.close();
    return 0;
}

// mathFunction performs arithmetic operations on given operands with the given operation type and returns the result
template<class ItemType>
ItemType mathFunction(std::string operation, ItemType operand1, ItemType operand2){
    ItemType result = 0;

    if(operation == "ADD"){
        result = operand1 + operand2;
    }
    else if(operation == "AND"){
        result = operand1 & operand2;
    }
    else if(operation == "ASR"){
        int32_t tempOperand1 = (int32_t) operand1;
        int32_t tempOperand2 = (int32_t) operand2;
        result = tempOperand1 >> tempOperand2;
    }
    else if(operation == "LSR"){ 
        result = operand1 >> operand2;
    }
    else if(operation == "LSL"){
        result = operand1 << operand2;
    }
    else if(operation == "NOT"){
        result = ~operand1;
    }
    else if(operation == "ORR"){
        result = operand1 | operand2;
    }
    else if(operation == "SUB"){
        result = operand1 - operand2;
    }
    else if(operation == "XOR"){
        result = operand1 ^ operand2;
    }
    else{
        std::cout << "Invalid operation type." << std::endl;
    }
    return result;
}

// printData prints the values stored in the registers
void printData(uint32_t r0, uint32_t r1,uint32_t r2,uint32_t r3,uint32_t r4,uint32_t r5,uint32_t r6,uint32_t r7){
    std::cout << std::uppercase << "R0:0x" << r0 << " R1:0x" << r1 << " R2:0x" << r2 << " R3:0x" << r3 << std::endl;
    std::cout << "R4:0x" << r4 << " R5:0x" << r5 << " R6:0x" << r6 << " R7:0x" << r7 << std::endl;
}