#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int linearSearchCounter = 0;
int binarySearchCounter = 0;
int jumpSearchCounter = 0;
int interpolationSearchCounter = 0;

void linearSearch(const vector<int>& arr, int searchValue) {
    linearSearchCounter++;
    int compares = 0;
    for (int i = 0; i < arr.size(); ++i) {
        compares++;
        if (arr[i] == searchValue) {
            cout << "Linear Search: Found at index " << i << " with " << compares << " compares.\n";
            return;
        }
    }
    cout << "Linear Search: Not found with " << compares << " compares.\n";
}

void binarySearch(const vector<int>& arr, int searchValue) {
    binarySearchCounter++;
    int left = 0, right = arr.size() - 1, compares = 0;
    while (left <= right) {
        compares++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == searchValue) {
            cout << "Binary Search: Found at index " << mid << " with " << compares << " compares.\n";
            return;
        }
        if (arr[mid] < searchValue)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "Binary Search: Not found with " << compares << " compares.\n";
}

void jumpSearch(const vector<int>& arr, int searchValue) {
    jumpSearchCounter++;
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0, compares = 0;

    while (arr[min(step, n) - 1] < searchValue) {
        compares++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "Jump Search: Not found with " << compares << " compares.\n";
            return;
        }
    }

    while (arr[prev] < searchValue) {
        compares++;
        prev++;
        if (prev == min(step, n)) {
            cout << "Jump Search: Not found with " << compares << " compares.\n";
            return;
        }
    }

    compares++;
    if (arr[prev] == searchValue) {
        cout << "Jump Search: Found at index " << prev << " with " << compares << " compares.\n";
    } else {
        cout << "Jump Search: Not found with " << compares << " compares.\n";
    }
}

void interpolationSearch(const vector<int>& arr, int searchValue) {
    interpolationSearchCounter++;
    int low = 0, high = arr.size() - 1, compares = 0;

    while (low <= high && searchValue >= arr[low] && searchValue <= arr[high]) {
        compares++;
        if (low == high) {
            if (arr[low] == searchValue) {
                cout << "Interpolation Search: Found at index " << low << " with " << compares << " compares.\n";
            } else {
                cout << "Interpolation Search: Not found with " << compares << " compares.\n";
            }
            return;
        }

        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (searchValue - arr[low]));

        compares++;
        if (arr[pos] == searchValue) {
            cout << "Interpolation Search: Found at index " << pos << " with " << compares << " compares.\n";
            return;
        }

        if (arr[pos] < searchValue)
            low = pos + 1;
        else
            high = pos - 1;
    }
    cout << "Interpolation Search: Not found with " << compares << " compares.\n";
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

    cout << "Enter the search value: ";
    cin >> searchValue;

    linearSearch(arr, searchValue);
    sort(arr.begin(), arr.end()); 
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