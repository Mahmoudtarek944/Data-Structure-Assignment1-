#include<bits/stdc++.h>
using namespace std;


#include <string>
#include <stack>
using namespace std;

int calculate(string s) {
    stack<int> stk;  // saves (running_total, sign) when entering (
    int result = 0;  // running total for the current scope
    int num = 0;  // digits being accumulated right now
    int sign = 1;  // +1 means add, -1 means subtract

    for (char ch : s) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        } else if (ch == '+') {
            result += sign * num;
            num = 0;
            sign = +1;
        } else if (ch == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (ch == '(') {
            stk.push(result);
            stk.push(sign);
            result = 0;
            sign = 1;
        } else if (ch == ')') {
            result += sign * num;
            num = 0;
            int sign_before = stk.top(); stk.pop();
            int outer = stk.top(); stk.pop();
            result = outer + sign_before * result;
        }
    }

    result += sign * num;
    return result;
}

int main() {

    string s = " 2-1 + 2 " ;
    cout << calculate(s);

    return 0;
}