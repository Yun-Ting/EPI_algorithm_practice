// 6.7_compute-all-possible-mnemonics-for-a-phone-number
// any such enumeration is best computed using recursion
// The execution path is very similar to that of the brute-force
// approach, but the compiler handles looping

// 9.22 hard to understand =口="
// 9.25 submitted it at Leetcode 17, compile error cannot fix QAQ
// Imagine you are really playing with a combination lock in your hand!

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


// Time comp: O( (4^n) * n)
vector<string> PhoneMnemonics(const string& phone_number) {
	string partial_mnemonic(phone_number.size(), 0);
	vector<string> mnemonics;
	PhoneMnemonicsHelper(phone_number, 0, &partial_mnemonic, &mnemonics);
	return mnemonics;
}

// The mapping from digit to corresponding characters.
const int kNumTelDigits = 10;
const array<string, kNumTelDigits> kMapping = 
								  {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void PhoneMnemonicsHelper(const string& phone_number, int digit, string* partial_mnemonic, vector<string>* mnemonics) {
	if (digit == phone_number.size()) {
		// all digits are processed
		// (We add a copy since subsequent calls modify partial_mnemonic)
		// (how do we want )
		mnemonics->emplace_back(*partial_mnemonic);
	} else {
		// try all possible characters for this digit
		for (char c: kMapping[phone_number[digit] - '0']) { 
			// for example: if the number is '3' 
			// kMapping['3'-'0'] is kMapping[3]
			// this for loop will loop through all characters in "ABC"
			(*partial_mnemonic)[digit] = c;
			PhoneMnemonicsHelper(phone_number, digit + 1, partial_mnemonic, mnemonics);
		}
	}
}























