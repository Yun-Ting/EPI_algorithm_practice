// 9.12.cpp


class Solution {
public:
	
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		unordered_map<int, size_t> node_to_inorder_idx;
		for(unsigned i = 0; i < inorder.size(); ++i) {
			node_to_inorder_idx.emplace(inorder[i], i);
		}

		return helper(preorder, 0, preorder.size(), 0, inorder.size(), node_to_inorder_idx);
	}

	TreeNode* helper(vector<int>& preorder, size_t pre_start, size_t pre_end, size_t in_start, size_t in_end, unordered_map<int, size_t>& node_to_inorder_idx) {

		if (inorder_end <= inorder_start) {return nullptr;} 

		size_t root_inorder_idx = node_to_inorder_idx.at(preorder[pre_start]);
		size_t left_subtree_size = root_inorder_idx - in_start;

		auto node = new TreeNode(preorder[pre_start]);
		node->left = helper(preorder, pre_start + 1, pre_start + 1 + left_subtree_size, in_start, root_inorder_idx, node_to_inorder_idx);
	}	node->right = helper(preorder, pre_start + 1 + left_subtree_size, pre_end, root_inorder_idx + 1, in_end, node_to_inorder_idx)

};