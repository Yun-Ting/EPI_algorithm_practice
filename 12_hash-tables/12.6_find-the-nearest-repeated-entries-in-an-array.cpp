// 12.6_find-the-nearest-repeated-entries-in-an-array.cpp

int FindNearestRepetition(const vector<string>& paragraph) {
	unordered_map<string, int> word_to_latest_idx;
	int neareast_repeated_distance = numeric_limits<int>::max();
	for (int i = 0; i < paragraph.size(); ++i) {
		auto latest_equal_word = word_to_latest_idx.find(paragraph[i]);
		if (latest_equal_word != word_to_latest_idx.end()) {
			neareast_repeated_distance = min(neareast_repeated_distance, i - latest_equal_word->second);

		}
		word_to_latest_idx[paragraph[i]] = i;
	}
	return neareast_repeated_distance;
}