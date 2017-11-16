// Bootcamp.cpp

vector<vector<string>> FindAnagrams(const vector<string>& dictionary) {
	unordered_map<string, vector<string>> sorted_string_to_anagrams;
	for (const string& s : dictionary) {
		// Sorts the string, uses it as a key, 
		// and append the original string as another value into the hash table.
		string sorted_str(s); // string ctor
		sort(sorted_str.begin(), sorted_str.end()); // sort takes two iterators
		sorted_string_to_anagrams[sorted_str].emplace_back(s);
	}

	vector<vector<string>> anagram_groups;
	// p is a pair with sorted_str as key (first), and original string(s) as values
	for (const auto& p : sorted_string_to_anagrams) { 
		if (p.second.size() > 2) {
			anagram_groups.emplace_back(p.second);
		}
	}
	return anagram_groups;
}
