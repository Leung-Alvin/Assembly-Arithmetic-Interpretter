/**
    CS219 This is the implemenation of the HexNum class, which represents hexadecimal numbers. The class creates hexadecimal number objects
	that can read out its decimal equivalent, hexadecimal value, hexadecimal name, and hexadecimal number length. There are functions that 
	convert hexadecimal values to decimal numbers.
    @file hexnum.cpp
    @author Alvin Leung
    @version 1.0 1/21/2022
*/
#include "hexnum.h"
#include <math.h>
/**
    Converts an integer value into a hexadecimal digit
    @param ret the integer to be converted
    @return a string representing a hexadecimal digit
*/
string convertIntDig(int ret){
	if(ret == 10) return "A";
	if(ret == 11) return "B";
	if(ret == 12) return "C";
	if(ret == 13) return "D";
	if(ret == 14) return "E";
	if(ret == 15) return "F";
	return std::to_string(ret);
}

/**
    Converts a hexadecimal digit into a decimal value
    @param s A character representing a hexadecimal digit.
    @return a 32 bit unsigned integer representing the converted hexadecimal digit.
*/

uint32_t convertHexDig(char s){
	if(s == '0'){
	 return 0;
	}
	if(s == '1'){
	 return 1;
	}
	if(s == '2'){
	 return 2;
	}
	if(s == '3'){
	 return 3;
	}
	if(s == '4'){
	 return 4;
	}
	if(s == '5'){
	 return 5;
	}
	if(s == '6'){
	 return 6;
	}
	if(s == '7'){
	 return 7;
	}
	if(s == '8'){
	 return 8;
	}
	if(s == '9'){
	 return 9;
	}
	if(s == 'A'){
	 return 10;
	}
	if(s == 'B'){
	 return 11;
	}
	if(s == 'C'){
	 return 12;
	}
	if(s == 'D'){
	 return 13;
	}
	if(s == 'E'){
	 return 14;
	}
	 return 15;

}
/**
    Converts an entire hexadecimal number into an integer number. This utilizes the implementation of convertHexDig(char s)
	as a helper function
    @param s the hexadecimal number to be converted into an integer
	@param len the integer representing the length of the hexadecimal number, the number of hexadecimal digits in string s
    @return a 32 bit unsigned integer representing the decimal number converted from the parameter hexadecimal number
*/
uint32_t convertHex(string s, int len){
	int power = len-1;
	uint32_t sum = 0;
	for(int i = 0; i < len; i++){
		int digit = convertHexDig(s.at(i));
		/*if(sum+pow(16,power) * digit > 4294967295){
			uint64_t overflow = sum+pow(16,power) * digit;
			sum = overflow - 4294967295;
		}*/
		sum += pow(16,power) * digit;
		power--;
	}
	return sum;
}

//overflow = 

/**
    Converts a decimal number into a hexadecimal number. This method uses the implementation of convertIntDig(int ret)
	as a helper function.
    @param i the decimal number to be converted into hexadecimal, len is the length of the hexadecimal number to be created
    @return a string representing the hexadecimal number converted from the parameter decimal number.
*/

string convertInt(uint32_t i, int len){
	string ret = "";
	if(i == 0){
		ret+="0";
	}
	uint32_t copy = i;
	while (copy > 0){
		int remainder = copy%16;
		ret += convertIntDig(remainder);
		copy/=16;
	}
	string ret2 = "";
	for (int i = ret.length()-1; i >= 0; i--){
		ret2+=ret.at(i);
	}
	while(len > ret2.length()){
		ret2 = "0" + ret2;
	} 
	return ret2;
}	
//Constructor for a Hex Number if given a hexadecimal number in string form (ex: "0x132").
HexNum::HexNum(string nhexVal){
	hexName = nhexVal;
	size_t loc = nhexVal.find("0x");
	hexVal = nhexVal.substr(loc+2);
	len = hexVal.length();
	intVal = convertHex(hexVal,len);

}

HexNum::HexNum(uint32_t i, int length){
	intVal = i;
	hexVal = convertInt(i,length);
	hexName = "0x" + hexVal;
	len = hexVal.length();
}

//Constructor for a Hex Number if given a decimal number in integer form (ex: 1322).
HexNum::HexNum(uint32_t i){
	intVal = i;
	hexVal = convertInt(i, len);
	hexName = "0x" + hexVal;
	len = hexVal.length();
}
/**
    Returns the hexadecimal value of this Hex Number
    @return a string representing the hexadecimal value of this Hex Number
*/
string HexNum::getHex() const{
	return hexVal;
}
/**
    Returns the hexadecimal number of this Hex Number
    @return a string representing the hexadecimal nnumber of this Hex Number. Hexadecimal number and hexadecimal value are different
	in that the hexadecimal number has a 0x as a header. (1231 vs 0x1231)
*/
string HexNum::getHexName() const{
	return hexName;
}
/**
    Returns the decimal number of this Hex Number
    @return an intger representing the decimal number of this Hex Number.
*/
uint32_t HexNum::getInt() const{
	return intVal;
}


int HexNum::getLength() const{
	return len;
}

/**
    Assigns a new hexadecimal value for this Hex Number (Work in Progress and not needed for this assignment)
    @param h a string representing the new hexadecimal value for this Hex Number
*/

void HexNum::setHex(string h){
	hexVal = h;
}

/**
    Assigns a new decimal number for this Hex Number (Work in Progress and not needed for this assignment)
    @param i a 32 bit unsigned integer representing the new decimal number to be assigned.
*/

void HexNum::setInt(uint32_t i){
	intVal = i;
}

HexNum HexNum::operator+ (const HexNum& rhs) const{
	int outputLength = len;
	if(len < rhs.len){
		outputLength = rhs.len;
	}
	return HexNum(intVal + rhs.intVal, outputLength);
}



