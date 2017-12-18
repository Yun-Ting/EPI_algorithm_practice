// Time Complexity: O(h) 
// since we descend the tree in each iteration, 
// the time complexity is O(h)

const TreeNode* FindKthNodeBinaryTree(const TreeNode* tree, int k) {
	TreeNode* iter = tree;
	while (iter != nullptr) {
		int left_size = iter->left ? iter->left_size : 0;
		if (left_size + 1 < k) { // kth node must be in right tree of iter
			k = k - (left_size + 1);
			iter = iter->right;
		} else if (left_size + 1 == k) { // k-th is iter itself
			return iter;
		} else { // kth node must be in left subtree of iter
			iter = iter->left;
		}
	}
	return nullptr;
}