class Solution {
public:
int fn(TreeNode* root, int& maxsum){
    if(!root) return 0;
    int leftsum= max(0, fn(root->left, maxsum));
    int rightsum= max(0, fn(root->right, maxsum));
    maxsum = max(maxsum, root->val+leftsum+rightsum);
    return root->val+max(leftsum, rightsum);
}
    int maxPathSum(TreeNode* root) {
        int maxsum=root->val;
        fn(root, maxsum);
        return maxsum;
    
    }
};
