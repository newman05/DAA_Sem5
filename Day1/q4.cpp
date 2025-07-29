/*
1.4 Aim of the program: Write a function to ROTATE_RIGHT (p1, p2) right an array for first p2
elements by 1 position using EXCHANGE (p, q) function that swaps/exchanges the numbers p
&amp; q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
rotated.
*/

#include <iostream>
using namespace std;

void EXCHANGE(int &p, int &q) {
    int temp = p;
    p = q;
    q = temp;
}

void ROTATE_RIGHT(int* p1, int p2) {
    for (int i = p2 - 1; i > 0; --i) {
        EXCHANGE(p1[i], p1[i - 1]);
    }
}

int main() {
    int n = 9;
    int A[n] = {11, 22, 33, 44, 55, 66, 77, 88, 99};

    cout<<"Before ROTATE: ";
    for (int i = 0; i < n; ++i) cout<<A[i]<<" ";
    cout<<endl;

    ROTATE_RIGHT(A, 5);  
    cout<<"After ROTATE: ";
    for (int i = 0; i < n; ++i) cout<<A[i]<<" ";
    cout<<endl;

    return 0;
}



