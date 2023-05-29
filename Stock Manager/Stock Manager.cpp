#include "Stock.h" // Connects Stock header file

Stock list[5]; // Array to store items
int numItems = 0; //this is the number of items

// Function declarations
void TextRed(); 
void TextGreen(); 
void TextWhite(); 
int ShowMenu();
void ItemHeaderDisplay();
void DoDisplayItem();
void DoChangePrice();
void DoChangeQuantity();
void UnlistedItem();
void SearchItem();


int main()
{
	// Start of Password Protection ~ Charlie

	cout << "PASSWORD CAN BE FOUND IN DOCUMENTATION\n";
	cout << "\t\n";
	for (int i = 0; i < 3; i++)
	{
		string attempt;
		cout << 4 - (i + 1) << " Attempts Remain\n"; // Password counter
		cout << "Please Enter Password\n";
		cout << "\t\n";
		cin >> attempt; // Password input

		if (list[i].Password(attempt) == true) {
			system("cls"); // Clears the correct password from the screen for security
			TextGreen();
			cout << "Correct Password\n"; // Displays this prompt to inform the user that the password was correct
			TextWhite();
			break;
		}
		else if (i == 2) {
			TextRed();
			cout << "Too Many Password Attempts";
			TextWhite();
			return 0;
		}
		else {
			TextRed();
			cout << "Incorrect Password\n";
			TextWhite();
		}
	} // End of Password Protection

	ifstream infile("Stock.dat"); // Opens file with stock

	if (!infile) { // Tests if the file exists
		TextRed();
		cout << "Error: input file not found";
		TextWhite();
		exit(0);
	}
	else { // If the file exists
		TextGreen();
		cout << "Input File Found\n";
		TextWhite();

		int ID;
		string Name;
		int Quantity;
		double Price;

		infile >> numItems;

		for (int i = 0; i < numItems; i++) {//This forloop populates arrays with infile content

			infile >> ID >> Name >> Quantity >> Price;
			Stock item(ID, Name, Price, Quantity);
			list[i] = item;

		}//end of for loop
	} // End of file Test



	int opt;
	do
	{
		opt = ShowMenu();
		switch (opt)
		{	
		case 0:
			DoDisplayItem();
			break;
		case 1:
			SearchItem();
			break;
		case 2:
			DoChangePrice();
			break;
		case 3:
			DoChangeQuantity();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "invalid option\n";
		}
	} while (opt != 10);



}//End of Main

void TextRed()//Changes text colour to Red
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(h, 12); //changes colour to red
}

void TextGreen() {// Changes text colour to Green
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 10); //changes colour to green
}


void TextWhite()// Changes color back to White(default)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(h, 7); // Changes color back to default
}

int ShowMenu()//Meenu display
{
	int option;
	cout << "\t0.		Display Stock\n";
	cout << "\t1.		Search Item\n";
	cout << "\t2.		Change Item Price\n";
	cout << "\t3.		Change Item Quantity\n";
	cout << "\t4.		Exit Program\n";

	cin >> option;
	return option;

}//end ShowMenu

void ItemHeaderDisplay()//this function was not specified, it is for additional functionality
{
	TextGreen();

	//this is the table header for diplaying items
	cout << setw(35) << "\t Item List" << endl;
	cout << "\t|" << setw(10) << "ID Number";
	cout << "\t|" << setw(10) << "Name";
	cout << "\t|" << setw(10) << "Quantity";
	cout << "\t|" << setw(10) << "Price[Euro]";
	cout << "\t|" << endl;

	TextWhite();

}//end of Item Headers 

void DoDisplayItem(void) //This displays all the items in stock
{
	ItemHeaderDisplay();//header for list

	for (int i = 0; i < numItems; i++) {//loop for displaying each item
		list[i].Display();//function for each varible in array to display
	}
	cout << "\t\n";//spacing for visual appeal 

}//end of display 

