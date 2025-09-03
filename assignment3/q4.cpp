#include <cctype>
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
  char peek() { return arr[top]; }
  bool isEmpty() { return top == -1; }
};

int precedence(char op) {
  if (op == '^')
    return 3;
  if (op == '*' || op == '/')
    return 2;
  if (op == '+' || op == '-')
    return 1;
  return 0;
}

int main() {
  char infix[MAX], postfix[MAX];
  cout << "Enter infix: ";
  cin >> infix;

  Stack s;
  int k = 0;
  for (int i = 0; i < strlen(infix); i++) {
    char c = infix[i];
    if (isalnum(c))
      postfix[k++] = c;
    else if (c == '(')
      s.push(c);
    else if (c == ')') {
      while (!s.isEmpty() && s.peek() != '(')
        postfix[k++] = s.pop();
      s.pop(); // remove '('
    } else {
      while (!s.isEmpty() && precedence(s.peek()) >= precedence(c))
        postfix[k++] = s.pop();
      s.push(c);
    }
  }
  while (!s.isEmpty())
    postfix[k++] = s.pop();
  postfix[k] = '\0';

  cout << "Postfix: " << postfix << "\n";
}
