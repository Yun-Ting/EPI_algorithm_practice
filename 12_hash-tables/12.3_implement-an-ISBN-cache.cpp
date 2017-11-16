// 12.3_implement-an-ISBN-cache.cpp
// template <size_t capacity>
class LRUCache {
public:
	LRUCache(capacity_in) : capacity(capacity_in) {}

	bool lookup(int isbn, int* price) {
		auto it = isbn_price_table_.find(isbn);
		if (it == isbn_price_table_.end()) {
			return false;
		}
		*price = it->second.second;
		// Since key has just been accessed, move it to the front.
		MoveToFront(isbn, it);
		return true;
	}

	void Insert(int isbn, int price) {
		auto it = isbn_price_table_.find(isbn);
		// We add the value for key only if key is not present
		// - we don't update existing values.
		if (it != isbn_price_table_.end()) {
			MoveToFront(isbn, it);
		} else {
			if (isbn_price_table_.size() == capacity) {
				// Remove the least recently used ISBN to get space
				isbn_price_table_.erase(lru_queue_.back()); // .back() access the last element
				lru_queue_.pop_back();
			}
			lru_queue_.emplace_front(isbn);
			isbn_price_table_[isbn] = {lru_queue_.begin(), price};
		}
	}

	bool Erase(int isbn) {
		auto it = isbn_price_table_.find(isbn);
		if (it == isbn_price_table_.end()) {
			return false;
		}

		lru_queue_.erase(it->second.first);
		isbn_price_table_.erase(it);
		return true;
	}

private:
	typedef unordered_map<int, pair<list<int>::iterator, int>> Table;
	// is equivalent to
	// using Table = unordered_map<int, pair<list<int>::iterator, int>>;

	// A type alias is a different name by which a type can be identified. 
	// In C++, any valid type can be aliased so that it can be referred to with a different identifier.

	void MoveToFront(int isbn, const Table::iterator& it) {
		lru_queue_.erase(it->second.first);
		lru_queue_.emplace_front(isbn);
		it->second.first = lru_queue_.begin();
	}

	Table isbn_price_table_;
	list<int> lru_queue_;
	size_t capacity;
};

int main() {
	LRUCache<10> myCache;
}
