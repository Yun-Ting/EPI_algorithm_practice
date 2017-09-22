// 6.1_interconvert-string-and-integers
// date: 9/21
#include <string>
#include <iostream>
using namespace std;


string IntToString(int &x) {
	bool is_negative = false;
	if (x < 0) {
		is_negative = true;
	}
	string s;
	do { // even x is 0, 
		 // we need to do the
		 // conversion once
		s += '0' + abs(x % 10);
		x /= 10;
	} while ( x != 0);

	if (is_negative) {
		s += '-';
	}
	return {s.rbegin(), s.rend()};
}

int StringToInt(string &s) {
	int result = 0;
	for (int i = s[0] == '-' ? 1 : 0; i < s.size(); ++i) {
		const int digit = s[i] - '0';
		result = result * 10 + digit;
	}
	return s[0] == '-' ? -result : result;
}

int main() {
	int x = 3421;
	int y = -293;
	cout << "int to string: " << IntToString(x) << endl;
	cout << "int to string: " << IntToString(y) << endl;

	string a = "1930";
	string b = "-24510";
	cout << "string to int: " << StringToInt(a) << endl;
	cout << "string to int: " << StringToInt(b) << endl;
}
