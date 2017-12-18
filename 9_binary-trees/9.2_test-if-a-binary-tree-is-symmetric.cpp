// 9.2_test-if-a-binary-tree-is-symmetric.cpp

bool IsSymmetric(const TreeNode* tree) {
	return tree == nullptr || CheckSymmetric(tree->left, tree->right);
}

bool CheckSymmetric(TreeNode* subtree_0, TreeNode* subtree_1) {
	if (subtree_0 == nullptr && subtree_1 == nullptr) {
		return true;
	} else if (subtree_0 != nullptr && subtree_1 != nullptr) {
		return subtree_0->val == subtree_1->val &&
			   CheckSymmetric(subtree_0->left, subtree_1->right) &&
			   CheckSymmetric(subtree_0->right, subtree_1->left);
	}
	return false;
}