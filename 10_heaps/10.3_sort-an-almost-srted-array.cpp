// 10.3_sort-an-almost-sorted-array.cpp
// Time Comp: O(nlogk)
// Space Comp: O(k)
// the brute-force Time Comp: O(nlogn), Space: O(n)
//				        // because stream will disappear if you don't store it

#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

void SortkSortedArray(istringstream* sequence, int k) {
	priority_queue<int, vector<int>, function<bool(int, int)> > 
		min_heap([](const int& a, const int& b) {return a >= b;});

	// Adds the first k elements into the array, 
	// stops if there are fewer than k elements
	int x;
	for (int i = 0; i < k && *sequence >> x; ++i) { 
			// *sequence >> x -> implicitly convert string to int
		min_heap.push(x);
	}

	// for every new element, add it to min_heap and
	// extract the smallest
	while (*sequence >> x) {
		min_heap.push(x);
		cout << min_heap.top() << endl;
		min_heap.pop();
	}

	// sequences is exhausted. 
	// iteratively extracts the remaining elements
	while (!min_heap.empty()) {
		cout << min_heap.top() << endl;
		min_heap.pop();
	}
}

int main() {   			//-1  2 3 4 5 6 8 
	string stringvalues = "3 -1 2 6 4 5 8";
	istringstream iss(stringvalues);
	int a = 2;
	SortkSortedArray(&iss, a);
	return 0;
}