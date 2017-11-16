// string_hash.cpp

int stringHash(const string& s, int modulus) {
	const int kMult = 997;
	int val = 0;
	for (char c : s) {
		val = (val * kMult + c) % modulus;
	}
	return val;
}