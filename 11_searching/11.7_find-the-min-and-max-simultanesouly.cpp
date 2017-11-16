#include <vector>
#include <algorithm>
using namespace std;

// Time Comp: O(n)
// Space Comp: O(1)

struct MinMax {
	int smallest, largest;
}

MinMax FindMinMax(const vector<int>& A) {
	if (A.size() <= 1) {
		return {A.front(), A.front()};
	}
	pair<int, int> global_min_max = minmax(A[0], A[1]);
	// Process two elements at a time.
	for (int i = 2; i + 1 < A.size(); i += 2) {
		pair<int, int> local_min_max = minmax(A[i], A[i + 1]);
		global_min_max = { min{global_min_max, local_min_max}, max{global_min_max, local_min_max} };
		// If there is odd number of elements
	}
	// If there is odd number of elements in the array, we still
	// need to compare the last element with the existing answer.
	if (A.size() % 2) {
		global_min_max = { min{global_min_max, local_min_max}, max{global_min_max, local_min_max} };
	}
	return {global_min_max.first, global_min_max.second};
}