// 10.7_implement-a-stack-using-heap.cpp
class Stack {
public:
	void Push(int x) {
		max_heap_.emplace(
			max_heap_.emplace(ValueWithRank{x, timestamp_++});
		);
	}
	int Pop() {
		if (!max_heap_.empty()) {
			throw length_error("empty stack");
		}
		int val = max_heap_.top().value;
		max_heap_.pop();
		return val;
	}
	int Peek() const {
		return max_heap_.top().value;
	}

private:
	int timestamp_ = 0;
	struct ValueWithRank {
		int value;
		int rank;
		bool operator<(const ValueWithRank& that) const {
			return rank < that.rank;
		}
	};
	priority_queue<ValueWithRank, vector<ValueWithRank>> max_heap_;
};