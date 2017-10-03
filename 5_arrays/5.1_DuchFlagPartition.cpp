#include <iostream>
#include <vector>
using namespace std;
// date: 9/16

void dutchNationalFlag(vector<int>*  A_ptr, int pivotValue) {
	// invariant:
	// bottom: [0, smaller - 1]
	// middle: [smaller, equal - 1]
	// unclassified: [equal, larger - 1]
	// top: [larger, A.size() - 1]

	// [0, 0, 1, 1, 1, ?, ?, 2, 2]
	//        ^        ^     ^
	//        s        e     l
	
	vector<int>& A = *A_ptr; // dereference an vector pointer and create an alias to trace
	int smaller = 0;
	int equal = 0;
	int larger = A.size(); // larger is the element to the right of the question mark

	while (equal < larger) {
		if (A[equal] < pivotValue) {
			swap(A[smaller++], A[equal++]); // swap the current value with the leftmost of the pivot group
		} else if (A[equal] == pivotValue) {
			++equal;
		} else {
			swap(A[equal], A[--larger]); // swap the current value with the right most question mark
		}
	}
}

int main() {
	vector<int> v = {0, 1, 0, 1, 2, 1, 2, 0, 1, 0};
	vector<int>* v_ptr = &v; // pointer stores an address 
	dutchNationalFlag(v_ptr, 1);
	for (int i = 0; i < v.size(); ++i) {
	    cout << v[i] << endl;
	}
}