// 6.3_compute-the-spreadsheet-column-encoding.cpp
// date: 9/21
// write some comments to this tomorrow!

#include <iostream>
#include <string>
using namespace std;
int SSDecodeColID(const string& col) {
	int result = 0;
	for (char c : col) {
		result = result * 26 + c - 'A' + 1;
	}
	return result;
}
int main() {
	string s1 = "AA";
	string s2 = "AAA";
	string s3 = "ZC";
	cout << SSDecodeColID(s1) << endl;
	cout << SSDecodeColID(s2) << endl;
	cout << SSDecodeColID(s3) << endl;
}
