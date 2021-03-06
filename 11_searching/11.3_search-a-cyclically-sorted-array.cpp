// 11.3_search-a-cyclically-sorted-array-with.cpp
#include <iostream>
#include <vector>
using namespace std;

int SearchSmallest(const vector<int>& A) {
	int left = 0;
	int right = A.size() - 1;
	while (left <= right) {
		int mid = left + ((right-left) / 2);
		if (A[mid] > right) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
		return mid;
	}
}

int main() {
	vector<int> v = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
	auto answer = SearchSmallest(v);
	cout << answer << endl;
}