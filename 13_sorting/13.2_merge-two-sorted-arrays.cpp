// 13.2_merge-two-sorted-arrays.cpp

void MergeTwoSortedArrays(int A[], int m, int B[], int n) {
	int a = m - 1, b = n - 1, write_idx = m + n - 1;
	while (a >= 0 && b >= 0) {
		A[write_idx--] = A[a] > B[b] ? A[a--] : B[b--];
	}
	while (b >= 0) {
		A[write_idx--] = B[b--];
	}
}