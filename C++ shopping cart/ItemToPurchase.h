#pragma once

#include <iostream>

#include <string>

using namespace std;

class ItemToPurchase {

public:

ItemToPurchase(string, string, int, int); 

void SetName(string);

void SetPrice(int);

void SetQuantity(int);

void SetDescription(string);

void PrintItemCost();

void PrintItemDescription();

string GetName() const;

int GetPrice() const;

int GetQuantity() const;

string GetDescription() const;

private:

string itemName;

int itemPrice;

int itemQuantity;

string itemDescription;

};