#include <iostream>
using namespace std;

#define MAX 100

class CircularQueue {
  int arr[MAX];
  int front, rear;

public:
  CircularQueue() { front = rear = -1; }

  bool isEmpty() { return front == -1; }
  bool isFull() {
    return (front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front;
  }

  void enqueue(int x) {
    if (isFull()) {
      cout << "Queue Full\n";
      return;
    }
    if (isEmpty())
      front = rear = 0;
    else
      rear = (rear + 1) % MAX;
    arr[rear] = x;
  }

  void dequeue() {
    if (isEmpty()) {
      cout << "Queue Empty\n";
      return;
    }
    if (front == rear)
      front = rear = -1;
    else
      front = (front + 1) % MAX;
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
    int i = front;
    while (i != rear) {
      cout << arr[i] << " ";
      i = (i + 1) % MAX;
    }
    cout << "\n";
  }
};

int main() {
  CircularQueue cq;
  int choice, val;
  do {
    cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
    cin >> choice;
    switch (choice) {
    case 1:
      cin >> val;
      cq.enqueue(val);
      break;
    case 2:
      cq.dequeue();
      break;
    case 3:
      cq.peek();
      break;
    case 4:
      cq.display();
      break;
    }
  } while (choice != 5);
}
