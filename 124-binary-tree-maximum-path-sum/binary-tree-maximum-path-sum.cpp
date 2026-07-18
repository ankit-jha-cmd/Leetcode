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
int fn(TreeNode* root, int& sum){
    if(!root) return 0;
    int leftsum=fn(root->left, sum);
    int rightsum=fn(root->right, sum);
    int totalsum= leftsum + rightsum + root->val;
    sum = max({sum, totalsum, leftsum+root->val, rightsum+root->val, root->val});
    return max({root->val, leftsum+root->val, rightsum+root->val});
}
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        fn(root, sum);
        return sum;
    }
};