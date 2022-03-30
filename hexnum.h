/**
    CS219 This is the header file for the HexNum class, which represents Hexadecimal Numbers.
    @file hexnum.cpp
    @author Alvin Leung
    @version 1.0 1/21/2022
*/
#ifndef HEXNUM_H
#define HEXNUM_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//This is the HexNum class, which represents Hexadecimal Numbers

class HexNum{
public:
	HexNum() = default;
	HexNum(string nhexVal);
	HexNum(uint32_t i);
	HexNum(uint32_t i, int length);

private:
	string hexVal;
	uint32_t intVal;
	int len;
	string hexName;

public: 
	int getLength() const;
	string getHex() const;
	uint32_t getInt() const;
	void setHex(string h);
	void setInt(uint32_t i); 
	string getHexName() const;
	HexNum operator+ (const HexNum& rhs) const;

};

#endif
