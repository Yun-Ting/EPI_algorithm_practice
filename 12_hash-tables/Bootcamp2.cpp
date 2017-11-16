// Bootcamp2.cpp
// Design of a hashable class

struct ContactList {
	// equal function for hash
	bool operator==(const ContactList& that) const {
		return unordered_set<string>(names.begin(), names.end()) == 
			   unordered_set<string>(that.names.begin(), that.names.end());
	}
	vector<string> names;
};

// Hash function for ContactList.
struct HashContactList { 
	size_t operator()(const ContactList& contacts) const {
		size_t hash_code = 0;
		for (const string& name: unordered_set<string>(contacts.name.begin(), contacts.names.end())) {
			hash_code ^= hash<string>()(name);
		}
		return hash_code;
	}
};

vector<ContactList> MergeContactLists(const vector<ContactList>& contacts) {
							   // a class implemented function operator
	unordered_set<ContactList, HashContactList> unique_contacts(contacts.begin(), contacts.end());
	return {unique_contacts.begin(), unique_contacts.end()};
}