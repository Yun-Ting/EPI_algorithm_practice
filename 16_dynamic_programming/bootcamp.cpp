// bootcamp.cpp

int FindMaxSubarray(const vector<int>& A) {
	int min_sum = 0, running_sum = 0, max_sum = 0;
	for (int i = 0; i < A.size(); ++i) {
		running_sum += A[i];
		min_sum = min(min_sum, running_sum - min_sum);
		max_sum = max(max_sum, running_sum - min_sum);
	}
	return max_sum;
}