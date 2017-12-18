// 9.7_implement-an-inorder-traversal-without-recursion.cpp

vector<int> BSTInSortedOrder(const TreeNode* tree) {
	stack<const TreeNode*> s;
	auto curr = tree;
	vector<int> result;

	while (!s.empty() || curr) {
		if (curr) {
			s.push(curr);
			// Going left.
			curr = curr->left;
		} else {
			// Going up
			curr = s.top();
			s.pop();
			result.emplace_back(curr->data);
			// Going right
			curr = curr->right;
		}
	}
	return result;
}







