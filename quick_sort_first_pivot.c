#include<stdio.h>

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        int temp;

        while(i <= j) {
            while(i <= high && arr[i] <= pivot)
                i++;
            while(arr[j] > pivot)
                j--;
            if(i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        arr[low] = arr[j];
        arr[j] = pivot;

        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n-1);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
