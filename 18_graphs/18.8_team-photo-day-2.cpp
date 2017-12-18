// 18.8_team-photo-day-2.cpp

struct GraphVertex {
	vector<GraphVertex*> edges;
	// set max_distance = 0 to indicate unvisited vertex.
	int max_distance = 0;
};

int FindLargestNumberTeams(vector<GraphVertex>* G) {
	stack<GraphVertex*> vertex_order(BuildTopologicalOrdering(G));
	return FindLargestNumberPath(&vertex_order);
}

stack<GraphVertex*> BuildTopologicalOrdering(vector<GraphVertex>* G) {
	
}