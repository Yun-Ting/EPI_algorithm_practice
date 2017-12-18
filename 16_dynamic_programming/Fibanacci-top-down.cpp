// Fibanacci-top-down.cpp

unordered_map<int, int> cache;

int Fibonacci(int n) {
	// f(0) = 0, f(1) = 1
	if (n <= 1) return n;
	else if (!cache.count(n)) {
		cache[n] = Fibonacci(n-1) + Fibonacci(n-2);
	}
	return cache[n];
}