// 5.5_delete-duplicates-from-a-sorted-array.cpp
// date: 9/20
// can think out the concept, but cannot convert
// the concept to compilable code QAQ, the idx
// problems are excruciating
#include <vector>
#include <iostream>
using namespace std;

// Time: O(n)
// Space: O(1)
//    1, 2, 2, 3, 5
//idx 0, 1, 2, 3, 4
//wri    1 
int DeleteDuplicates(vector<int> &v) {
	if (v.empty()) return 0;
	int writeIdx = 1; 
	// set to one, because we need the left
	// element of writeIdx
	for (int i = 1; i < v.size(); ++i) {
		if (v[writeIdx - 1] != v[i]) { 
		// so before there are any duplicates
		// the difference between writeIdx and i 
		// will be one
		// the difference increases as number of duplicates
		// increase
			v[writeIdx++] = v[i];
		}
	}
	return writeIdx;
}

int main() {
	vector<int> v1 = {1,2,2,3,5,5,7,8,9,9,9};
	int writeIdx = DeleteDuplicates(v1);
	for (int i = 0; i < writeIdx; ++i) {
		cout << v1[i] << " ";
	}
}