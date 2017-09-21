// 5.3_multiply-two-arrays
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> Multiply(vector<int>& v1, vector<int>& v2) {
	
	const int sign = v1.front() > 0 ^ v2.front() > 0 ? -1 : 1; 
	v1.front() = abs(v1.front());
	v2.front() = abs(v2.front());

	vector<int> result(v1.size() + v2.size(), 0);
	int carry = 0;
	for (int i = v2.size() - 1; i >= 0; --i) {
		for (int j = v1.size() - 1; j >= 0; --j) {
			result[i+j+1] += v2[i] * v1[j];
			result[i+j] += result[i+j+1] / 10;
			result[i+j+1] = result[i+j+1] % 10; 
		}
	}

	// remove leading 0s
	result = {find_if_not(begin(result), end(result), [](int a){return a == 0;}),
			  end(result)};
													// Unary function that accepts an element in the range as argument 
			  										// and returns a value convertible to bool. 
			  										// The value returned indicates whether the element is considered a match 
			  										// in the context of this function.
													// The function shall not modify its argument.
													// This can either be a function pointer or a function object.
	result.front() *= sign;
	return result;  
}

int main() {
	vector<int> v1 = {1,0};
	vector<int> v2 = {2,0};
	vector<int> res = Multiply(v1, v2);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << ' ';
	}
}



