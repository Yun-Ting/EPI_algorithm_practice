// heaps_boot_camp.cpp
// date: 10/25
// Time Complexity: O(klogn)
// Space Complexity: O(k)

#include <queue>
#include <vector>
#include <sstream>    // string
#include <string>     // istringstream
#include <iostream>   // cout
using namespace std;


vector<string> TopK(int k , istringstream* stream) {
	priority_queue<string, vector<string>, function<bool(string, string)>> 
		min_heap([](const string& a, const string& b) { return a.size() >= b.size(); } );
	
	string next_string;
	while (*stream >> next_string) { // next_string is a string buffer for the istringstream 
		// we can customize delimeter using getline(*stream, 'delimiter')!
		min_heap.emplace(next_string);
		if (min_heap.size() > k) {
			// Remove the shortest string. Note that the comparison function above
			// will order the strings by length.
			min_heap.pop();
		}
	}
	vector<string> result;
	while (!min_heap.empty()) {
		result.emplace_back(min_heap.top());
		min_heap.pop();
	}
	return result;
}

int main() {
	string stringvalues = "12345 1234 123 123456 123 12 1 1234567";
	istringstream iss(stringvalues);
	cout << iss.str() << endl;

	auto result = TopK(4, &iss);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
}