void DoChangePrice(void)//Changes price of selected Item
{

	double price;
	int i;//varilbe for user to select item
	cout << "\t\n";
	cout << "Select item you wish to change the price of.\n";
	cout << "-input item code to select an item\n";
	cout << "(Item code can be found on list item, option 0)\n";
	cin >> i;
	cout << "Selected item: " << i << endl;//user input
	i = i - 1;//matches item code to array number for searching item

	if (i > numItems || i < 0) {//checks if item code matches current number of items
		UnlistedItem();//displays item not found, if boolean expression = true
	}

	else {//else, meaning item is listed
		cout << "input price change\n";
		cin >> price;//price change input


		list[i].SetPrice(price);//compares item codes to users input code
		cout << "\t\n";
		TextRed();
		cout << "Changes highlighted in red\n";
		TextWhite();

		//desplays changed item
		ItemHeaderDisplay();
		list[i].DisplayPrice();
	}


}//end of Set Price 

void DoChangeQuantity(void)//Changes price of selected Item
{

	int Quantity;
	int i;//varilbe for user to select item
	cout << "\t\n";
	cout << "Select item you wish to change the Quantity of.\n";
	cout << "-input item code to select an item\n";
	cout << "(Item code can be found on list item, option 0)\n";
	cin >> i;
	cout << "Selected item: " << i << endl;//user input
	i = i - 1;//matches item code to array number for searching item

	if (i > numItems || i < 0) {//checks if item code matches current number of items
		UnlistedItem();//displays item not found, if boolean expression = true
	}

	else {//else, meaning item is listed
		cout << "input quantity change\n";
		cin >> Quantity;//price change input


		list[i].SetQuantity(Quantity);//compares item codes to users input code
		cout << "\t\n";
		TextRed();
		cout << "Changes highlighted in red\n";
		TextWhite();

		//desplays changed item
		ItemHeaderDisplay();
		list[i].DisplayQuantity();
	}


}//end of Set Price 

void UnlistedItem(void) {//this function was not specified, it is for additional functionality

	TextRed();

	//displays this prompt when items aren't found
	cout << "\t	Sorry, Item is not on our listing\n";
	cout << "\t\n";

	TextWhite();
}//end of unlisted Item 


void SearchItem()//this function was not specified, it is for additional functionality
{
	cout << "\t\n";
	int option;
	cout << "Do you wish to search item by:\n";
	cout << "Option 1: Item ID Number\n";
	cout << "Option 2: Item Name\n";
	cout << "Option 3: Back to Menu\n";
	cout << "Enter 1, 2 or 3\n";
	cout << "\t\n";
	cin >> option;//user input for option

	switch (option) {

	case 1://option 1: Item code search
	{
		int searchCode;
		cout << "Search Item ID Number\n";
		cout << "Enter an Item ID Number(int)\n";
		cout << "\t\n";
		cin >> searchCode;//user inputs item code

		for (int i = 0; i < numItems; i++)//loop means each item is compare to users input
		{


			if (list[i].HasCode(searchCode) == true) {//if itm code found
				ItemHeaderDisplay();
				list[i].Display();//displays searched item only
				cout << "\t\n";
				i = numItems;

			}
			else if (i < numItems - 1 && list[i].HasCode(searchCode) == !true) {//if not found
				// if not found & still items left to search, nothing is sent to console screen
			}
			else {
				//every item has been compared to list & no match found
				UnlistedItem();//sends console , item not found

			}

		}//end of item code search
		break;
	}
	case 2://option 2: Item Description search
	{
		string Name;
		cout << "Search Item Name\n";
		cout << "Case sensitive! Capital first letter, lower case for remaining letters\n";
		cout << "\t\n";
		cin >> Name;//user inputs item Description

		for (int i = 0; i < numItems; i++)//loop means each item is compare to users input
		{


			if (list[i].HasName(Name) == true) {//if itm code found
				ItemHeaderDisplay();
				list[i].Display();//displays searched item only
				cout << "\t\n";
				i = numItems;

			}
			else if (i < numItems - 1 && list[i].HasName(Name) == !true) {//if not found
				// if not found & still items left to search, nothing is sent to console screen
			}
			else {
				//every item has been compared to list & no match found
				UnlistedItem();//sends console , item not found
			}

		}//end of item code search
		break;
	}
	default://Option 3, or any other int input not 1 or 2
	{
		return;
		break;// breaks out of loop returning back to menu
	}
	}//end of switch


}//end of Search Item ~ Charlie