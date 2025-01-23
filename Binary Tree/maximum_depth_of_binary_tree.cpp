Approach :- recursion
Time Complexity :- O(N) because we visited all nodes once.
Space Complexity :- O(H) because of recursion stack.

class Solution {
public:

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right) + 1;
    }
};
