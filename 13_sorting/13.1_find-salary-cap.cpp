// 13.1_find-salary-cap.cpp

double FindSalaryaCap(double target_payroll, vector<double> current_salaries) {
	sort(current_salaries.begin(), current_salaries.end());
	double unadjusted_salary_sum = 0.0;
	for (int i = 0; i < current_salaries.size(); ++i) {
		const int adjusted_people = current_salaries.size() - i;
		const double adjusted_salary_sum = current_salaries[i] * adjusted_people;
		if (unadjusted_salary_sum + adjusted_salary_sum >= target_payroll) {
			return (target_payroll - unadjusted_salary_sum) / adjusted_people;
		}
		unadjusted_salary_sum += current_salaries[i];
	}
	return -1.0;
}