#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void BubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int Partition(int* arr, int start, int end) {
    int p = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++)
        if (arr[i] <= p)
            count++;

    int p_i = start + count;
    swap(arr[start], arr[p_i]);

    int i = start, j = end;
    while (i < p_i && j > p_i) {
        while (arr[i] <= p)
            i++;
        while (arr[j] > p)
            j--;
        if (i < p_i && j > p_i)
            swap(arr[i++], arr[j--]);
    }
    return p_i;
}

void QuickSort(int* arr, int start, int end) {
    if (start >= end)
        return;

    int p = Partition(arr, start, end);
    QuickSort(arr, start, p - 1);
    QuickSort(arr, p + 1, end);
}

void Merge(int* arr, int start, int end, int mid) {
    vector<int> temp(end - start + 1);
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];

    for (int i = 0; i < k; i++)
        arr[start + i] = temp[i];
}

void MergeSort(int* arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, end, mid);
    }
}

void main() {
    int arr[] = { 5, 6, 1, 3, 7, 9, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    //BubbleSort(arr, n);
    //QuickSort(arr, 0, n - 1);
    MergeSort(arr, 0, n - 1);

    cout << "After Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

}
