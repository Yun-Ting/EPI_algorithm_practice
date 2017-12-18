// 13.9_team-photo-day-1.cpp
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Player {
	bool operator<(const Player& that) const {
		return height < that.height;
	}
	int height;
};

class Team {
public:
	explicit Team(const vector<int>& height) {
		for (int h : height) {
			players_.emplace_back(Player{h});
		}
	}
	static bool ValidPlacementExists(Team& A, Team& B) {
		vector<Player> A_sorted(A.SortPlayersByHeight());
		vector<Player> B_sorted(B.SortPlayersByHeight());
		for (int i = 0; i < A_sorted.size() && i < B_sorted.size(); ++i) {
			if (!(A_sorted[i] < B_sorted[i])) {
				return false;
			}
		}
		return true;
	}

private:
	vector<Player> SortPlayersByHeight() const {
		vector<Player> sorted_players(players_); // vector copy constructor
		sort(sorted_players.begin(), sorted_players.end());
		return sorted_players;
	}

	vector<Player> players_;
};

int main(int argc, char const *argv[])
{
	vector<int> teamA_height = {3,4,5,6,7,8,9};
	vector<int> teamB_height = {4,5,6,7,8,9,10};
	Team A = Team(teamA_height);
	Team B = Team(teamB_height);
	cout << Team::ValidPlacementExists(A, B);
	
	return 0;
}