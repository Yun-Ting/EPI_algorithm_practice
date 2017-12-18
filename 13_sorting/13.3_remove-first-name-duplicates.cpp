// 13.3_remove-first-name-duplicates.cpp

// struct Name {
// 	bool operator==(const Name& that) const {
// 		return Name.firstname == that.firstname;
// 	}

// 	bool operator>(const Name& that) const {
// 		return firstname != that.firstname ? firstname < that.firstname;
// 	}
// 	string firstname;
// 	string lastname;	
// };


// void EliminateDuplicate(vector<Name>* A) {
// 	sort(A->begin(), A->end());
// 	A->erase(unique(A->begin(), A->end()), A->end());
// }





































struct Name {
	bool operator==(const Name& that) {
		return firstname == that.firstname;
	}

	bool operator<(const Name& that) {
		return firstname != that.firstname ? firstname < that.firstname;
	}

	string firstname;
	string lastname;
};

vector<Name> EliminateDuplicates(vector<Name>& A) {
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
}













