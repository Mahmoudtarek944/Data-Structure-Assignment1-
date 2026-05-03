#include <bits/stdc++.h>
using namespace std;
int helloRecursive(int n) {
        if (n <= 1) return 1;
        return helloRecursive(n-1) + helloRecursive(n-2);
}
// O(2^n)
void test(int n) {
    int i = n;
    while (i > 1) {
        int j = 1;
        while (j < i) {
            j *= 2;
        }
        i /= 2;
    }
} 
// O(log(n)^2)
int main(){
    return 0 ;
}