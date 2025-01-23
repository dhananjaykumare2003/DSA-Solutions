Approach:- recursive heightWay
Time Complexity :- O(N)
Space Complexity :- O(H)
class Solution {
public:
    int heightWay(TreeNode* root, int& ans){
        if(root == NULL) return 0;
        int lh = heightWay(root->left,ans);
        int rh = heightWay(root->right,ans);
        ans = max(ans,lh+rh);
        return max(lh,rh)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        heightWay(root,ans);
        return ans;
    }
};
