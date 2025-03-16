#include <iostream>
#include <vector>
using namespace std;

// Interpolation search function
int interpolationSearch(const vector<int>& arr, int low, int high, int key) {
    // Check if key is outside array range
    if (low > high || key < arr[low] || key > arr[high]) {
        return -1;
    }

    // Handle division by zero (if arr[high] == arr[low])
    if (arr[high] == arr[low]) {
        if (arr[low] == key) {
            return low;
        } else {
            return -1;
        }
    }

    // Calculate interpolation position
    int mid = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

    // If key is found
    if (arr[mid] == key) {
        return mid;
    }

    // If key is less, search in the left half
    if (arr[mid] > key) {
        return interpolationSearch(arr, low, mid - 1, key);
    } else {
        // If key is greater, search in the right half
        return interpolationSearch(arr, mid + 1, high, key);
    }
}

int main() {
    int key;
    cout << "Enter the key: ";
    cin >> key;

    // Create a sorted vector from 1 to 1000
    vector<int> arr1;
    for (int i = 1; i <= 1000; ++i) {
        arr1.push_back(i);
    }

    // Perform interpolation search
    int index = interpolationSearch(arr1, 0, arr1.size() - 1, key);

    // Output the result
    if (index != -1) {
        cout << "The key " << key << " is at index " << index << endl;
    } else {
        cout << "The key " << key << " is not found in the array." << endl;
    }

    return 0;
}