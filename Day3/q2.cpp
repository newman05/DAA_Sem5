/*3.2 Aim of the program: Write a menu driven program to sort a list of elements in ascending
order using Quick Sort technique. Each choice for the input data has its own disc file. A separate
output file can be used for sorted elements. After sorting display the content of the output file
along with number of comparisons. Based on the partitioning position for each recursive call,
conclude the input scenario is either best-case partitioning or worst-case partitioning.*/


#include <bits/stdc++.h>
using namespace std;

long long comparisons = 0;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            comparisons++;
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            comparisons++;
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

int main() {
    int choice;
    cout << "MAIN MENU (QUICK SORT)\n";
    cout << "1. Ascending Data\n";
    cout << "2. Descending Data\n";
    cout << "3. Random Data\n";
    cout << "4. EXIT\n";
    cout << "Enter option: ";
    cin >> choice;

    vector<int> arr;
    int n = 1000;

    if (choice == 1) {
        arr.resize(n);
        iota(arr.begin(), arr.end(), 1);
    }
    else if (choice == 2) {
        arr.resize(n);
        for (int i = 0; i < n; i++)
            arr[i] = n - i;
    }
    else if (choice == 3) {
        arr.resize(n);
        srand(time(0));
        for (int i = 0; i < n; i++)
            arr[i] = rand();
    }
    else
        return 0;

    cout << "Before Sorting: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    comparisons = 0;
    auto start = chrono::high_resolution_clock::now();
    qs(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();

    cout << "After Sorting: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    cout << "Number of Comparisons: " << comparisons << "\n";
    cout<<"Execution Time: "<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<" nanoseconds\n";

    return 0;
}