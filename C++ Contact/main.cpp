#include <iostream>
#include "ContactNode.h"
using namespace std;
int main()
{
ContactNode *List,*head;
string Name;
string PhoneNum;
List=new ContactNode;
for(int i=0;i<3;i++){
cout << "Person " << i+1 << endl;
cout << "Enter name:" << endl ;
getline(cin, Name);
cout << "Enter phone number:"<<endl ;
getline(cin, PhoneNum);
cout <<"You entered: "<< Name << ", " << PhoneNum << endl << endl;
List->InsertAfter(new ContactNode(Name,PhoneNum));
}
cout << "CONTACT LIST" << endl;
List->PrintContactNode();
return 0;
}