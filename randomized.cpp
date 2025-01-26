//randomized quick
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int steps = 0;
 
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    steps++;
}

int partition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    steps++;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
        steps++;
    }

    swap(arr[i + 1], arr[high]);
    steps++;

    return i + 1;
}

void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        steps++;
        int pi = partition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
        steps++;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        steps++;
    }
    cout << endl;
}

int main() {
    srand(time(0));//By calling srand(time(0));, the random numbers generated by rand() will vary across different executions of the program, making them appear more random.

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    randomizedQuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    cout << "\nTotal number of steps: " << steps << endl;

    return 0;
}
