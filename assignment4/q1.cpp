#include <iostream>
using namespace std;

#define MAX 100

class Queue {
  int arr[MAX];
  int front, rear;

public:
  Queue() { front = rear = -1; }

  bool isEmpty() { return front == -1; }
  bool isFull() { return rear == MAX - 1; }

  void enqueue(int x) {
    if (isFull()) {
      cout << "Queue Full\n";
      return;
    }
    if (isEmpty())
      front = 0;
    arr[++rear] = x;
  }

  void dequeue() {
    if (isEmpty()) {
      cout << "Queue Empty\n";
      return;
    }
    if (front == rear)
      front = rear = -1;
    else
      front++;
  }

  void peek() {
    if (isEmpty())
      cout << "Queue Empty\n";
    else
      cout << "Front: " << arr[front] << "\n";
  }

  void display() {
    if (isEmpty()) {
      cout << "Queue Empty\n";
      return;
    }
    for (int i = front; i <= rear; i++)
      cout << arr[i] << " ";
    cout << "\n";
  }
};

int main() {
  Queue q;
  int choice, val;
  do {
    cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
    cin >> choice;
    switch (choice) {
    case 1:
      cin >> val;
      q.enqueue(val);
      break;
    case 2:
      q.dequeue();
      break;
    case 3:
      q.peek();
      break;
    case 4:
      q.display();
      break;
    }
  } while (choice != 5);
}
