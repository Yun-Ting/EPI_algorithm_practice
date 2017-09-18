// 5.2_plus-one
// date: 9/16
#include <vector>
#include <iostream>
using namespace std;

// the brute-force way is to convert
// the array to an integer, plus-one
// and return again as an array
// but this cannot take care of the 
// overflow issue

vector<int> plusOne(vector<int> &A) {
	// vector.back() returns the reference 
	// to the last element of a vector
	A.back() = A.back() + 1; 
	
	// take care of the carry
	for (int i = A.size() - 1; i > 0 && A[i] == 10; --i) { 
		A[i] = 0;
		++A[i-1];
	}

	if (A[0] == 10) {
		// need additional storage as the most significant value
		// has carry-out
		A[0] = 0;
		A.insert(A.begin(), 1); 
		// see documentation I pasted
		// at the bottom of this file
	}
	return A;
}

void myPrint(const vector<int> &A) {
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << ' ';
	}
	cout << '\n';
}

int main() {
	vector<int> v1 = {1,2,9};
	vector<int> v2 = {9,9,9};
	vector<int> v3 = {1,3,0,2,9,1,3,2,1,6,5};
	vector<int> v4 = {8,9,9};

	plusOne(v1); // do not need & right here, because it's not reference declaration
	// when not in declaration, & means take the address
	plusOne(v2);
	plusOne(v3);
	plusOne(v4);
	myPrint(v1);
	myPrint(v2);
	myPrint(v3);
	myPrint(v4);
}

// vector.insert() documentation
// single element (1)	
// iterator insert (const_iterator position, const value_type& val);
// fill (2)	
// iterator insert (const_iterator position, size_type n, const value_type& val);
// range (3)	
// template <class InputIterator>
// iterator insert (const_iterator position, InputIterator first, InputIterator last);
// move (4)	
// iterator insert (const_iterator position, value_type&& val);
// initializer list (5)	
// iterator insert (const_iterator position, initializer_list<value_type> il);