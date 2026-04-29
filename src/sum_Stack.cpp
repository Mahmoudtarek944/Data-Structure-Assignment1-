
#include "sum_Stack.h"
using namespace std;

int sum_Stack::Sum(string text) {
    stack<int> nums;
    stack<int> ops;

    int num = 0;
    int sign = 1;
    int result = 0;

    for (int i = 0; i < text.size(); i++) {
        char c = text[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        else if (c == '+' || c == '-') {
            result += sign * num;
            num = 0;
            sign = (c == '+') ? 1 : -1;
        }
        else if (c == '(') {
            nums.push(result);
            ops.push(sign);
            result = 0;
            sign = 1;
        }
        else if (c == ')') {
            result += sign * num;
            num = 0;
            result = ops.top() * result;
            ops.pop();
            result += nums.top();
            nums.pop();
        }
    }

    result += sign * num;
    return result;

}
