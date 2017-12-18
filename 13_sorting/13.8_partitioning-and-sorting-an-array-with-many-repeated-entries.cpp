// 13.8_partitioning-and-sorting-an-array-with-many-repeated-entries.cpp
// Time Complexity : O(n)
// Space Complexity: O(m)

struct Person {
	int age;
	string name;
};

// void GroupByAge(vector<Person>* people) {
// 	unordered_map<int, int> age_to_count;

// 	for (const Person& p : *people) { // dereference people pointer 拿到 此vector的頭
// 		++age_to_count[p.age];
// 	}

// 	unordered_map<int,int> age_to_offset;
// 	int offset = 0;
// 	for (const auto& p : age_to_count) {
// 		age_to_offset[p.first] = offset;
// 		offset += p.second;
// 	}

// 	while (!age_to_offset.empty()) {
// 		auto from = age_to_offset.begin();
// 		auto to = age_to_offset.find((*people)[from->second].age);
// 		swap((*people)[from->second], (*people)[to->second]);

// 		// Use age_to_count to see when we are finished with a particular age.
// 		--age_to_count[to->first];
// 		if (age_to_count[to->first] > 0) {
// 			++to->second;
// 		} else {
// 			age_to_offset.erase(to);
// 		}
// 	}
// }

































void GroupByAge(const vector<Person>* people) {
	unordered_map<int, int> age_to_count;

	for (const Person& p : people) {
		++age_to_count[p.age];
	}

	unordered_map<int, int> age_to_offset;
	int offset = 0;
	for (const auto& p : age_to_count) {
		age_to_offset[p.first] = offset;
		offset += p.second;
	}

	while (!age_to_offset.empty()) {
		auto from = age_to_offset.begin();
		auto to = age_to_offset.find( (*people)[from->second].age ); 
		// find checks for the key in the hash_map
		// returns the iteratro to that key if exist, else returns iterator to end
		swap((*people)[from->second], (*people)[to->second]);
		--age_to_count[to->first];
		if (age_to_count[to->first] > 0) {
			++to->second;
		} else {
			age_to_offset.erase(to);
		}

	}

}












