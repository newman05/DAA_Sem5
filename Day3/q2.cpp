/*3.2 Aim of the program: Write a menu driven program to sort a list of elements in ascending
order using Quick Sort technique. Each choice for the input data has its own disc file. A separate
output file can be used for sorted elements. After sorting display the content of the output file
along with number of comparisons. Based on the partitioning position for each recursive call,
conclude the input scenario is either best-case partitioning or worst-case partitioning.*/


#include <bits/stdc++.h>
using namespace std;

long long comparisons = 0;
bool worstCase = false, bestCase = true;

int partitionFunc(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    int pivotIndex = i + 1;

    int leftSize = pivotIndex - low;
    int rightSize = high - pivotIndex;

    if (leftSize == 0 || rightSize == 0) worstCase = true;
    if (abs(leftSize - rightSize) > (high - low) / 2) bestCase = false;

    return pivotIndex;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partitionFunc(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int choice;
    cout << "MAIN MENU (QUICK SORT)\n";
    cout << "1. Ascending Data\n";
    cout << "2. Descending Data\n";
    cout << "3. Random Data\n";
    cout << "4. ERROR (EXIT)\n";
    cout << "Enter option: ";
    cin >> choice;

    vector<int> arr;
    if (choice == 1) arr = {10, 20, 30, 40, 50, 60, 70};
    else if (choice == 2) arr = {90, 80, 70, 60, 50, 40, 30};
    else if (choice == 3) arr = {55, 66, 33, 11, 44, 99, 77};
    else return 0;

    cout << "Before Sorting: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    comparisons = 0;
    worstCase = false;
    bestCase = true;

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();

    cout << "After Sorting: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    cout << "Number of Comparisons: " << comparisons << "\n";
    if (worstCase) cout << "Scenario: Worst-case partitioning\n";
    else if (bestCase) cout << "Scenario: Best-case partitioning\n";
    else cout << "Scenario: Average-case partitioning\n";

    cout << "Execution Time: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << " nanoseconds\n";

    return 0;
}
