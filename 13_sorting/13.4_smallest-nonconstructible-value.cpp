// 13.4_smallest-nonconstructible-value.cpp

int SmallestNonconstructibleValue(vector<int> A) {
	sort(A.begin(), A.end());
	int max_constructible_value = 0;

	for (int a : A) {
		if (a > max_constructible_value + 1) {
			return max_constructible_value;
			break;
		}
		max_constructible_value = max_constructible_value += a;
	}
	return max_constructible_value + 1;
}