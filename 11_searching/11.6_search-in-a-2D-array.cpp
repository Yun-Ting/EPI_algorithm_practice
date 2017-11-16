// 11.6_search-in-a-2D-array.cpp

bool MatrixSearch(const vector<vector<int>>& A, int x) {
	// start from the top-right corner.
	int row = 0;
	int col = A[0].size() - 1;

	// Keep searching while there are uncalissified rows and columns
	       // not yet bottom, not yet left most col
	while (row < A.size() && col >= 0) {
		if (A[row][col] == x) {
			return true;
		} else if (A[row][col] < x) {
			++row;
		} else { // A[row][col] > x
			--col;
		}
	}
	return false;	
}