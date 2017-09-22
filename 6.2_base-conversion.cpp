#include <iostream>
#include <string>
using namespace std;
// 9.21 學了好久快死掉了QAQ

string ConvertBase(const string& num_as_string, int b1, int b2);
string ConstructFromBase(int num_as_int, int base);

string ConvertBase(const string& num_as_string, int b1, int b2) {
	bool is_negative = num_as_string.front() == '-';
	int num_as_int = 0;
	for (int i = is_negative ? 1 : 0; i < num_as_string.size(); ++i) {
		num_as_int *= b1;
		num_as_int += isdigit(num_as_string[i])? num_as_string[i] - '0':
		num_as_string[i] - 'A' + 10;
	}
	return (is_negative ? "-" : "") + // we can have empty string, but not empty char!
		   (num_as_int == 0 ? "0" : ConstructFromBase(num_as_int, b2)); 
}    
    
string ConstructFromBase(int num_as_int, int b2) { // int to string
	return num_as_int == 0 ? "" : ConstructFromBase(num_as_int / b2, b2) + 
		   (char)(num_as_int % b2 >= 10 ? 'A' + num_as_int % b2 - 10 :
		    '0' + num_as_int % b2); 
}

int main()
{	
	string s = "615";
	int a = 7;
	int b = 13; 
	cout << ConvertBase(s, a, b) << endl;   
}
