#include <iostream>
using namespace std;
#define MAX 100

class Queue {
  int arr[MAX];
  int front, rear;

public:
  Queue() { front = rear = -1; }
  bool isEmpty() { return front == -1; }
  void enqueue(int x) {
    if (rear == MAX - 1)
      return;
    if (isEmpty())
      front = 0;
    arr[++rear] = x;
  }
  int dequeue() {
    if (isEmpty())
      return -1;
    int val = arr[front];
    if (front == rear)
      front = rear = -1;
    else
      front++;
    return val;
  }
  int size() { return isEmpty() ? 0 : (rear - front + 1); }
  int frontVal() { return isEmpty() ? -1 : arr[front]; }
};

class Stack {
  Queue q1, q2;

public:
  void push(int x) {
    q2.enqueue(x);
    while (!q1.isEmpty())
      q2.enqueue(q1.dequeue());
    Queue temp = q1;
    q1 = q2;
    q2 = temp;
  }
  void pop() { q1.dequeue(); }
  void top() { cout << q1.frontVal() << "\n"; }
};

int main() {
  Stack st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.top();
  st.pop();
  st.top();
}
