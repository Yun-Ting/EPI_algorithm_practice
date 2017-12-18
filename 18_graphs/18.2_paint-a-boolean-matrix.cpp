// 18.2_paint-a-boolean-matrix.cpp

// deque (usually pronounced like "deck") is an irregular acronym 
// of double-ended queue. Double-ended queues are sequence containers 
// with dynamic sizes that can be expanded or contracted on both ends (either its front or its back).

// BFS
void FlipColor(int x, int y, vector<deque<bool>>& A) {

	const array<array<int, 2>, 4> kDirs = {{{0, 1}, {0, -1}, {1, 0}, {1, 0}}};
	const bool color = A[x][y];

	struct Coordinate {
		int x, y;
	};

	queue<Coordinate> q;
	A[x][y] = !color; // flips
	q.emplace(Coordinate{x, y});
	while(!q.empty()) {
		Coordinate cur = q.front();
		for (const array<int, 2>& dir : kDirs) {
			const int next_x = cur.x + dir[0], next_y = cur.y + dir[1];
			if (next_x >= 0 && next_x < A.size() && next_y >= 0 && next_y < A[next_x].size() && A[next_x][next_y] == color) {
				// flips the color.
				A[next_x][next_y] = !color;
				q.emplace(Coordinate{next_x, next_y});
			}
		}
		q.pop();
	}
}

// DFS
void FlipColor(int x, int y, vector<deque<bool>>& A) {
	const array<array<int, 2>, 4> kDirs = {{{0, 1}, {0, -1}, {1, 0}, {1, 0}}};
	const bool color = A[x][y];

	A[x][y] = !color;
	for (const array<int, 2>& dir : kDirs) {
		const int next_x = cur.x + dir[0], next_y = cur.y + dir[1];
		if (next_x >= 0 && next_x < A.size() && next_y >= 0 && next_y < A[next_x].size() && A[next_x][next_y] == color) {
			FlipColor(next_x, next_y, A);
		}
	}
}
