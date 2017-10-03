// 6.9_convert-from-roman-to-decimal.cpp
// 9.28 Why right to left???
// 		since for exceptions, we calculate the value of the pair
// 		by substract s[left] values from s[right]
// 		therefore, it would be more convenient to 
// 		start from the right because of the nature of exception pair computation! 
// LeetCode 13
// we can suppose the input is valid

#include <iostream>
#include <unordered_map>
using namespace std;

int RomanToInteger(const string& s) {
	unordered_map<char, int> T = {
	 {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},{'C', 100}, {'D', 500}, {'M', 1000}};

	 int sum = T[s.back()];
	 for (int i = s.size() - 2; i >=0; --i) {
	 	if (T[s[i]] < T[s[i+1]]) {
	 		sum -= T[s[i]];
	 	} else {
	 		sum += T[s[i]];
	 	}
	 }
	 return sum;
}

int main() {
	string s1 = "XXXXXIIIII";
	string s2 = "LVIIII";
	string s3 = "LIX";
	cout << RomanToInteger(s1) << endl;
	cout << RomanToInteger(s2) << endl;
	cout << RomanToInteger(s2) << endl;

}