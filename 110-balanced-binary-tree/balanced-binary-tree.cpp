/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int fn(TreeNode* root,bool& ans){
    if(!root) return 0;
    int left= fn(root->left, ans);
    int right= fn(root->right, ans);
    if(abs(right-left)>1) ans=false;
    return 1+max(left, right);
}
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        fn(root, ans);
        return ans;
    }
};
