// 11.1_sorted-array-for-first-occurrence-of-k.cpp
// Time Complexity: O(logn)

int SearchFirstOfK(const vector<int>& A, int k) {
	int left = 0;
	int right = A.size() - 1;
	int result = -1;
	// A[left, right] is the candidate set.
	while (left <= right) {
		int mid = left + ((right -left) / 2);
		if (A[mid] > k) {
			right = mid - 1;
		} else if (A[mid] == k) {
			result = mid;
			// Nothing to the right of mid can be the first occurrence of k.
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return result;
}