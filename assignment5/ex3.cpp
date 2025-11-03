
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

void removeloop(node* head) {
    if (head == NULL || head->next == NULL)
        return;

    node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (fast == NULL || fast->next == NULL)
        return;

    slow = head;
    node* prev = NULL;
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;
}

int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    // creating loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    removeloop(head);

    cout << "Linked list after removing loop: ";
    node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}
