#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    ifstream file("input.txt"); 

    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    int n;
    file >> n;

    if (n < 2) {
        cout << "Need at least two numbers in the array." << endl;
        return 1;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        file >> arr[i];
    }
    file.close();

    int smallest = INT_MAX, secondSmallest = INT_MAX;
    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < n; ++i) {
        int num = arr[i];

        if (num < smallest) {
            secondSmallest = smallest;
            smallest = num;
        } else if (num > smallest && num < secondSmallest) {
            secondSmallest = num;
        }

        if (num > largest) {
            secondLargest = largest;
            largest = num;
        } else if (num < largest && num > secondLargest) {
            secondLargest = num;
        }
    }

    if (secondSmallest == INT_MAX)
        cout << "No second smallest (all elements may be equal)." << endl;
    else
        cout << "Second Smallest: " << secondSmallest << endl;

    if (secondLargest == INT_MIN)
        cout << "No second largest (all elements may be equal)." << endl;
    else
        cout << "Second Largest: " << secondLargest << endl;

    return 0;
}
