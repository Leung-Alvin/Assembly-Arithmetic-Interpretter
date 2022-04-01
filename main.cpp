/**
    CS219 This is the driver or main file that runs the functions and implementations necessary to read the program text and write the
	appropriate output onto the linux terminal.
    @file main.cpp
    @author Alvin Leung
    @version 1.0 1/21/2022
*/
#include <cctype>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "operator.h"
#include "hexnum.h"

using namespace std;

void printOperator(string operation, int reg1, int reg2, int reg3, string imm, HexNum registers[]){
	cout << "----------" << endl;
	cout << "Operation: " << operation << endl;
	if(imm.length() > 0){
		cout << "Immediate Operand: " << imm << endl;
	}
	if(reg1 != -1){
		cout << "Operand 1: r" << reg1 << endl;
	}
	if(reg2 != -1){
		cout << "Operand 2: r" << reg2 << endl;
	}
	if(reg3 != -1){
		cout << "Destination: r" << reg3 << endl;
	}
	if(reg1 != -1){
		cout << "r" << reg1 << " " << registers[reg1].getHexName() << endl;
	}
	if(reg2 != -1){
		cout << "r" << reg2 << " " << registers[reg2].getHexName() << endl;
	}
	if(reg3 != -1){
		cout << "r" << reg3 << " " << registers[reg3].getHexName() << endl;
	}
	cout << "----------" << endl;
	
}

void printRegisters(HexNum registers[],int len){
	for(int i = 0; i < len; i++){
		cout << "r"<<i<<" "<< registers[i].getHexName() << endl;
	}
}

int convertStringToInt(string s){
	string ret;
	for(int i = 0; i < s.length(); i++){
		if(isdigit(s.at(i))){
			 ret+=s.at(i);
		}
	}
	return stoi(ret);
}

int isAnOperator(string s)
{
	//an "ADD" assembly command returns a code of 1. More codes for different assembly operators will be added.
	if(s == "ADD") return 1;
	if(s == "AND") return 2;
	if(s == "ASR") return 3;
	if(s == "LSR") return 4;
	if(s == "LSL") return 5;
	if(s == "NOT") return 6;
	if(s == "ORR") return 7;
	if(s == "SUB") return 8;
	if(s == "XOR") return 9;
	if(s == "MOV") return 10;
	return 0;
}



int main(){
	int regLength = 8;
	HexNum registers[regLength];
	for(int i = 0; i < regLength; i++){
		HexNum value = HexNum("0x0");
		registers[i] = value;
	}
	ifstream file;
	file.open("test.txt");
	//file.open("Programming-Project-1.txt");
	//8, 7,9
	string word;
	while(file >> word){
		string toUpper;
		if(word.length() > 2 && word.at(0) != '0' && word.at(1) != 'x'){
			for(int i = 0; i < word.length(); i++){
				toUpper+=toupper(word.at(i));
			}
		}
//printOperator(string operation, int reg1, int reg2, int reg3, int imm, HexNum registers[])
		int code = isAnOperator(toUpper);
		if(code == 1){
			file >> word;
			int rd = convertStringToInt(word);			
			file >> word;
			int rn = convertStringToInt(word);
			file >> word;
			int rm = convertStringToInt(word);
			
			HexNum h1 = registers[rn];
			HexNum h2 = registers[rm];
			registers[rd] = HexNum(h1.getInt() + h2.getInt(), h1.getLength());
			printOperator(toUpper, rn, rm, rd, "", registers);

			
		}
		if(code == 2){
			file >> word;
			int rd = convertStringToInt(word);			
			file >> word;
			int rn = convertStringToInt(word);
			file >> word;
			int rm = convertStringToInt(word);
			
			HexNum h1 = registers[rn];
			HexNum h2 = registers[rm];
			registers[rd] = HexNum(h1.getInt() & h2.getInt(), h1.getLength());
			printOperator(toUpper, rn, rm, rd, "", registers);
		}
		if(code == 3){
			file >> word;
			int rd = convertStringToInt(word);
			file>>word;
			int rn = convertStringToInt(word);
			HexNum h1 = registers[rn];
			registers[rd] = HexNum(h1.getInt() >> 1, h1.getLength());
			printOperator(toUpper, rn, -1, rd, "", registers); 
		}
		if(code == 4){
			file >> word;
			int rd = convertStringToInt(word);
			file>>word;
			int rn = convertStringToInt(word);
			HexNum h1 = registers[rn];
			registers[rd] = HexNum(h1.getInt() >> 1, h1.getLength());
			printOperator(toUpper, rn, -1, rd, "", registers); 
		}
		if(code == 5){
			file >> word;
			int rd = convertStringToInt(word);
			file>>word;
			int rn = convertStringToInt(word);
			HexNum h1 = registers[rn];
			registers[rd] = HexNum(h1.getInt() << 1, h1.getLength()); 
			printOperator(toUpper, rn, -1, rd, "", registers);
		}
		if(code == 6){
			file >> word;
			HexNum h1 = HexNum(word);
			file>>word;
			HexNum NOT = HexNum(~h1.getInt(), h1.getLength());
			cout << "----" << endl;
			cout << h1.getHexName() << " NOT " << " = " << NOT.getHexName() << endl; 			
		}
		if(code == 7){
			file >> word;
			int rd = convertStringToInt(word);			
			file >> word;
			int rn = convertStringToInt(word);
			file >> word;
			int rm = convertStringToInt(word);
			
			HexNum h1 = registers[rn];
			HexNum h2 = registers[rm];
			registers[rd] = HexNum(h1.getInt() | h2.getInt(), h1.getLength());
			printOperator(toUpper, rn, rm, rd, "", registers);
		}
		if(code == 8){
			file >> word;
			int rd = convertStringToInt(word);			
			file >> word;
			int rn = convertStringToInt(word);
			file >> word;
			int rm = convertStringToInt(word);
			
			HexNum h1 = registers[rn];
			HexNum h2 = registers[rm];
			registers[rd] = HexNum(h1.getInt() - h2.getInt(), h1.getLength());
			printOperator(toUpper, rn, rm, rd, "", registers);
		}
		if(code == 9){
			file >> word;
			int rd = convertStringToInt(word);			
			file >> word;
			int rn = convertStringToInt(word);
			file >> word;
			int rm = convertStringToInt(word);
			
			HexNum h1 = registers[rn];
			HexNum h2 = registers[rm];
			registers[rd] = HexNum(h1.getInt() ^ h2.getInt(), h1.getLength());
			printOperator(toUpper, rn, rm, rd, "", registers);
		}

		if(code == 10){
			file >> word;
			int rd = convertStringToInt(word);
			file >> word;
			string imm;
			for(int i = 1; i < word.length(); i++){
				imm+=word.at(i);
			}
			registers[rd] = HexNum(imm);
			printOperator(toUpper, -1, -1, rd, word, registers);
		}


			
	}
	cout << "---------" << endl;
	cout << "Register State End: " << endl;
	printRegisters(registers,regLength);
	cout << "---" << endl;
	return 0;



}



