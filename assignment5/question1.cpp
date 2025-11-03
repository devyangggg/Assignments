#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertBefore(int target, int val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->data == target) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != target) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Target not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void insertAfter(int target, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != target) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Target not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Node not found!\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found!\n";
    }
    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty!\n";
            return;
        }
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    LinkedList list;
    int choice, val, target;
    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete a Specific Node\n";
        cout << "8. Search a Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter target and new value: ";
            cin >> target >> val;
            list.insertBefore(target, val);
            break;
        case 4:
            cout << "Enter target and new value: ";
            cin >> target >> val;
            list.insertAfter(target, val);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteNode(val);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> val;
            list.search(val);
            break;
        case 9:
            list.display();
            break;
        case 10:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}