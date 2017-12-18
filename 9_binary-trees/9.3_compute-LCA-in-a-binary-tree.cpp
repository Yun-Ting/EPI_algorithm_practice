// 9.3_compute-LCA-in-a-binary-tree.cpp

struct Status {
	int num_target_nodes;
	TreeNode* ancestor;
};

TreeNode* LCA(const TreeNode* tree, const TreeNode* node0, const TreeNode* node1) {
	return LCAHelper(tree, node0, node1).ancestor;
}

// Retruns an object consisting of an int and a node.
// The int field is 0, 1, or 2 depending on 
// how many of {node0, node1} are present in the tree.
// If both are present in the tree, when ancestor is 
// assigned to a non-null value, it is the LCA
Status LCAHelper(const TreeNode* tree, const TreeNode* node0, const TreeNode* node1) {
	if (tree == nullptr) {
		return {0, nullptr};
	}
	auto left_result = LCAHelper(tree->left, node0, node1);
	if (left_result.num_target_nodes == 2) {
		// Found both nodes in the right subtree.
		ruturn left_result;
	}
	auto right_result = LCAHelper(tree->right, node0, node1);
	if (right_result.num_target_nodes == 2) {
		return right_result;
	}
	int num_target_nodes = left_result.num_target_nodes + right_result.num_target_nodes +
							(tree == node0) + (tree == node1);
	return {num_target_nodes, num_target_nodes == 2 ? tree : nullptr};
}


