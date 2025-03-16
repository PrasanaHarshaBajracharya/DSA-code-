#include <iostream>
#include <vector>
using namespace std;

// Binary search function
int binarysearch(vector<int> arr, int tar) {
    int start = 0, end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2; // Avoids potential overflow

        if (tar > arr[mid]) {
            start = mid + 1;
        } else if (tar < arr[mid]) {
            end = mid - 1;
        } else {
            return mid; // Target found
        }
    }

    return -1; // Target not found
}

int main() {
    int target;
    cout << "Enter the element you want to search: ";
    cin >> target;

    // Create a sorted vector from 1 to 1000
    vector<int> arr1;
    for (int i = 1; i <= 1000; ++i) {
        arr1.push_back(i);
    }

    // Perform binary search
    int index = binarysearch(arr1, target);

    // Output the result
    if (index != -1) {
        cout << "The element " << target << " is at index " << index << endl;
    } else {
        cout << "The element " << target << " is not found in the array." << endl;
    }

    return 0;
}