//9.4_compute-the-LCA-when-nodes-have-parent-pointers.cpp

TreeNode* LCA(const TreeNode* node0, const TreeNode* node1) {
	int depth0 = GetDepth(node0);
	int depth1 = GetDepth(node1);
	// make node0 as the deeper node to simplify the code.
	if (depth1 > depth0) {
		swap(node0, node1);
	}
	// Ascends from the deeper node.
	int depth_diff = abs(depth_0 - depth1);
	while (depth_diff--) {
		node0 = node0->parent;
	}
	// Now ascends both nodes until we reach the LCA
	while (node0 != node1) {
		node0 = node0->parent;
		node1 = node1->parent;
	}
	return node1;
}

int GetDepth(const TreeNode* node) {
	int depth = 0;
	while (node->parent) {
		++depth;
		node = node->parent;
	}
	return depth;
}