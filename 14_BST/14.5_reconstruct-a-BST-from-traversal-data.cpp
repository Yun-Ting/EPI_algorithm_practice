// 14.5_reconstruct-a-BST-from-traversal-data.cpp

// Time Complexity: O(n^2) for stick
// 					O(nlogn) for complete tree
TreeNode* RebuildBSTFromPreorder(const vector<int>& preorder_sequence) {
	return RebuildBSTFromPreorderHelper(preorder_sequence, 0, preorder_sequence.size());
}

// Builds a BST from preorder_sequence[start, end - 1]
TreeNode* RebuildBSTFromPreorderHelper(const vector<int>& preorder_sequence, int start, int end) {
	if (start >= end) {
		return nullptr;
	}
	int transition_point 
		= distance(preorder_sequence.cbegin(), find_if_not(preorder_sequence.cbegin() + start, preorder_sequence.cend(),
		[&](int a) {return a <= preorder_sequence[start]; }))

	return TreeNode(
		{preorder_sequence[start], RebuildBSTFromPreorderHelper(preorder_sequence, start + 1, transition_point), RebuildBSTFromPreorderHelper(preorder_sequence, transition_point, end)});
}


///////////
TreeNode* RebuildBSTFromPreorder(const vector<int>& preorder_sequence) {
	int root_idx = 0;
	return RebuildBSTFromPreorderHelper(preorder_sequence, numeric_limits<int>::min(), numeric_limits<int>::max(), &root_idx);
}

TreeNode* RebuildBSTFromPreorderHelper(const vector<int>& preorder_sequence, int upper_bound, int lower_bound, int& root_idx) {
	if (root_idx == preorder_sequence.size()) return nullptr;

	int root = preorder_sequence[root_idx];
	if (root < lower_bound || root > upper_bound) return nullptr;
	++root_idx;
	auto left_subtree = RebuildBSTFromPreorderHelper(preorder_sequence, lower_bound, root, root_idx);
	auto right_subtree = RebuildBSTFromPreorderHelper(preorder_sequence, root, upper_bound, root_idx);
	return TreeNode({root, left_subtree, right_subtree});
}
