// 5.4_advancing-through-an-array
// 9.18 side note:
// no ideas from the very beginning
// very interesting quesiton
// a little bit of greedy feeling inside it?

// advancing from the first to the last
// need to find combinations that is 
// greater than the size of the arr

bool canReachEnd(const vector<int>& max_advanced_steps) {
	int furthest_reach_so_far = 0;
	int last_idx = max_advanced_steps.size() - 1;
					// we need to be able to walk to i
	for (int i = 0; i <= furthest_reach_so_far && furthest_reach_so_far < last_idx) {

		furthest_reach_so_far = max(furthest_reach_so_far, max_advanced_steps[i] + i);
	}
	return furthest_reach_so_far >= last_idx;
}

// just haven't tested it

