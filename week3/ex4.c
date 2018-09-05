//
// Created by alexey on 05.09.18.
//

void quicksort(int *, int, int);

int partition(int *, int, int);

int main() {

    int arr[10] = {25, 87, 1, 8, 76, 23, 43, 67, 37, 66};
    quicksort(arr, 0, 9);
    printf("Result is: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}


void quicksort(int arr[], int left, int right) {
    int part;
    if (left < right) {
        part = partition(arr, left, right);
        quicksort(arr, left, part - 1);
        quicksort(arr, part + 1, right);
    }
}

int partition(int *arr, int left, int right) {
    int part, i;
    part = arr[left];
    i = right + 1;

    for (int k = right; k > left; k--) {
        if (arr[k] >= part) {
            i--;
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }

    arr[left] = arr[i - 1];
    arr[i - 1] = part;

    return (i - 1);
}