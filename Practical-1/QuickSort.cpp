#include <iostream>
using namespace std;


int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (arr[start] <= pivot)
            start++;

        while (arr[end] > pivot)
            end--;

        if (start < end)
            swap(arr[start],arr[end]);
    }

    swap(arr[lb], arr[end]);
    return end;
}

void quickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(arr,lb,ub);
        quickSort(arr,lb,loc-1);
        quickSort(arr,loc+1, ub);
    }
}


int main() {
    int arr1[] = {20, 44, 62, 10, 5, 71, 3};

    cout<<"Array before Sorting: ";
    for(int i = 0; i<7; i++){
        cout<<arr1[i]<<" ";
    }
    quickSort(arr1, 0, 6);

    cout<<endl<<"After sorting: ";
    for (int i = 0; i<7; i++) {
        cout << arr1[i] << " ";
    }
    return 0;
}
