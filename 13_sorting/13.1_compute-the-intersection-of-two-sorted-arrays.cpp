#include <vector>
using namespace std;

vector<int> IntersectionTwoSortedArrays(const vector<int>& A, const vector<int>& B) {
	vector<int> intersection_A_B;
	int i = 0, j = 0;
	while (i < A.size() && j < B.size()) {
		if (A[i] == B[j] && (i == 0 || A[i] != A[i - 1])) {
			intersection_A_B.emplace_back(A[i]);
			++i, ++j;
		} else if (A[i] < B[j]) {
			++i;
		} else {
			++j;
		}
	}
	return intersection_A_B;
}
