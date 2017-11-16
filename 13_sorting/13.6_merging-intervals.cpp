// 13.6_merging-intervals.cpp

struct Interval {
	int left, right;
};

vector<Interval> AddInterval(const vector<Interval>& disjoint_intervals, vector<Interval> new_interval) {
	size_t i = 0;
	vector<Interval> result;

	while ( i < disjoint_intervals.size() && disjoint_intervals[i].right < new_interval.left) {
		result.emplace_back(disjoint_intervals[i++]);
	}

	while( i < disjoint_intervals.size() && disjoint_intervals[i].left <= new_interval.right) {
	    // if (a, b) and (c, d) is overlap, 
	    // there union is min(a, c), max(b, d)
	    new_interval = Interval{min(disjoint_intervals[i].left, new_interval.left), max(disjoint_intervals[i].right, new_interval.right)};
	    ++i;
	}

	result.emplace_back(new_interval);

	result.insert(result.end(), disjoint_intervals.begin() + i, disjoint_intervals.end());

	return result;
}