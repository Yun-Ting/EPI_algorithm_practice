// 8.8_implement-a-circular-queue.cpp
class Queue {
public:
	explicit Queue(size_t capacity) : entries_(capacity){};

	void Enqueue(int x) {
		if (num_queue_elements == entries_.size()) { // needs to resize
			rotate(entries_.begin(), entries_.begin() + head_, entries_.end());
			head_ = 0;
			tail_ = num_queue_elements;
			entries_.resize(entreis_.size() * kScaleFactor);
		}
		entries_[tail_] = x;
		tail_ = (tail_ + 1) % entries_.size(); 
		++num_queue_elements;
	}

	void Dequeue(int x) {
		if (num_queue_elements == 0) {
			throw length_error("empty queue");
		}
		--num_queue_elements;
		int ret = entries_[head_];
		head_ = (head_ + 1) % entries_.size();
		return ret;
	}

	size_t size() const { return num_queue_elements; }

private:
	const int kScaleFactor = 2;
	size_t head_ = 0;
	size_t tail_ = 0;
	num_queue_elements = 0;
	vector<int> entries_;

};