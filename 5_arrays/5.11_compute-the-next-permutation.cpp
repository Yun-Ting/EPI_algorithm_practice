// 5.11_compute-the-next-permutation.cpp
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// the key insight is that we want to increase the permutaion
// by as little as possible

// 1. Find k such that p[k] < p[k+1] and entries after index k appear
// in decreasing order 
// 2. Find the smallest p[l] such that p[l] > p[k] (such an l must exist
// since p[k] < p[k+1])
// 3. swap p[l] and p[k] (note that the position k remains in decreasing order)
// 4. Reverse the sequence after position k

vector<int> nextPermutation(vector<int> perm) {
	// Find the first entry from the left that is smaller
	// than the entry immediately after it
	
	// 1.
	auto inversion_point = is_sorted_until(perm.rbegin(), perm.rend());
	if (inversion_point == perm.rend()) { 
		// if the element is all sorted, returns last
		return {};
	}
	// swap the entry referenced by inversion_point that's greater 
	// than the entry referenced by inversion_point. 
	// Since perm must be sorted in decreasing order after inversion_point, 
	// we can use a fast algorithm to find this entry.
	auto least_upper_bound = upper_bound(perm.rbegin(), inversion_point, *inversion_point);
	
	// 2. perform the swap
	iter_swap(inversion_point, least_upper_bound);

	// 3. reverse the subarray that follows inversion_point
	reverse(perm.rbegin(), inversion_point);

	return perm;
}

int main(int argc, char const *argv[])
{
	vector<int> perm = {6,2,1,5,4,3,0};
	vector<int> nextPerm = nextPermutation(perm);
	for (int i = 0; i < nextPerm.size(); ++i) {
		cout << nextPerm[i] << endl;
	}
 	return 0;
}