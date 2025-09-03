#include <cstring>
#include <iostream>
using namespace std;

#define MAX 100

class Stack {
  char arr[MAX];
  int top;

public:
  Stack() { top = -1; }
  void push(char c) { arr[++top] = c; }
  char pop() { return arr[top--]; }
  bool isEmpty() { return top == -1; }
};

int main() {
  char str[MAX];
  cout << "Enter string: ";
  cin >> str;

  Stack s;
  for (int i = 0; i < strlen(str); i++)
    s.push(str[i]);

  cout << "Reversed: ";
  while (!s.isEmpty())
    cout << s.pop();
  cout << "\n";
}
