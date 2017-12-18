// Fibonacci-bottom-up.cpp

int Fibonacci(int n) {
	if (n <= 1) return n;
	
	int f_minus_1 = 1;
	int f_minus_2 = 0;
	for (int i = 2; i <= n; ++i) {
		int f = f_minus_1 + f_minus_2;
		f_minus_2 = f_minus_1; // 把不要的最先洗掉! 
		f_minus_1 = f;
	}
	return f_minus_1;
}