// 18.1_search-a-maze.cpp
typedef enum { WHITE, BLACK } Color;

struct Coordinate {
	bool operator==(const Coordinate& that) {
		return x == that.x && y == that.y;
	}
	int x;
	int y;
};

vector<Coordinate> SearchMaze(vector<vector<Color>> maze, const Coordinate& s, const Coordinate& e) {
	vector<Coordinate> path;
	if (!SearchMazeHelper(s, e, &maze, &path)) { // no path between start and end
		return {};
	}
	return path;
}

// Perform DFS to find a feasible path.
bool SearchMazeHelper(const Coordinate& cur, const Coordinate& e, vector<vector<Color>>& maze, vector<Coordinate>& path) {
	
	// 檢查現在這個點是不是超出maze的合理範圍了
	if (!IsFeasible(cur, maze)) return false;
	path.emplace_back(cur);
	maze[cur.x][cur.y] = BLACK; // 把這個點改成走過

	if (cur == e) return true;

	const array<array<int, 2>, 4> kShift = {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
	
	// 對於每個點, try 右&上, 看有沒有可能解
	for (const array<int, 2>& s : kShift) {
		if (SearchMazeHelper( {cur.x + s[0], cur.y + s[1]}, e, maze, path)) {
			return true;
		}
	}
	path->pop_back();
	return false;
}

bool IsFeasible(const Coordinate& cur, const vector<vector<Color>>& maze) {
	return cur.x >= 0 && cur.x < maze.size() && cur.y >= 0 && cur.y < maze[cur.x].size()
					&& maze[cur.x][cur.y] == WHITE;
}

