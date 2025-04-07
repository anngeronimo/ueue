#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int linearSearchCounter = 0;
int binarySearchCounter = 0;
int jumpSearchCounter = 0;
int interpolationSearchCounter = 0;


bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false; 
        }
    }
    return true; 
}

void linearSearch(const vector<int>& arr, int searchValue) {
    linearSearchCounter++;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == searchValue) {
            cout << "Linear Search: Found at index " << i << ".\n";
            return;
        }
    }
    cout << "Linear Search: Not found.\n";
}

void binarySearch(const vector<int>& arr, int searchValue) {
    binarySearchCounter++;
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == searchValue) {
            cout << "Binary Search: Found at index " << mid << ".\n";
            return;
        }
        if (arr[mid] < searchValue)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "Binary Search: Not found.\n";
}

void jumpSearch(const vector<int>& arr, int searchValue) {
    jumpSearchCounter++;
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < searchValue) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "Jump Search: Not found.\n";
            return;
        }
    }

    while (arr[prev] < searchValue) {
        prev++;
        if (prev == min(step, n)) {
            cout << "Jump Search: Not found.\n";
            return;
        }
    }

    if (arr[prev] == searchValue) {
        cout << "Jump Search: Found at index " << prev << ".\n";
    } else {
        cout << "Jump Search: Not found.\n";
    }
}

void interpolationSearch(const vector<int>& arr, int searchValue) {
    interpolationSearchCounter++;
    int low = 0, high = arr.size() - 1;

    while (low <= high && searchValue >= arr[low] && searchValue <= arr[high]) {
        if (low == high) {
            if (arr[low] == searchValue) {
                cout << "Interpolation Search: Found at index " << low << ".\n";
            } else {
                cout << "Interpolation Search: Not found.\n";
            }
            return;
        }

        int pos = low + ((high - low) / (arr[high] - arr[low]) * (searchValue - arr[low]));

        if (arr[pos] == searchValue) {
            cout << "Interpolation Search: Found at index " << pos << ".\n";
            return;
        }

        if (arr[pos] < searchValue)
            low = pos + 1;
        else
            high = pos - 1;
    }
    cout << "Interpolation Search: Not found.\n";
}

int main() {
    int N, searchValue;
    cout << "Enter the number of elements: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    if (!isSorted(arr)) {
        cout << "The array is not sorted. Please sort the array!\n";
        return 1; 
    }

    cout << "Enter the search value: ";
    cin >> searchValue;

    linearSearch(arr, searchValue);
    binarySearch(arr, searchValue);
    jumpSearch(arr, searchValue);
    interpolationSearch(arr, searchValue);

    cout << "\nSearch Algorithm Call Counts:\n";
    cout << "Linear Search: " << linearSearchCounter << " times\n";
    cout << "Binary Search: " << binarySearchCounter << " times\n";
    cout << "Jump Search: " << jumpSearchCounter << " times\n";
    cout << "Interpolation Search: " << interpolationSearchCounter << " times\n";

    return 0;
}