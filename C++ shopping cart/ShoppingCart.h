#pragma once

#include <iostream>

#include <string>

#include <vector>

#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart {

public:

ShoppingCart(string customerName, string currentDate);

string GetCustomerName();

string GetDate();

void AddItem(ItemToPurchase);

void RemoveItem(string);

void ModifyItem(ItemToPurchase);

int GetNumItemsInCart();

int GetCostOfCart();

void PrintTotal();

void PrintDescriptions();

private:

string customerName;

string currentDate;

vector < ItemToPurchase > cartItems;

};