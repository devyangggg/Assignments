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

  void display() {
    for (int i = front; i <= rear; i++)
      cout << arr[i] << " ";
    cout << "\n";
  }
};

void interleave(Queue &q) {
  int n = q.size();
  int half = n / 2;
  int first[MAX], second[MAX];
  int fSize = 0, sSize = 0;

  for (int i = 0; i < half; i++)
    first[fSize++] = q.dequeue();
  while (!q.isEmpty())
    second[sSize++] = q.dequeue();

  for (int i = 0; i < half; i++) {
    q.enqueue(first[i]);
    q.enqueue(second[i]);
  }
}

int main() {
  Queue q;
  int arr[] = {4, 7, 11, 20, 5, 9};
  for (int x : arr)
    q.enqueue(x);

  interleave(q);
  q.display();
}
