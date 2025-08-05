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
