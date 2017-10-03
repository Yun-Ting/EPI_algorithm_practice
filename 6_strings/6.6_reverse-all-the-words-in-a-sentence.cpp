// 6.6_reverse-all-the-words-in-a-sentence.cpp
// 9.20 the power of std!!!!!
// 9.25 cannot pass LeetCode 151 QAQ
// 9.27 Finally passed LeetCode, you can see the code at the bottom
// 		super annoying test cases!!!!

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

// Time: O(n)
// Space: O(1)
void ReverseWords(string& s) {
	// reverse the all string
	reverse(s.begin(), s.end());

	size_t start = 0;
	size_t end;
	while ( (end = s.find(" ", start)) != string::npos){ // 1st iteration: find the first
														 // space in the entire string
		// When pos is specified, the search only includes characters "at or after"!!!! position pos, 
		// ignoring any possible occurrences that include characters before pos.
		reverse(s.begin() + start, s.begin() + end);
		start = end + 1;
	}
	// reverse the last word, (becuase there's no space to identify the last word with the previous while loop)
	reverse(s.begin() + start, s.end());
}

int main() {
	string s1 = "I love puppy";
	string s2 = "a b c d ee f";
	string s3 = " Mr. Q!";
	ReverseWords(s1);
	ReverseWords(s2);
	ReverseWords(s3);
	for (int i = 0; i < s1.size(); ++i) {
		cout << s1[i];
	}
	cout << endl;
	for (int i = 0; i < s2.size(); ++i) {
		cout << s2[i];
	}
	cout << endl;
	for (int i = 0; i < s3.size(); ++i) {
		cout << s3[i];
	}
	cout << endl;
}

////////////////////////////////////////////

class Solution {
public:
    void reverseWords(string &s) {
        // Step1:
        // remove leading and trailing zeroes
        const auto strBegin = s.find_first_not_of(" ");
        if (strBegin == string::npos) {
            s = ""; // no non-whitespace found
            return;
        }
        const auto strEnd = s.find_last_not_of(" ");
        const auto strRange = strEnd - strBegin + 1;
        s = s.substr(strBegin, strRange);
        
        // Step2:
        // remove extra spaces
        auto beginSpace = s.find_first_of(" ");
        while (beginSpace != string::npos) { // while contains extra spaces to be removed        
            const auto endSpace = s.find_first_not_of(" ", beginSpace);
            const auto range = endSpace - beginSpace;
            s.replace(beginSpace, range, " ");
            const auto newStart = beginSpace + 1;
            beginSpace = s.find_first_of(" ", newStart);
        }
        // Step3:       
        // reverse words in-place
        reverse(s.begin(), s.end());
        int start = 0;
        int end = 0;
        while ((end = s.find(" ", start)) != string::npos) { //while there's " " in the position we're interested in
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
        // !!!remember to reverse the last word
        reverse(s.begin() + start, s.end());
    }
};




// Find content in string
// Searches the string for the first occurrence of the sequence specified by its arguments.

// When pos is specified, the search only includes characters at or after position pos, 
// ignoring any possible occurrences that include characters before pos.

// Notice that unlike member find_first_of, whenever more than one character is being searched for, it is not enough that just one of these characters match, but the entire sequence must match.