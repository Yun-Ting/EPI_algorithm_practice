// 18.7_transform-one-string-to-another.cpp

// Uses BFS to find the least steps of transformtaion
int Transforming(unordered_set<string> D, const string& s, const string& t) {
	struct StringWithDistance {
		string candidate_string;
		int distance;
	};

	queue<StringWithDistance> q;
	D.erase(s);
	q.emplace(StringWithDistance{s, 0});

	while (!q.empty()) {
		StringWithDistance f(q.front());
		// Returns if we find a match.
		if (f.candidate_string == t) {
			return f.distance;   // # of steps
		}

		// Tries all possible transformations of f.candidate_string
		string str = f.candidate_string;
		for (int i = 0; i < str.size(); ++i) {
			for (int c = 0; c < 26; ++c) { // Iterates through 'a' ~ 'z'
				str[i] = 'a' + c;
				auto it(D.find(str));
				if (it != D.end()) {
					D.erase(it);
					q.emplace(StringWithDistance{str, f.distance + 1});
				}
			}
			str[i] = f.candidate_string[i]; // reverts the change of str.
		}
		q.pop();
	}
	return -1; // cannot find possible transformtions
}