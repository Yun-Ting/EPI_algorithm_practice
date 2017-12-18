// 17.8_compute-the-largest-rectangle-under-skyline.cpp

int CalculateLargestRectangle(const vector<int>& heights) {
	stack<int> pillar_indices;
	int max_rectangle_area = 0;

	for(unsigned i = 0; i <= heights.size(); ++i) {
		while(!pillar_indices.empty() &&
			  IsNewPillarOrReachEnd(heights, i, pillar_indices.top())) {
		    int height = heights[pillar_indices.top()];
			pillar_indices.pop();
			int width = pillar_indices.empty()  i : i - pillar_indices.top() - 1;
			max_rectangle_area = max(max_rectangle_area, height * width);
		}
		pillar_indices.emplace(i);
	}
	return max_rectangle_area;
}

bool IsNewPillarOrReachEnd(const vetor<int>& heights, int curr_idx, int last_pillar_idx) {
	return curr_idx < heights.size() ? heights[curr_idx] <= heights[last_pillar_idx] : true;
}