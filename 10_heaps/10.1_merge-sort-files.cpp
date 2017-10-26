// 10.1_merge-sort-files.cpp
// date: 10/25
// Time Complexity: O(nlogk) // both extract and insert min takes O(logk) time
// Space Complexity: O(k) additional space for the heap
#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
using namespace std;

struct IteratorCurrentAndEnd {
	bool operator>(const IteratorCurrentAndEnd& that) const {
		return *current > *that.current;
	}
	vector<int>::const_iterator current;
	vector<int>::const_iterator end;
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
	priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>, greater<>> min_heap;

	for (const vector<int>& sorted_array : sorted_arrays) {
		if (!sorted_array.empty()) {
			min_heap.emplace(
				IteratorCurrentAndEnd{sorted_array.cbegin(), sorted_array.cend()} );
		}
	}

	vector<int> result;
	while (!min_heap.empty()) {
		auto smallest_array = min_heap.top();
		min_heap.pop();
		if (smallest_array.current != smallest_array.end) {
			result.emplace_back(*smallest_array.current);
			min_heap.emplace(
				IteratorCurrentAndEnd{next(smallest_array.current), smallest_array.end});
		}
	}
	return result;
}

int main() {
	vector<vector<int>> myVector = {{3,5,7}, {0,6}, {0,6,28}};

	auto result = MergeSortedArrays(myVector);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
}
