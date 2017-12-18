class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
        stack<int> pillar_indices;
       	int largestRectangleArea = 0;

       	for(unsigned i = 0; i <= heights.size(); ++i) {
       		while(!pillar_indices.empty() && IsNewPillarOrReachEnd(heights, i, pillar_indices.top())) {
       		    int height = heights[pillar_indices.top()];
       		    pillar_indices.pop();
       		    int width = pillar_indices.empty() ? i : i - pillar_indices.top() - 1;
       		    largestRectangleArea = max(largestRectangleArea, width * height);
       		}
       		pillar_indices.emplace(i);
       	}
       	return largestRectangleArea;
    }

    bool IsNewPillarOrReachEnd(const vector<int>& heights, const int curr_idx, const int last_pillar_idx) {
		return curr_idx < heights.size() ? heights[curr_idx] <= heights[last_pillar_idx] : true;
    }
};