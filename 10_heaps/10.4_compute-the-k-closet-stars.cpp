// 10.4_compute-the-k-closet-stars.cpp
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <array>
using namespace std;



struct Star {
	bool operator<(const Star& that) const {
		return Distance() < that.Distance();
	}
	double Distance() const { return sqrt(x * x + y * y + z * z); }
	double x, y, z;
};

vector<Star> FindClosestKStars(int k, istringstream* stars) {
	// max_heap to store the closet k stars seen so far.
	priority_queue<Star, vector<Star>> max_heap;

	string line;
	while (getline(*stars, line)) {
		stringstream line_stream(line);
		array<double, 3> data; // stores x, y, and z
		for (int i = 0; i < 3; ++i) {
			string buf;
			getline(line_stream, buf, ',');
			data[i] = stod(buf);
		}
		
		// Add each star to the max-heap. If the max-heap size exceeds k,
		// remove the max elemnt from the max-heap
		max_heap.emplace( Star{data[0], data[1], data[2]} );
		if (max_heap.size() == k + 1) {
			max_heap.pop();
		}
	}

	// Iteratively extract from the max-heap, which yields the stars
	// sorted according from furthest to closet.
	vector<Star> closet_stars;
	while (!max_heap.empty()) {
		closet_stars.emplace_back(max_heap.top());
		max_heap.pop();
	}
	return { closet_stars.rbegin(), closet_stars.rend()};
}

int main() {
	string stringvalues = "0,0,0\n2,4,8\n7,3,9\n1,1,1\n-7,2,0\n";
	istringstream iss(stringvalues);
	
	auto result = FindClosestKStars(3, &iss);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i].x << result[i].y << result[i].z << endl;
	}
}

