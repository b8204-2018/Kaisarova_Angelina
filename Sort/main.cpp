#include <iostream>
#include <string.h>

using namespace std;

class Sorts {
public:
    virtual void Sort(int *arr, int size) = 0;
};

class Shell : public Sorts {
public:
    void Sort(int *arr, int size) override {
        int step = size / 2;
        while (step > 0) {
            for (int i = 0; i < (size - step); i++) {
                int j = i;
                while (j >= 0 && arr[j] > arr[j + step]) {
                    swap(arr[j], arr[j + step]);
                    j--;
                }
            }
            step = step / 2;
        }
    }
};

void PrintSortedArray(Sorts &sort, int *arr, int size){
    int *res = new int[size];
    memcpy(res, arr, size * sizeof(int));
    sort.Sort(res, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << " " << res[i];
    }
}

void PrintArray(int *arr, int size){
    cout << "Your array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int size;
    cout << "Number of elements ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size + 1;
    }
    Shell sortShell;
    PrintArray(arr, size);
    PrintSortedArray(sortShell, arr, size);

    return 0;
}

