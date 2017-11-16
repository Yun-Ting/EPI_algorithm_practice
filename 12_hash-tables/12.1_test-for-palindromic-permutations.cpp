// 12.1_test-for-palindromic-permutations.cpp

bool canFormPanlindrome(const string& s) {
	unordered_map<char> chars_with_odd_freq;
	for (char c : s) {
		if (chars_with_odd_freq.count(c) != 0) {
			chars_with_odd_freq.erase(c);
		} else {
			chars_with_odd_freq.insert(c);
		}
	}
	return chars_with_odd_freq.size() <= 1;
}