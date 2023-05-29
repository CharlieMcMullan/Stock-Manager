#include "Stock.h" //connects Stock header file


bool Stock::Password(string Attempt)//
{//password protection 
	string Pass;

	Pass = "Pass1$";//sets "Pass" to password

	if (Pass == Attempt)//compares password to users password attempt
		return true;//if correct returns true

	return false;// if incorrect returns false


}//end of password 
Stock::Stock(void)
	: S_ID_Num(0)
	, S_Name("")
	, S_Quantity(0)
	, S_Price(0)
{
}//end of stock 

Stock::Stock(int ID, string Name, double Price, int Quantity)
	: S_ID_Num(ID)
	, S_Name(Name)
	, S_Quantity(Quantity)
	, S_Price(Price)
{
}//end of stock 

void Stock::Display(void)//Displays items in listing
{
	//dislays items in a table format
	cout << "\t|" << setw(10) << S_ID_Num;
	cout << "\t|" << setw(10) << S_Name;
	cout << "\t|" << setw(10) << S_Quantity;
	cout << "\t|" << setw(10) << S_Price;
	cout << "\t|" << endl;

}//end of display 


void Stock::DisplayPrice(void)//Displays price from options
{
	cout << "\t|" << setw(10) << S_ID_Num;
	cout << "\t|" << setw(10) << S_Name;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//changes text colour
	//changes colour for price changes by user to highlight these changes to the user
	SetConsoleTextAttribute(h, 12);
	cout << "\t|" << setw(10) << S_Quantity << "\t|";
	SetConsoleTextAttribute(h, 7);//changes text colour back to default

	cout << " " << setw(10) << S_Price << "\t |" << endl;
	cout << "\t\n";

}//end of displayPrice 


void Stock::DisplayQuantity(void)//Displays price from options
{
	cout << "\t|" << setw(10) << S_ID_Num;
	cout << "\t|" << setw(10) << S_Name;
	cout << "\t|" << setw(10) << S_Price;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//changes colour for price changes by user to highlight these changes to the user
	SetConsoleTextAttribute(h, 12);
	cout << "\t|" << setw(10) << S_Quantity << "\t |" << endl;
	cout << "\t\n";
	SetConsoleTextAttribute(h, 7);//changes text colour back to default

}//end of displayPrice

void Stock::SetPrice(double price)
{
	S_Price = price; //sets input price to price of item

}//end of Set Price 

void Stock::SetQuantity(int Quantity) {
	S_Quantity = Quantity; //sets input Quantity to Quantity of item
}//end of set quantity

bool Stock::HasCode(int searchCode)
{
	if (S_ID_Num == searchCode)
		return true;
	else
		return false;
}

bool Stock::HasName(string Name)
{
	if (S_Name == Name)
		return true;
	else
		return false;
}