#include<iostream>
using namespace std;
class node{
    public: 
    int data;
    node *next;
    node(int data1){
        data=data1;
        next=nullptr;
    }
    node (int data1, node *next1){
        data=data1;
        next=next1;
}  
};
node * reverselinkedlistkgroup( node *head,int k){
    node *currentnode=head;
    int totalnodes=0;
    while(currentnode!=nullptr&&totalnodes<k){
        currentnode=currentnode->next;
        totalnodes++;
    }
    if(totalnodes<k) return head;
    currentnode=head;
    node*prevnode=nullptr;
    node *nextnode=nullptr;
    int count=0;

     while(count<k&& currentnode!=nullptr){
        nextnode=currentnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
        count++;
     }
     head->next=reverselinkedlistkgroup(nextnode,k);
     return prevnode;
}

int main() {
    // Create Linked List: 1->2->3->4->5->6->NULL
    node* head = new node(1);
    head->next = new   node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);

    int k = 2; 
    head = reverselinkedlistkgroup(head, k);
  cout << "Reversed Linked List in groups of " << k << ": ";
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
