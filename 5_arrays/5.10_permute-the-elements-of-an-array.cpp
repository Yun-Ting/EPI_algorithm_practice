// 5.10_permute-the-elements-of-an-array.cpp

#include <vector>
#include <iostream>
using namespace std;

// I think we just need a for loop to do this, 
// than why use another while loop???
void ApplyPermutation(vector<int>& perm, vector<int>& A) {
	for (int i = 0; i < A.size(); ++i) {
		// Check if the element at index i has not been moved
		// by checking if perm[i] is nonnegative.
		int next = i;
		while (perm[next] >= 0) {
			swap(A[i], A[perm[next]]);
			int temp = perm[next];
			// substracts perm.size() from an entry in perm to make it negative
			// which indicates the corresponding move has been performed.
			perm[next] -= perm.size();
			next = temp;
		}
	}
	// Restore perm (add the previously substracted size back)
	for_each(begin(perm), end(perm), [&perm](int& x) {x += perm.size(); });
}

int main(int argc, char const *argv[])
{
	vector<int> perm = {2, 0, 1, 3};
	vector<int> A = {1, 2, 3, 4};
	ApplyPermutation(perm, A);
	for (int i = 0; i < perm.size(); ++i) {
		cout << perm[i] << endl;
	}
}
