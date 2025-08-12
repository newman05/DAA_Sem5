/*2.1 Aim of the program: Write a program in C to convert the first ‘n’ decimal numbers of a disc
file to binary using recursion. Store the binary value in a separate disc file.*/

#include <bits/stdc++.h>
using namespace std;

#define kcod ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> ans;

void helper(int n) {
    if (n == 0) return;

    helper(n / 2);             
    ans.push_back(n % 2);     
}

int main() {
    kcod;

    int n;
    cin >> n;

    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }

    helper(n);

    for (int bit : ans) cout << bit;
    cout << endl;

    return 0;
}
