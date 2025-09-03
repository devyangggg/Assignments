#include <iostream>
using namespace std;

#define MAX 100

class Stack {
  int arr[MAX];
  int top;

public:
  Stack() { top = -1; }

  void push(int x) {
    if (top == MAX - 1)
      cout << "Stack Overflow\n";
    else
      arr[++top] = x;
  }

  int pop() {
    if (top == -1) {
      cout << "Stack Underflow\n";
      return -1;
    }
    return arr[top--];
  }

  bool isEmpty() { return top == -1; }
  bool isFull() { return top == MAX - 1; }

  int peek() {
    if (isEmpty()) {
      cout << "Stack Empty\n";
      return -1;
    }
    return arr[top];
  }

  void display() {
    if (isEmpty())
      cout << "Stack Empty\n";
    else {
      for (int i = top; i >= 0; i--)
        cout << arr[i] << " ";
      cout << "\n";
    }
  }
};

int main() {
  Stack s;
  int choice, val;
  while (true) {
    cout << "\n1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek "
            "7.Exit\nChoice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter value: ";
      cin >> val;
      s.push(val);
      break;
    case 2:
      val = s.pop();
      if (val != -1)
        cout << "Popped: " << val << "\n";
      break;
    case 3:
      cout << (s.isEmpty() ? "Empty\n" : "Not Empty\n");
      break;
    case 4:
      cout << (s.isFull() ? "Full\n" : "Not Full\n");
      break;
    case 5:
      s.display();
      break;
    case 6:
      val = s.peek();
      if (val != -1)
        cout << "Top: " << val << "\n";
      break;
    case 7:
      return 0;
    default:
      cout << "Invalid choice\n";
    }
  }
}
