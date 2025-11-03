#include<iostream>
using namespace std;
class node {
    public:
    node*next;
    int  data;
    node (int data1){
        data=data1;
        next=nullptr;

    }
     node (int data1,node *next1){
        data=data1;
        next=next1;
    }
};
node* findintersection(node *head1,node *head2,int diff){
    if(diff>0){
        head1=head1->next;
        diff--;

    }
    while(head1!=NULL&&head2!=NULL){
        if(head1==head2) return head1;
        head1=head1->next;
        head2=head2->next;

    }
    return NULL;
}
node * intersectionnode(node*head1,node *head2){
    node *firstcurrnode=head1;
    int length1=0;
    while(firstcurrnode!=nullptr){
      length1++;
      firstcurrnode=firstcurrnode->next;
    }
    int length2=0;
    node  *secondcurrnode=head2;
    while(secondcurrnode!=nullptr){
        length2++;
        secondcurrnode=secondcurrnode->next;

    }
    if(length1<length2) findintersection(head2,head1,length2-length1);
    else findintersection(head1,head2,length1-length2);
}

int main() {
   
    node* head1 = new node(10, nullptr);
    head1->next = new node(20, nullptr);
    head1->next->next = new node(30, nullptr);
    head1->next->next->next = new node(40, nullptr);

    node* head2 = new node(15, nullptr);
    head2->next=new node(20,nullptr);
    head2->next = head1->next->next; // intersection at node with data = 30

    node* result = intersectionnode(head1, head2);

    if (result != NULL)
        cout << "Intersection Point: " << result->data << endl;
    else
        cout << "No Intersection Point" << endl;

    return 0;
}
