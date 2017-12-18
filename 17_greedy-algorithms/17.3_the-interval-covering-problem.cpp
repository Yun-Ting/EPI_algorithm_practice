// 17.3_the-interval-covering-problem.cpp

struct Interval {
	int left, right;
};

int FindMinimumVisits(vector<Interval> intervals) {
	// sort intervals based on the right end points
	sort(intervals.begin(), intervals.end(),
		 [](const Interval& a, const Interval& b) {return a.right < b.right; });
	int last_visit_time = numeric_limits<int>::min(), num_visits = 0;
	for (const Interval& interval : intervals) {
		if (interval.left > last_visit_time) {
			last_visit_time = interval.right;
			++num_visits;
		}
		return num_visits;
	}
}