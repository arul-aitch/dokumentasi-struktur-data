#include <iostream>
#include <stack>
#include <string>
using namespace std;


int precedence(char op) {
	if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

void infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isalnum(c)) {
            result += c;
        } else if (c == '(') {
            st.push('(');
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    cout << "Ekspresi Postfix: " << result << endl;
}

int main() {
    string exp = "a+(2*b^3)/(f-g)+d*h";
    
    cout << "Ekspresi Infix : " << exp << endl;
    infixToPostfix(exp);

    return 0;
}
