// 13.7_compute-the-union-of-intervals.cpp

struct Interval {
	private:
		struct EndPoint {
			bool is_closed;
			int val;
		};
	public:
		bool operator<(const Interval& i) {
			if (left.val != i.left.val) {
				return left.val < i.left.val;
			}
			return left.is_closed && !i.left.is_closed;
		}
	EndPoint left, right;
};

vector<Interval> UnionOfIntervas(vector<Interval> intervals) {

	if (intervals.empty()) {
		return {};
	}

	// Sort intervals according to left endpoints of intervals.
	sort(intervals.begin(), intervals.end());
	vector<Interval> result;
	for (Interval i : intervals) {

		// 可以更新Union的各種狀況
		// 第一個if: 不但左邊要有overlap, (不但兩者有扯上關係)
		// nested if: 且右邊要比result最後一個index的右界大 (且右界還比較厲害)
		if (!result.empty() && 
			// case 2
			(i.left.val < result.back().right.val || // 有overlap
				// 剛好等於, 但是邊界使他們連起來
				(i.left.val == result.back().right.val && i.left.is_closed || result.back().right.is_closed))) { 
			// case 3
			if (i.right.val > result.back().right.val || i.right.val == result.back().right.val && i.right.is_closed) {
				result.back().right = i.right;
			} 
		// case 1
		} else {
			result.emplace_back(i);
		}
	}
	return result;
}


