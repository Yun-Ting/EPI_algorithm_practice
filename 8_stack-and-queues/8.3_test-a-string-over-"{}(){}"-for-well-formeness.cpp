//8.3_test-a-string-over-"{}(){}"-for-well-formedness.cpp


bool isWellFormed(const string& s) {
	stack<char> left_chars;
	const unordered_map<char, char> kLookup = {
		{'(', ')'}, {'{','}'}, {'[',']'} 
	};

	for (int i = 0; i < s.size(); ++i) {
		if ( kLookup.count(s[i]) ) { // return the number of left chars if found!
			left_chars.emplace(s[i]);
		} else {
			if ( left_chars.empty() || kLookup.at(left_chars.top()) != s[i]) {
									   // A similar member function, unordered_map::at, has the same behavior when an element with the key exists, 
									   // but throws an exception when it does not.
				// unmatched right char or mismatched char
				return false;
			}
			left_chars.pop();
		}
	}
	return left_chars.empty();
}
