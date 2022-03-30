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
	printRegisters(registers,regLength);
	cout << "---" << endl;
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
			/*cout << registers[rn].getHexName() << " ADD " << h2.getHexName() << " = " << registers[rd].getHexName() << endl;

*/
			
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
		}
		if(code == 3){
			file >> word;
			int rd = convertStringToInt(word);
			file>>word;
			int rn = convertStringToInt(word);
			HexNum h1 = registers[rn];
			registers[rd] = HexNum(h1.getInt() >> 1, h1.getLength()); 
		}
		if(code == 4){
			file >> word;
			int rd = convertStringToInt(word);
			file>>word;
			int rn = convertStringToInt(word);
			HexNum h1 = registers[rn];
			registers[rd] = HexNum(h1.getInt() >> 1, h1.getLength()); 
		}
		if(code == 5){
			file >> word;
			int rd = convertStringToInt(word);
			file>>word;
			int rn = convertStringToInt(word);
			HexNum h1 = registers[rn];
			registers[rd] = HexNum(h1.getInt() << 1, h1.getLength()); 
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
		}

		if(code == 10){
			file >> word;
			int registerNumber = convertStringToInt(word);
			file >> word;
			string imm;
			for(int i = 1; i < word.length(); i++){
				imm+=word.at(i);
			}
			registers[registerNumber] = HexNum(imm);
		}


			
	}
	printRegisters(registers,regLength);
	cout << "---" << endl;
	return 0;



}



