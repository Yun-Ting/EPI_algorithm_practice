// bootCamp.cpp

struct Student {
	bool operator<(const Student& that) const {
		return name < that.name;
	}
	string name;
	double grade_point_average;
}

void SortByName(vector<Student>* students) {
	// rely on the operator< defined in Student.
	sort(students->begin(), students->end());
}

void SortByGPA(vector<Student>* students) {
	sort(students->begin(), students->end(), [](const Student& a, const Student& b) {
		return a.grade_point_average >= b.grade_point_average;
	}); 
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}