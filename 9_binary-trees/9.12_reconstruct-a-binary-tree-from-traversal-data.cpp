#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* BinaryTreeFromPreorderInorder(const vector<int>& preorder, const vector<int>& inorder);
TreeNode* BinaryTreeFromPreorderInorderHelper(
	const vector<int>& preorder, size_t preorder_start, size_t preorder_end, 
	size_t inorder_start, size_t inorder_end, const unordered_map<int, size_t>& node_to_inorder_idx);



TreeNode* BinaryTreeFromPreorderInorder(const vector<int>& preorder, const vector<int>& inorder) {
	unordered_map<int, size_t> node_to_inorder_idx;
	for (size_t i = 0; i < inorder.size(); ++i) {
		node_to_inorder_idx.emplace(inorder[i], i);
	}
	return BinaryTreeFromPreorderInorderHelper(
		preorder, 0, preorder.size(), 0, inorder.size(), node_to_inorder_idx);
}


// builds the subtree with preorder[preorder_start, preorder_end - 1] and
// inorder[inorder_start, inorder_end - 1].
TreeNode* BinaryTreeFromPreorderInorderHelper(
	const vector<int>& preorder, size_t preorder_start, size_t preorder_end, 
	size_t inorder_start, size_t inorder_end, const unordered_map<int, size_t>& node_to_inorder_idx) {

	if (inorder_end <= inorder_start) {
		return nullptr;
	}
	size_t root_inorder_idx = node_to_inorder_idx.at(preorder[preorder_start]);
	size_t left_subtree_size = root_inorder_idx - inorder_start;

	auto node = new TreeNode(preorder[preorder_start]);
	node->left = BinaryTreeFromPreorderInorderHelper(preorder, preorder_start + 1, preorder_start + 1 + left_subtree_size, inorder_start, root_inorder_idx, node_to_inorder_idx);
	node->right = BinaryTreeFromPreorderInorderHelper(preorder, preorder_start + 1 + left_subtree_size, preorder_end, root_inorder_idx + 1, inorder_end, node_to_inorder_idx);

	return node;
}

void TreeTraversal(TreeNode* root) {
	if (root) {
		cout << "preorder: " << root->val << endl;
		TreeTraversal(root->left);

		cout << "inorder: " << root->val << endl;
		TreeTraversal(root->right);
	}
}

int main() {
	vector<int> inorder = {6,2,1,5,8,3,4,9,7};
	vector<int> preorder = {8,2,6,5,1,3,4,7,9};
	auto cuteTree = BinaryTreeFromPreorderInorder(preorder, inorder);

	TreeTraversal(cuteTree);
}
