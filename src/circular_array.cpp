#include "circular_array.h"

#include <stack>


vector<int>circular_array::solve(vector<int> &arr) {
    stack<int> s;
    vector<int> v(arr.size(),-1);
    for(int i=0;i< 2*arr.size();i++) {

        int val=arr[i% arr.size()];
        while(!s.empty() && arr[s.top()]<val) {
            v[s.top()]=val;
            s.pop();
        }
        if (i<arr.size()) {
            s.push(i);
        }
    }
    return v;
}
