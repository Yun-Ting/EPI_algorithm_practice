// 17.6_the-gasup-problem.cpp

const int kMPG = 20;

// gallons[i] is the amount of gas in city i, and
// distance[i] is the distance city i to the next city

int FindAmpleCity(const vector<int>& gallons, const vector<int>& distances) {
	int remaining_gallons = 0;

	struct CityAndRemainingGas {
		int city = 0, remaining_gallons = 0;
	};

	CityAndRemainingGas city_remaining_gas_pair;
	const int num_of_cities = gallons.size();

	for (int i = 1; i < num_of_cities; ++i) {
		remaining_gallons += gallons[i - 1] - distances[i - 1] / kMPG;
		if (remaining_gallons < city_remaining_gas_pair.remaining_gallons) {
			city_remaining_gas_pair = {i, remaining_gallons};
		}
	}
	return city_remaining_gas_pair.city;
}