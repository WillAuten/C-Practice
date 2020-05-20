#include <iostream>
#include "ContactNode.h"
using namespace std;

ContactNode::ContactNode(){
nextNodePtr=NULL;
}

ContactNode::ContactNode(string name, string phoneNum){
contactName=name;
contactPhoneNum=phoneNum;
nextNodePtr=NULL;
}
void ContactNode::InsertAfter(ContactNode *nextNode){
ContactNode *temp;
if(nextNodePtr==NULL)
nextNodePtr=nextNode;
else{
temp=nextNodePtr;
while(temp->nextNodePtr!=NULL){
temp=temp->GetNext();
}
temp->nextNodePtr=nextNode;   
}
}
string ContactNode::GetName(){
return contactName;
}
string ContactNode::GetPhoneNumber(){
return contactPhoneNum;
}
ContactNode* ContactNode::GetNext(){
return nextNodePtr;
}
void ContactNode::PrintContactNode(){
ContactNode *temp;
  
if(nextNodePtr!=NULL) {
cout<<"Name: "<<nextNodePtr->GetName()<<endl;
cout<<"Phone number: "<<nextNodePtr->GetPhoneNumber()<<endl<<endl;
  
GetNext()->PrintContactNode();
}
}