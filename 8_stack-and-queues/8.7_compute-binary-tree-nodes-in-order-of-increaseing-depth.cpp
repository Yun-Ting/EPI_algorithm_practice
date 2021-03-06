// 8.7_compute-binary-tree-nodes-in-order-of-increasing-depth.cpp

vector<vector<int>> BinaryTreeDepthOrder(const BinaryTreeNode* tree) {
	queue<BinaryTreeNode*> curr_depth_nodes({tree});
	vector<vector<int>> result;

	while (!curr_depth_nodes.empty()) {
		queue<BinaryTreeNode*> next_depth_nodes;
		vector<int> this_level;
		while (!curr_depth_nodes.empty()) {
			auto curr = curr_depth_nodes.front();
			curr_depth_nodes.pop();
			if (curr) {
				this_level.emplace_back(curr->data);

				// Defer the null check to the null test above
				next_depth_nodes.emplace_back(cur->left);
				next_depth_nodes.emplace_back(cur->right);
			}
		}
		if (!this_level.empty()) {
			result.emplace_back(this_level);
		}
		curr_depth_nodes = next_depth_nodes;
	}
	return result;
}