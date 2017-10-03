#include <iostream>
#include <algorithm>
using namespace std;
// date: 9/15

// invariant: all the elements to the left of the pIndex
// will be less than the pivot
// all the elements to the right of the pIndex (including the pIndex itself)
// will be larger than the pivot

// <1, 3, 5, ?, ? 4(pivot)>
//        ^ 
//        PI      
int Partition(int* A, int start, int end){
    int &pivot = A[end];
    //use reference to trace it
    int pIndex = start;
    // pIndex is the first element that's greater than the pivot 
    for (int i = start; i < end; ++i) {
        if (A[i] <= pivot) { // note for the smaller equal than here
            swap(A[i], A[pIndex]);
            ++pIndex;
        }
    }
    swap(A[pIndex], pivot); 
    // pivot is a reference of end, we can swap
    // to change the value of the array
    return pIndex;
}

void quickSort(int *A, int start, int end){
    if (start < end) {
        int pIndex = Partition(A, start, end);
        quickSort(A, start, pIndex-1);
        quickSort(A, pIndex+1, end);
    }
}

int main()
{
    int A[]= {3,2,1,5,4};
    quickSort(A, 0, 4);
    for (int i = 0; i < 5; ++i) {
        cout << A[i] << endl;
    }
}
