// 18.3_compute-enclosed-regions.cpp

void FillSurrondedRegions(vector<vector<char>>& board) {

	// Identifies the regions that are reachable via white
	// path starting from the first or last columns
	for (int i = 0; i < board.size(); ++i) {
		if (board[i][0] == "W") {
			MarkBoundaryRegions(i, 0, board);
		}
		if (board[i][board[i].size() - 1] == "W") {
			MarkBoundaryRegions(i, board[i].size() - 1, board);
		}
	}

	// Identifies the regions that are reachable via white path starting
	// from the first or last rows
	for (int j = 0; j < board.front.size(); ++j) {
		if (board[0][j] == "W") {
			MarkBoundaryRegions(0, j, board);
		}
		if (board[board.size() - 1][j] == "W") {
			MarkBoundaryRegions(board.size() - 1, j, board);
		}
	}

	// Mark the surrounded white regions as black.
	for (vector<char>& row : board) {
		for (char& c : row) {
			c = c != 'T' ? 'B' : 'W';
		}
	}
}

void MarkBoundaryRegions(int i , int j, vector<vector<char>> board) {
	struct Coordinate {
		int x, y;
	};

	queue<Coordinate> q(deque<Coordinate>(1, Coordinate{i, j}));

	// Use BFS to traverse the region
	while (!q.empty()) {
	    const Coordinate curr = q.front();
	    q.pop();
	    if (curr.x >= 0 && curr.x < board.size() && 
	    	curr.y >= 0 && curr.y < board[cur.x].size() && board[curr.x][curr.y] == 'W') {
	    	q.emplace(Coordinate{curr.x - 1, curr.y});
	    	q.emplace(Coordinate{curr.x + 1, curr.y});
	    	q.emplace(Coordinate{curr.x, curr.y - 1});
	    	q.emplace(Coordinate{curr.x, curr.y + 1});
	    }
	}
}













