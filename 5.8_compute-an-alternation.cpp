// 5.8_compute-an-alternation.cpp
// date: 9/20
#include <vector>
#include <iostream>
using namespace std;

// algorithm design by iterative refinement
// of a brute-force solution
void Rearrange(vector<int> &A) {
	for (int i = 1; i < A.size(); ++i) {
		if ( (!(i % 2) && A[i-1] < A[i]) || ((i%2) && A[i-1] > A[i]) ) {
			swap(A[i], A[i+1]);
		}
	} 
}

int main() {
	vector<int> v = {1,2,3,4,5};
	Rearrange(v);
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}
}