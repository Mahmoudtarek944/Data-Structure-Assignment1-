#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(n, -1);

    stack<int> stk;

    for (int i = 0; i < 2 * n; i++) {
        int curr = nums[i % n];

        while (!stk.empty() && curr > nums[stk.top()]) {
            ans[stk.top()] = curr;
            stk.pop();
        }

        if (i < n) {
            stk.push(i);
        }
    }

    return ans;
}

int main() {
    vector<int> arr =  {1,2,3,4,3};

    vector<int> ans = nextGreaterElements(arr);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";



    return 0;
}