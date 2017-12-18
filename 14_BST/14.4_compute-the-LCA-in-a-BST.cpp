// 14.4_compute-the-LCA-in-a-BST.cpp

TreeNode* FindLCA(const TreeNode* tree, TreeNode* s, TreeNode* b) {
	auto p = tree;
	while (p->data < s->data || p->data > b->data) {
		// Keep searching since p is outside of [s, b].
		while (p->data < s->data) {
			p = p->right;
		}
		while (p->data > b->data) {
			p = p->left;
		}
	}
	return p;
}
