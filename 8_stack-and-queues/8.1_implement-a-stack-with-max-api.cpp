// 8.1_implement-a-stack-with-max-api.cpp
// date: 10/10

#include <stack>
// #include <stdexcept>
using namespace std;

class Stack {
public:
	bool Empty() const {
		return element_.empty();
	}

	int Max() const {
		if (Empty()) {
			throw length_error("Max(): empty stack");
		}
		return cached_max_with_count_.top().max;
	}

	int Pop() {
		if (Empty()) {
			throw length_error("Max(): empty stack");
		}
		int pop_element = element_.top();
		element_.pop();
		const int current_max = cached_max_with_count_.top().max;

		if (pop_element == current_max) {
			int& max_frequency = cached_max_with_count_.top().count;
			--max_frequency;
			if (max_frequency == 0) {
				cached_max_with_count_.pop();
			}
		}
		return pop_element;
	}

	void Push(int x) {
		element_.emplace(x);
		if (cached_max_with_count_.empty()) {
			cached_max_with_count_.emplace( MaxWithCount{x, 1} );
		} else {
			const int current_max = cached_max_with_count_.top().max;
			if (x == current_max) {
				int& max_frequency = cached_max_with_count_.top().count;
				++max_frequency;
			} else if (x > current_max) {
				cached_max_with_count_.emplace( MaxWithCount{x, 1} );
			}
		}
	}

private:
	stack<int> element_;
	struct MaxWithCount{
		int max;
		int count;
	};
	stack<MaxWithCount> cached_max_with_count_;
};