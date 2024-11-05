#include <iostream>

using namespace std;

class insertionSort {
private:
    int* Arr;           // Pointer to the array
    int size;           // size of array
    int capacity;       // array extendablity

public:
    // Constructor to initialize array with initial values
    insertionSort(int* A, int n) : size(n), capacity(n + 10) {
        Arr = new int[capacity];
        for (int i = 0; i < n; i++) {
            Arr[i] = A[i];
        }
    }

    // Destructor to release allocated memory
    ~insertionSort() {
        delete[] Arr;
    }

    // Sort function to perform insertion sort
    void sort() {
        for (int i = 1; i < size; ++i) {
            int key = Arr[i];
            int j = i - 1;
            while (j >= 0 && Arr[j] > key) {
                Arr[j + 1] = Arr[j];
                --j;
            }
            Arr[j + 1] = key;
        }
    }

    // Function to add a new element to the array
    void add(int x) {
        if (size >= capacity) {
            // Resize the array if needed
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < size; i++) {
                newArr[i] = Arr[i];
            }
            delete[] Arr;
            Arr = newArr;
        }
        Arr[size++] = x;
    }

    // Function to remove an element by its 1-based position
    void remove(int place = 1) {
        if (place > 0 && place <= size) {
            for (int i = place - 1; i < size - 1; ++i) {
                Arr[i] = Arr[i + 1];
            }
            --size;
        }
    }
    
    // Function to remove an element by its value and occurence
    void removeDu(int x, int place = 1) {
      bool found = false;
      for (int i = 0; i < size; i++) {
        if (Arr[i] == x) {
            if (place == 1) {  // Match found and correct place
                found = true;
                for (int j = i; j < size - 1; j++) {
                    Arr[j] = Arr[j + 1];  // Shift elements
                }
                --size;  // Decrement size after removal
                break;
            } else {
                --place;  // Decrement place if it's not the right occurrence
            }
        }
    }
    if (!found) {
        cout << "Element was not in Arr" << endl;
    }
}


    // Function to print the array
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << Arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int initialArr[] = {1, 2, 2, 2, 2, 3, 4};
    int n = sizeof(initialArr) / sizeof(initialArr[0]);
    
    insertionSort insert(initialArr, n);
    
    // Add and remove elements
    insert.add(5);
    insert.remove(2);
    insert.removeDu(2,2);

    // Sort and print the sorted array
    insert.sort();
    insert.print();

    return 0;
}
