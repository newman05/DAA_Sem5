/* 3.1 Aim of the program: Write a menu driven program to sort list of array elements
   using Merge Sort technique and calculate the execution time only to sort the elements.
   Count the number of comparisons.
*/

#include <bits/stdc++.h>
using namespace std;

long long comparisons = 0;

void merge(vector<int> &a, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        comparisons++;
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int choice;
    cout << "MAIN MENU (MERGE SORT)\n";
    cout << "1. Ascending Data\n";
    cout << "2. Descending Data\n";
    cout << "3. Random Data\n";
    cout << "4. ERROR (EXIT)\n";
    cout << "Enter option: ";
    cin >> choice;

    vector<int> arr;
    int n = 100;
    if (choice == 1)
    {
        arr.resize(n);
        iota(arr.begin(), arr.end(), 1); 
    }
    else if (choice == 2)
    {
        arr.resize(n);
        for (int i = 0; i < n; i++)
            arr[i] = n - i; 
    }
    else if (choice == 3)
    {
        arr.resize(n);
        srand(time(0));
        for (int i = 0; i < n; i++)
            arr[i] = rand();
    }
    else
        return 0;

    cout << "Before Sorting: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    comparisons = 0;
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();

    cout << "After Sorting: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    cout << "Number of Comparisons: " << comparisons << "\n";
    cout << "Execution Time: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << " nanoseconds\n";
}