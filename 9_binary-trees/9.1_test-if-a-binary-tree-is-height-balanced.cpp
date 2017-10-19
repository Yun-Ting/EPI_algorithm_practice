// 9.1_test-if-a-binary-tree-is-height-balanced.cpp

struct BalancedStatusWithHeight {
	bool balanced;
	int height;
};

bool IsBalanced(const TreeNode* root) {
	return CheckBalanced(tree).balanced;
}

BalancedStatusWithHeight CheckBalanced(const TreeNode* root) {
	if (!root) return {true, -1};

	int left_result = CheckBalanced(tree->left); 
	if (!left_result.balanced) {
		return {false, 0};
	}

}