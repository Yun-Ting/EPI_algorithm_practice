// 17.7_compute-the-maxiumum-water-trapped-by-a-pair-of-vertical-lines.cpp

int GetMaxTrappedWater(const vector<int>& heights) {
	int i = 0, j = heights.size() - 1, max_water = 0;
	while (i < j) {
		int width = j - i;
		max_water = max(max_water, width * min(heights[i], heights[j]));
		if (heights[i] > heights[j]) {
			--j;
		} else {
			++i;
		}
	}
	return max_water;
}