// 8.10_implement-a-queue-with-max-API.cpp
// date: 10/17
// Time Comp: 
// dequeue: O(1), Amortized enqueue: O(n), max: O(1)
// Space Comp:

template <typename T>
class QueueWithMax {
public:
	void Enqueue(const T& x) {
		entries_.emplace(x);
		// Eliminate dominated elements in candidates_for_max_
		while (!candidates_for_max_.empty() && candidates_for_max_.back() < x) {
			candidates_for_max_.pop_back();
		}
		candidates_for_max_.emplace_back(x);
	}

	T Dequeue() {
		if (!entries_.empty()) {
			T result = entries_.front();
			if (result == candidates_for_max_.front()) {
				candidates_for_max_.pop_front();
			}
			entries_.pop();
			return result;
		}
		throw length_error("empty queue");
	}

	const T& Max() const {
		if (!candidates_for_max_.empty()) {
			return candidates_for_max_.front();
		}
		throw length_error("empty queue");
	}

private:
	queue<T> entries_;
	deque<T> candidates_for_max_;
};