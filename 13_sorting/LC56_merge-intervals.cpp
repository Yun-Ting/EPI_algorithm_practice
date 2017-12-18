// LC56_merge-intervals.cpp
// Given a collection of intervals, merge all overlapping intervals.

// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty()) {
        	return {};
        }
        
        for (Interval i : intervals) {
        	if (!result.empty() && i.start <= result.back().end ) {
        		if (i.end > result.back().end) {
        			res.back().end = i.end;
        		}
        	} else {
        		res.emplace_back(i);
        	}
        }
        return res;
    }
};








