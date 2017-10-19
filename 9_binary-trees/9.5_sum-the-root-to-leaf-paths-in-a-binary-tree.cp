// 9.5_sum-the-root-to-leaf-paths-in-a-binary-tree.cpp

int SumRootToLeaf(const TreeNode* tree) {
	return SumRootToLeafHelper(tree, 0);
}

int SumRootToLeafHelper(const TreeNode* tree, int partial_path_sum) {
	if (tree == nullptr) {
		return 0;
	}
	partial_path_sum = partial_path_sum * 2 + tree->data;
	if (tree->left == nullptr && tree->right == nullptr) { //leaf
		return partial_path_sum;
	}
	// Non-leaf
	return SumRootToLeafHelper(tree->left, partial_path_sum) + 
		   SumRootToLeafHelper(tree->right, partial_path_sum);
}