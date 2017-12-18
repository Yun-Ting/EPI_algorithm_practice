// 9.10_compute-the-successor.cpp

TreeNode* FindSuccessor(const TreeNode* node) {
	auto iter = node;
	if (iter->right != nullptr) {
		// Successor is the leftmost element in node's right subtree
		iter = iter->right;
		while (iter->left) {
			iter = iter->left;
		}
		return iter;
	}


	// find the closet ancestor whose left subtree contains node.
	while (iter->parent != nullptr && iter->parent->right == iter) {
		iter = iter->parent;
	}

	// A return value of nullptr means node does not have successor,
	// i.e., it is the rightmost node in the tree
	return iter->parent;
}