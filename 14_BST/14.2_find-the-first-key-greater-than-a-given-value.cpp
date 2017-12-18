// 14.2_find-the-first-key-greater-than-a-given-value-in-BST.cpp

// Time: O(h), Space: O(1)
TreeNode* FindFirstGreaterThanK(const TreeNode* tree, int k) {
	TreeNode* sub_tree;
	TreeNode* first_so_far = nullptr;

	while(sub_tree) {
	    if (sub_tree->data > k) {
	    	first_so_far = sub_tree;
	    	sub_tree = sub_tree->left;
	    } else { // Root and all keys in leftree are <= k, so skip them
	    	sub_tree = sub_tree->right;
	    }
	}
	return first_so_far;
}



