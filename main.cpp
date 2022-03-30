/**
    CS219 This is the driver or main file that runs the functions and implementations necessary to read the program text and write the
	appropriate output onto the linux terminal.
    @file main.cpp
    @author Alvin Leung
    @version 1.0 1/21/2022
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "operator.h"
#include "hexnum.h"

using namespace std;

/**
    Takes in a string representing an assembly command and determines what operator it is. The operator type is returned as an integer
	code.
    @param s The assembly command to be read and deciphered
    @return an int that is code for the assembly command.
*/

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
	return 0;
}


int main(){
	//Uses an ifstream to read the file and creates a string word to extract words from the text document
	ifstream file;
	file.open("Programming-Project-1.txt");
	string word;
	//Reads into the file
	while(file >> word){
		//When an operator keyword is found inside the text file, the ifstream reads the next two word
		if(isAnOperator(word) == 1){
			//The read words are turned into Hex Number Objects with their hex value as parameters
			file >> word;
			HexNum h1 = HexNum(word);
			file >> word;
			HexNum h2 = HexNum(word);
			//The sum of the two Hex Numbers are found by adding the integer values of the respective Hex Numbers
			HexNum sum = h1 + h2;
			//A HexNumber representing the sum is created
			//A separator is printed out to separate answers
			cout<< "----" << endl;
			//The two Hexadecimal numbers are printed out in the equation print with the Hexadecimal Number representing
			//the sum is printed last
			cout << h1.getHexName() << " ADD " << h2.getHexName() << " = " << sum.getHexName() << endl;
			
		}
		if(isAnOperator(word) == 2){
			//The read words are turned into Hex Number Objects with their hex value as parameters
			file >> word;
			HexNum h1 = HexNum(word);
			file >> word;
			HexNum h2 = HexNum(word);
			HexNum AND = HexNum(h1.getInt() & h2.getInt(), h1.getLength());
			cout << "----" << endl;	
			cout << h1.getHexName() << " AND " << h2.getHexName() << " = " << AND.getHexName() << endl;
		}
		if(isAnOperator(word) == 3){
			file >> word;
			HexNum h1 = HexNum(word);
			file>>word;
			HexNum ASR = HexNum(h1.getInt()>>1, h1.getLength());
			cout << "----" << endl;
			cout << h1.getHexName() << " ASR 1 " << " = " << ASR.getHexName() << endl; 
		}
		if(isAnOperator(word) == 4){
			file >> word;
			HexNum h1 = HexNum(word);
			file>>word;
			HexNum LSR = HexNum(h1.getInt()>>1, h1.getLength());
			cout << "----" << endl;
			cout << h1.getHexName() << " LSR 1 " << " = " << LSR.getHexName() << endl; 
		}
		if(isAnOperator(word) == 5){
			file >> word;
			HexNum h1 = HexNum(word);
			file>>word;
			HexNum LSL = HexNum(h1.getInt()<<1, h1.getLength());
			cout << "----" << endl;
			cout << h1.getHexName() << " LSL 1 " << " = " << LSL.getHexName() << endl; 
		}
		if(isAnOperator(word) == 6){
			file >> word;
			HexNum h1 = HexNum(word);
			file>>word;
			HexNum NOT = HexNum(~h1.getInt(), h1.getLength());
			cout << "----" << endl;
			cout << h1.getHexName() << " NOT " << " = " << NOT.getHexName() << endl; 			
		}
		if(isAnOperator(word) == 7){
			//The read words are turned into Hex Number Objects with their hex value as parameters
			file >> word;
			HexNum h1 = HexNum(word);
			file >> word;
			HexNum h2 = HexNum(word);
			HexNum ORR = HexNum(h1.getInt() | h2.getInt(), h1.getLength());
			cout << "----" << endl;	
			cout << h1.getHexName() << " ORR " << h2.getHexName() << " = " << ORR.getHexName() << endl;
		}
		if(isAnOperator(word) == 8){
			file >> word;
			HexNum h1 = HexNum(word);
			file >> word;
			HexNum h2 = HexNum(word);
			HexNum SUB = HexNum(h1.getInt() - h2.getInt(), h1.getLength());
			cout << "----" << endl;
			cout << h1.getHexName() << " SUB " << h2.getHexName() << " = " << SUB.getHexName() << endl;
		}
		if(isAnOperator(word) == 9){
			file >> word;
			HexNum h1 = HexNum(word);
			file >> word;
			HexNum h2 = HexNum(word);
			HexNum XOR = HexNum(h1.getInt() ^ h2.getInt(), h1.getLength());
			cout << "----" << endl;
			cout << h1.getHexName() << " XOR " << h2.getHexName() << " = " << XOR.getHexName() << endl;
		}


			
	}
	return 0;

}



