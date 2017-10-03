// 5.9_enmerate-all-primes-to-n.cpp
// 10.2 
// LeetCode 204 - do the leetcode this afternoon please!

#include <vector>
#include <iostream>
#include <deque>
using namespace std;

// the sieving out method is jaw-dropping smart method
// Time Complexity: O(2/n + 3/n + 5/n +...+) -> O(nloglogn)
// Space Complexity: O(n)

vector<int> GeneratePrimes(int n) {
	vector<int> primes;
	deque<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;

	for (int p = 2; p < n; ++p) {
		if(is_prime[p]){
			primes.emplace_back(p);
		}
		for (int i = p; i <= n; i += p) {
			is_prime[i] = false;
		}
	}
	return primes;
}

int main() {
	 int n = 10;
	 vector<int> primes = GeneratePrimes(n);
	 for (int i = 0; i < primes.size(); ++i) {
	 	cout << primes[i] << endl;
	 }
}