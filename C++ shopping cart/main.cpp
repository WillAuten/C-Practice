#include <iostream>

#include <string>

#include "ItemToPurchase.h"

#include "ShoppingCart.h"

using namespace std;

char PrintMenu()

{

char answer;

cout <<"MENU" << endl;

cout << "a - Add item to cart" << endl;

cout << "d - Remove item from cart" << endl;

cout << "c - Change item quantity" << endl;

cout << "i - Output items' descriptions" << endl;

cout << "o - Output shopping cart" << endl;

cout <<"q - Quit" << endl << endl;

while(true)

{

cout << "Choose an option: " << endl;

cin >> answer;

if (answer == 'a' || answer == 'A')

break;

if (answer == 'd' || answer == 'D')

break;

if (answer == 'c' || answer == 'C')

break;

if (answer == 'i' || answer == 'I')

break;

if (answer == 'o' || answer == 'O')

break;

if (answer == 'q' || answer == 'Q')

break;

}

return answer;

}

void AddItem ()

{

string itemName = "";

string itemDescription;

int itemQuantity;

int itemPrice;

cout << "ADD ITEM TO CART" << endl;

cout << "Enter the item name: " << endl;

cin.ignore();

getline (cin, itemName);

cout << "Enter the item description: " << endl;

cin.ignore();

getline(cin, itemDescription);

cout << "Enter the item price: " << endl;

cin >> itemPrice;

cout << endl << "Enter the item quantity: " << endl;

cin >> itemQuantity;

ItemToPurchase itemToAdd(itemName, itemDescription, itemPrice, itemQuantity);


}

int main()

{

string itemToRemove;

string customerName;

string currentDate;

cout << "Enter customer's name:" << endl;

getline(cin, customerName);

cout << "Enter today's date:" << endl;
cout <<""<<endl;

getline(cin, currentDate);

cout << "Customer name: " << customerName << endl;

cout << "Today's date: " << currentDate << endl;
cout <<""<<endl;

ShoppingCart itemCart(customerName, currentDate);

char answer = PrintMenu();


while (answer != 'q')

{

   if (answer == 'o' || answer == 'O')

{

cout <<"OUTPUT SHOPPING CART" << endl;

itemCart.PrintTotal();

}

if (answer == 'a' || answer == 'A')

{

AddItem();

}

if (answer == 'i' || answer == 'I'){

cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;

itemCart.PrintDescriptions();

}

if (answer == 'd' || answer == 'D')

{

cout << "REMOVE ITEM FROM CART" << endl << "Enter name of item to remove: ";

getline(cin, itemToRemove);

}

if (answer == 'c' || answer == 'C')

break;

if (answer == 'q' || answer == 'Q')

break;

answer = PrintMenu();

}

}