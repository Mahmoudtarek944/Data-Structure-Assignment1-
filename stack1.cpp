#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    stack<int> st;
    int result = 0;
    int number = 0; // if the number is not only one digit
    int sign = 1;

    for (int i = 0; i < s.size(); i++) {
        if(s[i] == ' '){
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9') { // hold digit by digit
            number = number * 10 + (s[i] - '0');
        }
        else if (s[i] == '+') {
            result += sign * number;
            number = 0;
            sign = 1; // positive num
        }
        else if (s[i] == '-') {
            result += sign * number;
            number = 0; 
            sign = -1; // negative num
        }
        else if (s[i] == '(') {
            st.push(result);
            st.push(sign);
            result = 0;
            sign = 1;
        }
        else if (s[i] == ')') {
            result += sign * number;
            number = 0;
            result *= st.top(); // sign
            st.pop();
            result += st.top(); // the last result
            st.pop();
        }
    }
    result += sign * number;
    return result;
}
int main() {
    string s;
    getline(cin, s);
    cout << calculate(s) << endl;
}