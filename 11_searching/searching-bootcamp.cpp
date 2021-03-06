// searching-bootcamp.cpp

struct Student {
	string name;
	double grade_point_average;
};

const static function<bool(const Student&, const Student&)> CompGPA = [](
	const Student& a, const Student& b) {
	if (a.grade_point_average != b.grade_point_average) {
		return a.grade_point_average > b.grade_point_average;
	}
	return a.name < b.name;
}

bool SearchStudent (
	const vector<Student>& students;
	const Student& target;
	const function<bool(const Student&, const Student&)> & CompGPA) {
		return binary_search(students.begin(), students.end(), target, CompGPA);
}