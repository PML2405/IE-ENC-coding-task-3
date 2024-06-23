#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> brac;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            brac.push(s[i]);
        } else {
            if (brac.empty()){
                return false;
            } 
            char top = brac.top();
            if ((s[i] == '}' && top == '{') ||
                (s[i] == ']' && top == '[') ||
                (s[i] == ')' && top == '(')) {
                brac.pop();
            } else {
                return false; 
            }
        }
    }
    return brac.empty(); 
}

int main() {
    string s;
    cout << "Enter the bracket string" << endl;
    cin >> s;
    if (isValid(s)) {
        cout << "String is Valid" << endl;
    } else {
        cout << "Invalid string" << endl;
    }
    return 0;
}
