// 6.10_compute-all-valid-ip-addresses.cpp
// 9.29 
// LeetCode 93

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<string> GetValidIPAddress(const string& s) {
	vector<string> result;
	for (size_t i = 1; i < 4 && i < s.size(); ++i) { 
		//i < s.size() means we probably will have inputs that the string length < 4
		const string first = s.substr(0, i);
		if (isValid(first)) {
			for (size_t j = 1; j < 4 && i+j < s.size(); ++j) {
				const string second = s.substr(i, j);
				if (isValid(second)) {
					for (size_t k = 1; k < 4 && i+j+k < s.size(); ++k) {
						const string third = s.substr(i+j, k);
						const string fourth = s.substr(i+j+k); // no size parameter
						// we don't need about the length would exploded
						// because the string passed in are gauranteed to be valid!
						if ( isValid(third) && isValid(fourth) ) {
							result.emplace_back(first + "." + second + "." + third + "." + fourth);
						}
					}
				}
			}
		}
	}
}

bool isValid(const string& s) {
	if (s.size() > 3) return false;
	// "00", "001", "000" are not valid, but "0" is valid
	if (s.front() == '0' && s.size() > 1) return false; 
	// s.front() returns a reference to the first character of the string
	int val = stoi(s);
	return val >= 0 && val <= 255;
}