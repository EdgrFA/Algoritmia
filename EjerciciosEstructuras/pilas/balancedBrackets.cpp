//https://www.hackerrank.com/challenges/ctci-balanced-brackets/problem
#include <bits/stdc++.h>
using namespace std;

int typeOfBracket(char c){
    if(c == '{' || c == '(' || c == '[') return 0;
    if(c == '}' || c == ')' || c == ']') return 1;
    return -1;
}

bool isPairBracket(char c, char openB){
    if(openB == '{' && c == '}') return true;
    if(openB == '(' && c == ')') return true;
    if(openB == '[' && c == ']') return true;
    return false;
}

void isBalancedBracket(string expression){
    stack<int> brackets;
    for(int i = 0; i < expression.size(); i++){
        char c = expression[i]; 
        int opt = typeOfBracket(c);
        if(opt == 0) brackets.push(c);
        else if(opt == 1){
            if(brackets.empty() || !isPairBracket(c, brackets.top())){
                cout << "NO\n";
                return;
            }
            brackets.pop();
        }
    }
    if(brackets.empty()) cout << "YES\n";
    else cout << "NO\n";
}
