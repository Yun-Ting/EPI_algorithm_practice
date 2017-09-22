// 6.5_test-palindromicity
// 9/22 the concepts of looping still needs to be improved!

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// considering in using two indexes
// remember to ask the interviewer whether it is case-sensitive!

bool IsPanlindrome(const string &s) {
	int i = 0;
	int j = s.size() - 1;
	while (i < j) {
		while (!isalpha(s[i]) && i < j) {
			++i;
		}
		while (!isalpha(s[j]) && i < j) {
			--j;
		}
		if (tolower(s[i++]) != towlower(s[j--])) 
			return false;
	}
	return true;
}

int main() {
	string s1 = "A man, a plan, a canal, Panama.";
	assert(IsPanlindrome(s1) == true);
	string s2 = "Able was I, ere I saw Elba!";
	assert(IsPanlindrome(s2) == true);
	string s3 = "Ray a Ray.";
	assert(IsPanlindrome(s3) == false);
}