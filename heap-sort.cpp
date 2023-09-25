// Heap Sort
#include <iostream>
#include <vector>
using namespace std;

int LEFT(int i);
int RIGHT(int i);
void MaxHeapify(vector<int>& A, int i, int heapSize);
void BuildMaxHeap(vector<int>& A);

int main() {
    vector<int> A = {0, 4, 10, 3, 5, 1};
    int n = A.size() - 1;

    cout << "Original array: ";
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    BuildMaxHeap(A);

    cout << "Max heap: ";
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

int LEFT(int i) {
    return 2 * i;
}

int RIGHT(int i) {
    return 2 * i + 1;
}

void MaxHeapify(vector<int>& A, int i, int heapSize) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;
    if (l <= heapSize && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= heapSize && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(A[i], A[largest]);
        MaxHeapify(A, largest, heapSize);
    }
}

void BuildMaxHeap(vector<int>& A) {
    int heapSize = A.size() - 1;
    for (int i = heapSize / 2; i >= 0; i--) {
        MaxHeapify(A, i, heapSize);
    }
}