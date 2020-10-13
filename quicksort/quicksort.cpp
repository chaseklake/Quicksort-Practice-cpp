#include <vector>
#include <iostream>
//#include <cstdlib> //Not sure if necessary
using namespace std;

//function prototypes
vector<int> createRandomArray(int size);
vector<int> quickSort(vector<int>* arr, int low, int high);
int partition(vector<int>* arr, int low, int high);
void printArray(vector<int> arr);

//MAIN FUNCTION
int main() {
    int vecSize;
    cout << "Enter an array size: ";
    cin >> vecSize;

    vector<int> array = createRandomArray(vecSize);
    cout << "Array:\n";
    printArray(array);

    array = quickSort(&array, 0, vecSize-1);

    cout << "Sorted array:\n";
    printArray(array);

    return 0;
}

// Creates a random array of integers between 0 and 100,000
vector<int> createRandomArray(int size) {
    vector<int> randArray;
    for (int i=0; i < size; i++) {
        randArray.push_back(rand() % 100000);
    }
    return randArray;
}

// An implementation of quicksort on the inserted array
vector<int> quickSort(vector<int>* arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p, high);
    }

    return *arr;
}

// Partition function for quickSort
int partition(vector<int>* arr, int low, int high) {
    int pivot = (*arr).at(high);
    int i = low;
    for (int j = low; j < high; j++) {
        if ((*arr).at(j) < pivot) {
            int temp = (*arr).at(j);
            (*arr).at(j) = (*arr).at(i);
            (*arr).at(i) = temp;
            i++;
        }
    }

    int temp = (*arr).at(high);
    (*arr).at(high) = (*arr).at(i);
    (*arr).at(i) = temp;

    return i;
}

// Prints the vector values to the console from arr[0] to arr[size]
void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size()-1; i++) {
        cout << arr.at(i) << ", ";
    }
    cout << arr.at(arr.size()-1) << endl;
}