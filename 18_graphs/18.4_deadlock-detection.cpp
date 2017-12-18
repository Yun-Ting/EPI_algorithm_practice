// 18.4_deadlock-detection.cpp

struct GraphVertex {
	enum Color {white, gray, black} color = white;
	vector<GraphVertex*> edges;
};

bool IsDeadlocked(vector<GraphVertex>* G) {
	return any_of(begin(*G), end(*G),[&](GraphVertex& vertex) {
		return vertex.color == GraphVertex::white && HasCycle(&vertex);
	});
}

bool HasCycle(GraphVertex* cur) {
	// visiting a gray vertex means a cycle.
	if (cur->color == GraphVertex::gray) {
		return true;
	}

	cur->color = GraphVertex::gray; // Marks current vertex as a gray one.
	// Traverse the neighbor vertices.
	for (GraphVertex*& next : cur->edges) {
		if (next->color != GraphVertex::black && HasCycle(next)) {
			return true;
		}
	}

	cur->color = GraphVertex::black; // Marks current vertex as black.
	return false;
}
