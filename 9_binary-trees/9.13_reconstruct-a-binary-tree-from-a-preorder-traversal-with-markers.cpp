

TreeNode* Reconstruct(vector<int*>& preorder) {
	int subtree_idx = 0;
	return helper(preorder, subtree_idx);
}

TreeNode* helper(vector<int*>& preorder, int& subtree_idx) {

	int* subtree_key = preorder[subtree_idx];
	++subtree_idx;
	if (subtree_key == nullptr) return nullptr;

	auto left_subtree = helper(preorder, subtree_idx); 
	// we do left first, and the ++subtree_idx in that level will forward the idx to somewhere closer to the right subtree idx
	auto right_subtree = helper(preorder, subtree_idx);

	return new TreeNode(*subtree_key, left_subtree, right_subtree);
}
