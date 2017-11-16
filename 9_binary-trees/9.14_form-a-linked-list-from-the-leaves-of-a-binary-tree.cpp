// 9.14_form-a-linked-list-from-the-leaves-of-a-binary-tree.cpp

list<TreeNode*> CreateListOfLeaves(TreeNode* tree) {
	list<TreeNode*> leaves;
	if (tree != nullptr) {
		if (tree->left == nullptr && tree->right == nullptr) {
			leaves.emplace_back(tree);
		} else {
			// First do the left subtree, 
			// and then do the right subtree
			leaves.splice(leaves.end(), CreateListOfLeaves(tree->left));
			leaves.splice(leaves.end(), CreateListOfLeaves(tree->right));
		}
	}
	return leaves;
} 