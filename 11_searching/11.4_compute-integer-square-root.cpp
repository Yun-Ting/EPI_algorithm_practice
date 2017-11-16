// 11.4_compute-integer-square-root.cpp
#include <iostream>
using namespace std;

int SquareRoot(int k) {
	int left = 0;
	int right = k;
	while (left <= right) {
		// candidate interval [left, right]
		// where everything before left has
		// square <= k, and everything after right has square > k
		long mid = left + ((right - left) / 2);
		long mid_sq = mid * mid;
		if (mid_sq <= k) {
			left = mid + 1;
		} else {
			right = mid - 1;	
		}
	}
	return left - 1;
}

int main() {
	auto sq20 = SquareRoot(20);
	auto sq100 = SquareRoot(100);
	cout << sq20 << endl;
	cout << sq100 << endl;
}