TreeNode* ReconstructPreorder(const vector<int*>& preorder) {
	int subtree_idx_pointer = 0;
	return ReconstructPreorderHelper(preorder, &subtree_idx_pointer);
}

TreeNode* ReconstructPreorderHelper(const vector<int*>& preorder, int* subtree_idx_pointer) {
	int& subtree_idx = *subtree_idx_pointer;
	int* subtree_key = preorder[subtree_idx];
	++subtree_idx;
}