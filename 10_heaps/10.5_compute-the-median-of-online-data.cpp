// 10.5_compute-the-median-of-online-data.cpp

void OnlineMedian(istringstream* sequence) {
	// min_heap stores the larger half seen so far.
	priority_queue<int, vector<int>, greater<>> min_heap;
	priority_queue<int, vector<int>, less<>> max_heap;

	int x;
	while (*sequence >> x) {
		min_heap.emplace(x);
		max_heap.emplace(min_heap.top());
		min_heap.pop();
		
		if (max_heap.size() > min_heap.size()) {
			min_heap.emplace(max_heap.top());
			max_heap.pop();
		}

		cout << (min_heap.size() == max_heap.size()) ? 
				0.5 * (min_heap.top() + max_heap.top()) :
				min_heap.top() << endl;
	}

}