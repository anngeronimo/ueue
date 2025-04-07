#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            comparisons++; 
            if (arr[j] > arr[j+1]) {
                swaps++; 
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertionSort(vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;      
        comparisons++; 
        while (j >= 0 && arr[j] > key) {
            comparisons++; 
            swaps++; 
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++; 
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swaps++; 
            swap(arr[i], arr[minIndex]);
        }
    }
}

void merge(vector<int>& arr, int left, int right, int& comparisons, int& swaps) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;  
    merge(arr, left, mid, comparisons, swaps); 
    merge(arr, mid + 1, right, comparisons, swaps); 
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;   
    while (i <= mid && j <= right) {
        comparisons++; 
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }   
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }    
    for (int i = 0; i < temp.size(); i++) {
        swaps++; 
        arr[left + i] = temp[i];
    }
}

void mergeSort(vector<int>& arr, int left, int right, int& comparisons, int& swaps) {
    merge(arr, left, right, comparisons, swaps);
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    vector<int> arr(N);
    cout << "Enter the elements: \n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }  
    
    vector<int> arr_copy = arr;
    int comparisons = 0, swaps = 0;

    vector<int> bubbleArr = arr;
    comparisons = swaps = 0;
    bubbleSort(bubbleArr, comparisons, swaps);
    cout << "\nBubble Sort:\n";
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) cout << bubbleArr[i] << " ";
    cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << endl;

    vector<int> insertionArr = arr;
    comparisons = swaps = 0;
    insertionSort(insertionArr, comparisons, swaps);
    cout << "\nInsertion Sort:\n";
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) cout << insertionArr[i] << " ";
    cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << endl;

    vector<int> selectionArr = arr;
    comparisons = swaps = 0;
    selectionSort(selectionArr, comparisons, swaps);
    cout << "\nSelection Sort:\n";
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) cout << selectionArr[i] << " ";
    cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << endl;

    vector<int> mergeArr = arr;
    comparisons = swaps = 0;
    mergeSort(mergeArr, 0, N - 1, comparisons, swaps);
    cout << "\nMerge Sort:\n";
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) cout << mergeArr[i] << " ";
    cout << "\nComparisons: " << comparisons << "\nSwaps: " << swaps << endl;

    return 0;
}
