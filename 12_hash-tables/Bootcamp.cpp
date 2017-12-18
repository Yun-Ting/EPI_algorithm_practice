// Bootcamp.cpp
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

// Given any string, sits sorted version can be used
// as a unique identifier for the anagram group it belongs to

// a map from a sorted string to the anagrams it corresponds to
// anytime you need to store a set of strings, a hash table is an execellent choice


vector<vector<string>> FindAnagrams(const vector<string>& dictionary) {

	unordered_map<string, vector<string>> sorted_string_to_anagrams;
	for (const string& s : dictionary) {
		string sorted_str(s); // strings copy constructor
		sort(sorted_str.begin(), sorted_str.end());
		sorted_string_to_anagrams[sorted_str].emplace_back(s);
	}

	vector<vector<string>> anagram_groups;
	for (const pair<string, vector<string>>& p : sorted_string_to_anagrams) {
		if (p.second.size() >= 2) {
			anagram_groups.emplace_back(p.second);
		}
	}
	return anagram_groups;
}


int main(int argc, char const *argv[]) {
	const vector<string> test_str = {"debitcard", "elvis", "silent", "badcredit", "lives", "freedom", "listen", "levis", "money"};
	vector<vector<string>> result = FindAnagrams(test_str);
	for (auto string_group : result) {
		for (auto s : string_group) {
			cout << s << " ";
		}
		cout << endl;
	}
}
























