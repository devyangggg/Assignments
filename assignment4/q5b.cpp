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
  Queue q;

public:
  void push(int x) {
    q.enqueue(x);
    int sz = q.size();
    for (int i = 0; i < sz - 1; i++)
      q.enqueue(q.dequeue());
  }
  void pop() { q.dequeue(); }
  void top() { cout << q.frontVal() << "\n"; }
};

int main() {
  Stack st;
  st.push(5);
  st.push(15);
  st.push(25);
  st.top();
  st.pop();
  st.top();
}
