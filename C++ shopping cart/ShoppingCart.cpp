
#include <iostream>

#include <string>

#include "ShoppingCart.h"

using namespace std;

ShoppingCart::ShoppingCart(string customerName, string currentDate){

currentDate = "January 1, 2016";

customerName = "none";

}

string ShoppingCart::GetCustomerName()

{

return customerName;

}

string ShoppingCart::GetDate()

{

return currentDate;

}

void ShoppingCart::AddItem(ItemToPurchase item)

{

cartItems.push_back(item);

}

void ShoppingCart::RemoveItem(string item)

{

int oldsize = cartItems.size();

for (int i = 0; i < cartItems.size(); i++){

if (cartItems.at(i).GetName() == item)

cartItems.erase(cartItems.begin()+i);

}

if(oldsize == cartItems.size())

cout << "item not found in cart. Nothing removed." << endl;

}

void ShoppingCart::ModifyItem(ItemToPurchase item)

{

bool bItemsModified = false;

for (int i = 0; i < cartItems.size(); i++){

if (cartItems.at(i).GetName() == item.GetName()){

cartItems.at(i).SetPrice(item.GetPrice());

cartItems.at(i).SetQuantity(item.GetQuantity());

cartItems.at(i).SetDescription(item.GetDescription());

bItemsModified = true;

}

}

if (bItemsModified == false)

cout << " Item not found in cart. Nothing modified.";

}

int ShoppingCart::GetNumItemsInCart(){

int result = cartItems.size();

return result;

}

int ShoppingCart::GetCostOfCart()

{

int total = 0;

for (int i = 0; i < cartItems.size(); i++)

{

total = total + (cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity());

}

return total;

}

void ShoppingCart::PrintTotal()

{

int total = 0;

cout << customerName << "'s Shopping Cart - " << currentDate << endl;

if(cartItems.size() == 0)

{

cout << "Number of Items: 0" << endl << endl;

cout << "SHOPPING CART IS EMPTY" << endl << endl;

cout << "Total: $0" << endl << endl;

}

else{

cout << "Number of Items " << GetNumItemsInCart() << endl << endl;

for(int i = 0; i < cartItems.size(); i++)

{

cout << cartItems.at(i).GetName() << " " << cartItems.at(i).GetQuantity() << " @ $" << cartItems.at(i).GetPrice()

<< " = $" << cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity() << endl;

total = total +   (cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity());

}

cout << endl << "Total: " << total << endl;

}

}

void ShoppingCart::PrintDescriptions()

{

cout << customerName << "'s Shopping Cart - " << currentDate << endl;

cout << "Item Descriptions" << endl;

for(int i = 0; i < cartItems.size(); i++){

cout << cartItems.at(i).GetName() << cartItems.at(i).GetDescription() << endl;

}

}