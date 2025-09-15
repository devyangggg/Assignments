#include <iostream>
using namespace std;
#define MAX 256

class Queue {
  char arr[1000];
  int front, rear;

public:
  Queue() { front = rear = -1; }
  bool isEmpty() { return front == -1; }
  void enqueue(char x) {
    if (rear == 999)
      return;
    if (isEmpty())
      front = 0;
    arr[++rear] = x;
  }
  void dequeue() {
    if (isEmpty())
      return;
    if (front == rear)
      front = rear = -1;
    else
      front++;
  }
  char getFront() { return isEmpty() ? '\0' : arr[front]; }
};

void firstNonRepeating(string s) {
  Queue q;
  int freq[MAX] = {0};

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];
    freq[(int)c]++;
    q.enqueue(c);

    while (!q.isEmpty() && freq[(int)q.getFront()] > 1)
      q.dequeue();

    if (q.isEmpty())
      cout << -1 << " ";
    else
      cout << q.getFront() << " ";
  }
  cout << "\n";
}

int main() {
  string s = "aabc";
  firstNonRepeating(s);
}
