// bubble_sort-adaptive.cpp

#include <vector>
#include <iostream>
using namespace std;

void bubble(vector<int>& A, int left, int right);


// non-adaptive-version
void bubble(vector<int>& A, int left, int right) {
	for (int i = left; i < right - 1; ++i) {
		bool swapped = false;
		for (unsigned j = right - 1; j > i; --j) {
			if (A[j] < A[j-1]) {
				swapped = true;
				swap(A[j], A[j-1]);
			}
		}
		// 如果這個pass這麼右邊已經sorted, 
		// 在左邊就肯定也sorted了
		if (!swapped) break; 
	}
}


int main(int argc, char const *argv[])
{
	vector<int> v = {4,2,5,1,3};
	bubble(v, 0, v.size());
	for(int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}

	return 0;
}