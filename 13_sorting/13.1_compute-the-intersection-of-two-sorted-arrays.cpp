#include <vector>
using namespace std;

// vector<int> IntersectionTwoSortedArrays(const vector<int>& A, const vector<int>& B) {
// 	vector<int> intersection_A_B;
// 	int i = 0, j = 0;
// 	while (i < A.size() && j < B.size()) {
// 		if (A[i] == B[j] && (i == 0 || A[i] != A[i - 1])) {
// 			intersection_A_B.emplace_back(A[i]);
// 			++i, ++j;
// 		} else if (A[i] < B[j]) {
// 			++i;
// 		} else {
// 			++j;
// 		}
// 	}
// 	return intersection_A_B;
// }




















// brute-force
vector<int> IntersectionTwoSortedArrays(const vector<int>& A, const vector<int>& B) {
	vector<int> intersection_A_B;

	for(unsigned i = 0; i < A.size(); ++i) {
		if (A[i] != A[i-1] && find(begin(B), end(B), A[i]) != end(B)) {
			intersection_A_B.emplace_back(A[i]);
		}
	}
	return intersection_A_B;
} 

// sol2
vector<int> IntersectionTwoSortedArrays(const vector<int>& A, const vector<int>& B) {
	vector<int> intersection_A_B;

	for(unsigned i = 0; i < A.size(); ++i) {
		if (i == 0 || A[i] != A[i - 1] && binary_search(B.begin(), B.end(), A[i])) // binary_search return true or false
			intersection_A_B.emplace_back(A[i]);
		}
	return intersection_A_B;
}

// sol3
vector<int> IntersectionTwoSortedArrays(const vector<int>& A, const vector<int>& B) {
	vector<int> intersection_A_B;

	int i = 0, j = 0;
	while(i < A.size() && j < B.size) {
		if(A[i] == B[j] && A[i] != A[i - 1]) {
			intersection_A_B.emplace_back(A[i]);
			++i;
			++j;
		}
		else if(A[i] > B[j]) {
			++j;
		}
		else {
			++i;
		}
	}
	return intersection_A_B;
}	

















