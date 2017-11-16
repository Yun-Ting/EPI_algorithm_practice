// 9.8_implement-a-preorder-traversal-without-recursion.cpp

vector<int> PreorderTraversal(const TreeNode* tree) {
	stack<TreeNode* > path;
	path.emplace_back(tree);
	vector<int> result;
	while (!path.empty()) {
		auto curr = path.top();
		path.pop();
		if (curr != nullptr) {
			result.emplace_back(curr->data);
			path.emplace(curr->right);
			path.emplace(curr->left);
		}
	}
	return result;
}