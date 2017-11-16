// 11.8_find-the-Kth-largest-element.cpp
#include <vector>
#include <iostream>
#include <random>
using namespace std;

// The numbering starts from one, i.e.
// if A = [3, 1, -1, 2] then
// FindKthLargest(1, A) returns 3, FindKthLargest(2, A) returns 2,
// FindKthLargest(3, A) returns 1, and FindKthLargest(4, A) returns -1

class AGreaterthanB {
public:
	bool operator()(const int& a, const int& b) {
		return a > b;
	}	
};

template <typename Compare>
int FindKth(int k, Compare comp, vector<int>& A) {
	int left = 0;
	int right = A.size() - 1;
	while (left <= right) {
		int pivot_idx = left + ((right - left) / 2);
		int new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, comp, A);
		if (new_pivot_idx == k -1) {
			return A[new_pivot_idx];
		} else if (new_pivot_idx > k - 1) {
			right = new_pivot_idx - 1;
		} else {
			left = new_pivot_idx + 1;
		}
	}
}

template <typename Compare>
int PartitionAroundPivot(int left, int right, int pivot_idx, Compare comp, vector<int>& A) {
	int pivot_value = A[pivot_idx];
	int new_pivot_idx = left;
	swap(A[pivot_idx], A[right]);
	for (int i = left; i < right; ++i) {
		if (comp(A[i], pivot_value)) {
			swap(A[i], A[new_pivot_idx++]);
		}
	}
	swap(A[new_pivot_idx], A[right]);
	return new_pivot_idx;
}

int main() {
	vector<int> v = {-1, 3, 4, 2, 9, 11};
	cout << FindKth(3, AGreaterthanB(), v) << endl;
}