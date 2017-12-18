// 14.3_find-the-k-largest-elements-in-a-BST.cpp

vector<int> FindKLargestInBST(TreeNode* tree, int k) {
	vector<int> k_largest_elements;
	FindKLargestInBSTHelper(tree, k, &k_largest_elements);
	return k_largest_elements;
}

void FindKLargestInBSTHelper(TreeNode* tree, int k, vector<int>* k_largest_elements) {
	// perform reverse inorder traversal

	if (tree && k_largest_elements->size() < k) {
		FindKLargestInBSTHelper(tree->right, k, k_largest_elements);
		if (k_largest_elements->size() < k) {
			k_largest_elements->emplace_back(tree->data);
			FindKLargestInBSTHelper(tree->left, k, k_largest_elements);
		}
	}
}