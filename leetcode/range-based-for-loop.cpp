// range-based-for-loop.cpp

int main(int argc, char const *argv[]) {
	vector<int> v{ -1, 42, 123, 9000 };
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
		cout << *i << endl;
	}
}