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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return  NULL;
        map<int, int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root= new TreeNode(preorder[0]);
        int rootind= mpp[root->val];
        vector<int>leftin;
        for(int i=0;i<rootind;i++){
            leftin.push_back(inorder[i]);
        }
        vector<int>leftpre;
        for(int i=1;i<=leftin.size();i++){
            leftpre.push_back(preorder[i]);
        }
        vector<int>rightin;
        for(int i=rootind+1;i<inorder.size();i++){
            rightin.push_back(inorder[i]);
        }
        vector<int>rightpre;
        for(int i=leftpre.size()+1;i<preorder.size();i++){
            rightpre.push_back(preorder[i]);
        }
        root->left=  buildTree(leftpre, leftin);
        root->right=  buildTree(rightpre, rightin);

        return root;
    }
};