// 9.6_find-a-root-to-leaf-path-with-specified-sum.cpp

bool HasPathSum(const TreeNode* tree, int remaining_weight) {
	if (tree == nullptr) {
		return false;
	} 
	else if (tree->left == nullptr && tree->right == nullptr){ // leaf
		return remaining_weight == tree->data;
	}
	// non leaf
	return HasPathSum(tree->left, remaining_weight - tree->data) ||
		   HasPathSum(tree->right, remaining_weight - tree->data);
}