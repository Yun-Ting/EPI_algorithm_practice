// 18.6_making-wired-connections.cpp

struct GraphVertex {
	int d = -1;
	vector<GraphVertex*> edges;
};

bool IsAnyPlacementFeasible(vector<GraphVertex>* G) {
	for (GraphVertex& v : *G) {
		if (v.d == -1 && !BFS(&v)) {
			return false;
		}
	}
	return true;
}

bool BFS(GraphVertex* s) {
	s->d = 0;
	queue<GraphVertex*> q;
	q.emplace(s);

	while(!q.empty()) {
		for (GraphVertex* t : q.front()->edges) {
			if (t->d == -1) { // Unvisited vertex
				t->d = q.front()->d + 1;
				q.emplace(t);
			} else if (t->d == q.front()->d) { // odd cycle 
				return false;
			}
		}
		q.pop();
	}
	return true;
}

