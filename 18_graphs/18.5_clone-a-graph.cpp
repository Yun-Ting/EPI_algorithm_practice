// 18.5_clone-a-graph.cpp

struct GraphVertex {
	int label;
	vector<GraphVertex*> edges;
};

GraphVertex* CloneGraph(GraphVertex* G) {
	if (!G) return nullptr;

	unordered_map<GraphVertex*, GraphVertex*> vertex_map;
	queue<GraphVertex*> q;
	q.emplace(G);

	vertex_map.emplace(G, new GraphVertex({G->label}));
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		for (GraphVertex* e : v->edges) {
			// Try to copy vertex e.
			if (vertex_map.find(e) == vertex_map.end()) {
				vertex_map.emplace(e, new GraphVertex({e->label}));
				q.emplace(e);
			}

			// copy edges v->e
			vertex_map[v]->edges.emplace_back(vertex_map[e]);
		}
	}
	return vertex_map;
}