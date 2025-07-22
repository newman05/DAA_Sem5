
/*
1.1 Aim of the program: Write a program to find out the second smallest and second largest
element stored in an array of n integers.
Input: Size of the array is ‘n’ and read ‘n’ number of elements from a disc file.
Output: Second smallest, Second largest
*/

#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max = INT_MIN;
    int second_max = INT_MIN;
    int second_min = INT_MAX;
    int mini = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if (arr[i] > second_max && arr[i] != max) {
            second_max = arr[i];
        }
    }

    if (second_max == INT_MIN) {
        printf("There is no second largest element.\n");
    } else {
        printf("The second largest element is %d\n", second_max);
    }

    
    for (int i = 0; i < n; i++) {
        if (arr[i] < mini) {
            second_min = mini;
            mini = arr[i];
        } else if (arr[i] < second_min && arr[i] != mini) {
            second_min = arr[i];
        }
    }

    if (second_min == INT_MIN) {
        printf("There is no second smallest element.\n");
    } else {
        printf("The second smallest element is %d\n", second_min);
    }

    return 0;
}