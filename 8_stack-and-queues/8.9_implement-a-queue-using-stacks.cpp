// 8.9_implement-a-queue-using-stacks.cpp

class Queue {
public:
	void Enqueue(int x) {
		enqueue_.emplace(x);
	}
	int Dequeue() {
		if (dequeue_.empty()) {
			while (!enqueue_.empty()) {
				dequeue_.emplace(enqueue_.top());
				enqueue_.pop();
			}			
		}
		if (dequeue_.empty()) {
			throw length_error("the queue is already empty!");
		}
		int ret = dequeue_.top();
		dequeue_.pop();
		return ret;
	}
private:
	stack<int> enqueue_;
	stack<int> dequeue_;

};