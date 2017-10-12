// 8.6_buildings-with-a-sunset-view.cpp

vector<int> ExamineBuildingWIthSunset(istringstream* sin) {
	int building_idx = 0;
	int building_height;

	struct BuildingWithHeight {
		int id;
		int height;
	};

	stack<BuildingWithHeight> candidates;
	while (*sin >> building_height) {
		while (!candidates.empty() && building_height >= candidates.top().height) {
			candidates.pop();
		}
		candidates.emplace(BuildingWithHeight{building_idx++, building_height});
	}

	vetor<int> buildings_with_sunset;
	while (!candidates.empty()) {
		buildings_with_sunset.emplace_back(candidates.top().id);
		candidates.pop();
	}
	return buildings_with_sunset;
}