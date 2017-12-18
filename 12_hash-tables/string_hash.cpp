// string_hash.cpp
// 11.29看第二次

// 1. the hash function should examine al the characters in the string
// 2. give a large range of values, and should not let one character dominate
// 3. rolling hash function: if a char is deleted from the front of the string, and another add to the end, 
// it sould compute in O(1) time
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

// int stringHash(const string& s, int modulus) {
// 	const int kMult = 997;
// 	int val = 0;

int stringHash(const string& s, int modulus) {
	const int kMult = 997;
	int val = 0;

	for (char c : s) {
		val = (val * kMult + c) % modulus;
	}
	return val;
}

int main(int argc, char const *argv[]) {
	string s = "veryverycutegaga";
	cout << stringHash(s, 100) << endl; 
}

