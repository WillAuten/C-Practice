#include <iostream>

#include <string>

#include "ItemToPurchase.h"

using namespace std;

void ItemToPurchase::SetName(string itemName)

{

itemName = itemName;

}

void ItemToPurchase::SetPrice(int itemPrice)

{

itemPrice = itemPrice;

}

void ItemToPurchase::SetQuantity(int itemQuantity)

{

itemQuantity = itemQuantity;

}

void ItemToPurchase::SetDescription(string itemDescription)

{

itemDescription = itemDescription;

}

string ItemToPurchase::GetName() const

{

return itemName;

}

int ItemToPurchase::GetPrice() const

{

return itemPrice;

}

int ItemToPurchase::GetQuantity() const

{

return itemQuantity;

}

string ItemToPurchase::GetDescription() const

{

return itemDescription;

}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity)

{

SetName(name);

SetPrice(price);

SetQuantity(quantity);

SetDescription(description);

}

void ItemToPurchase::PrintItemCost()

{

cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity

<< itemPrice << endl;

return;

}

void ItemToPurchase::PrintItemDescription()

{

cout << itemName << ": " << itemDescription << endl;

return;

}