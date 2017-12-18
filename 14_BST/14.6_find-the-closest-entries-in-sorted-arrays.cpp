// 14.6_find-the-closest-entries-in-sorted-arrays.cpp

int FindCLosestElementsInSortedArrays(const vector<vector<int>>& sorted_arrays) {
	int min_distance_so_far = numeric_limits<int>::max();

	struct IterTail {
		vector<int>::const_iterator iter;
		vector<int>::const_iterator tail;
	};

	multimap<int, IterTail> iter_and_tail;
	// typedef pair<const Key, T> value_type;

	for (const vector<int>& sorted_array : sorted_arrays) {
		iter_and_tail.emplace( sorted_array.front(), IterTail{sorted_array.cbegin(), sorted_array.cend()} );
	}

	while (true) {
	    int min_value = iter_and_tail.cbegin()->first,
			max_value = iter_and_tail.crbegin()->first;
		min_distance_so_far = min(min_distance_so_far, max_value - min_value);
		const auto next_min = next(iter_and_tail.cbegin()->second.iter),
				   next_end = iter_and_tail.cbegin()->second.tail;


		// Return if some array has no remaining elements
		if (next_min == next_end) {
			return min_distance_so_far;
		}
		iter_and_tail.emplace(*next_min, IterTail{next_min, next_end});
		iter_and_tail.erase(iter_and_tail.cbegin());
	}
}