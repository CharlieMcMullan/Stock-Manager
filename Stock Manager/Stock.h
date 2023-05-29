#pragma once
using namespace std;
#include <iostream> // Input & output functionality
#include <string> //String maniplulation
#include <fstream> //file I/O functionality
#include <iomanip>  // Input/output manipulation
#include <windows.h> //Windows header, used for coloured text


class Stock
{
private:
	int S_ID_Num;
	string S_Name;
	int S_Quantity;
	double S_Price;

public:
	Stock(void);
	Stock(int ID, string Name, double Price, int Quantity);

	bool Password(string Attempt);
	void Display(void);
	void DisplayPrice(void);
	void SetPrice(double price);
	void SetQuantity(int Quantity);
	void DisplayQuantity();
	bool HasName(string Name);
	bool HasCode(int searchCode);

};


