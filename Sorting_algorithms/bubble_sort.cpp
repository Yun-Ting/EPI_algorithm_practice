// bubble_sort.cpp
#include <vector>
#include <iostream>
using namespace std;

void bubble(vector<int>& A, int left, int right);
void compswap(int& a, int& b);

// non-adaptive-version
void bubble(vector<int>& A, int left, int right) {
	for (int i = left; i < right - 1; ++i) {
		for (unsigned j = right - 1; j > i; --j) {
			compswap(A[j], A[j-1]);
		}
	}
}

void compswap(int& a, int& b) {
	if (a > b) {
		swap(a, b);
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