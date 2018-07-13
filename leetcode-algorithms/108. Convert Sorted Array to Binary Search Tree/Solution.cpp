// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
// Example:
//
// Given the sorted array: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return formTree(nums, 0, nums.size() - 1);
    }

    TreeNode* formTree(vector<int>& nums, int start, int end) {
        if (start == end) {
            TreeNode* node = new TreeNode(nums[start]);
            return node;
        } else if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = formTree(nums, start, mid - 1);
        node->right = formTree(nums, mid + 1, end);
        return node;
    }
};
