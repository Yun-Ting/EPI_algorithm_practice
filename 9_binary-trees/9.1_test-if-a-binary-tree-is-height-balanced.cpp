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

	auto left_result = CheckBalanced(tree->left); 
	if (!left_result.balanced) {
		return {false, 0};
	}

	auto right_result = CheckBalanced(tree->right);
	if (!right_result.balanced) {
		return {false, 0};
	}

	bool IsBalanced = abs(left_result.height - right_result.height) <= 1;
	int height = max(left_result.height, right_result.height) + 1;
	return {is_balanced, height};

}