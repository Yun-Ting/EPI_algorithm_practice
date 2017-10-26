// 10.2_sort-an-increasing-decreasing-array.cpp
// date: 10/25
// reverse and sort
// Time Complexity: O(nlogk)
// Space Complexity: besides storing result, O(k) space

vector<int> SortKIncreasingDecreasingArray(const vector<int>& A) {
	// Decomposes A into a set of sorted arrays
	vector<vector<int>> sorted_subarrays;
	typedef enum {INCREASING, DECREASING} SubarrayType;
	SubarrayType subarray_type = INCREASING;

	int start_idx = 0;
	for (i = 1; i < A.size(); ++i) {
		if (i == A.size() || // A is ended. Adds the last subarray.
			(A[i-1] < A[i] && subarray_type == DECREASING) ||    // turning point
			(A[i-1] >= A[i] && subarray_type == INCREASING)) {   // turning point
			
			if (subarray_type == INCREASING) {
				sorted_subarrays.emplace_back(A.cbegin() + start_idx, A.cbegin() + i);
			} else {
				sorted_subarrays.emplace_back(A.crbegin() + A.size() - i, A.crbegin() + A.size() - start_idx);
			}
			start_idx = i;
			subarray_type = (subarray_type == INCREASING ? DECREASING : INCREASING); 
		}
	}

	return MergeSortedArrays(sorted_subarrays);
}
