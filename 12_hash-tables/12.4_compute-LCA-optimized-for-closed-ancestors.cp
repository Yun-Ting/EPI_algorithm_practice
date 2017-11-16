// 12.4_compute-LCA-optimized-for-closed-ancestors.cpp
using namespace std;
// 9.4
// struct TreeNode {
// 	TreeNode* next;
// 	TreeNode* parent;
// 	int data;
// 	TreeNode() : next(nullptr), parent(nullptr) {}
// };

// TreeNode* LCA(TreeNode* n1, TreeNode* n2) {
// 	int depth_n1 = GetDepth(n1);
// 	int depth_n2 = GetDepth(n2);
// 	if (n2 > n1) {
// 		swap(n1, n2);
// 	}
// 	int depth_diff = depth_n1 - depth_n2;
// 	while (depth_diff--) {
// 		n1 = n1->parent;
// 	}
// 	while (n1 != n2) {
// 		n1 = n1->parent;
// 		n2 = n2->parent;
// 	}
// 	return n1;
// }

// int GetDepth(TreeNode* node) {
// 	int depth = 0;
// 	while (node->parent) {
// 		++depth;
// 		node = node->parent;
// 	}
// 	return depth;
// }

////////////////////////////////////////////
// Time and Space Com: O(D0 + D1);
// D0 is the distance from the argument to the root

TreeNode* LCA(TreeNode* n1, TreeNode* n2) {
	unordered_set<TreeNode*> nodes_on_path_to_root;
	while (n1 || n2) {
		if (n1) {
			if (nodes_on_path_to_root.emplace(n1).second == false) {
				return n1;
			}
			n1 = n1->parent;
		}
		if (n2) {
			if (nodes_on_path_to_root.emplace(n2).second == false) {
				return n2;
			}
			n2 = n2->parent;
		}
	}
}






