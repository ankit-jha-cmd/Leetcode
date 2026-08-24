/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    void bfs(TreeNode* root, string &s){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* el=q.front();
            q.pop();
            if(el==NULL){
                s+="n,";
                continue;
            }
            s.append(to_string(el->val) + ',');
            q.push(el->left);
            q.push(el->right); 
        }
    }
    string serialize(TreeNode* root) {
        string s;
        bfs(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string temp="";
        vector<string>arr;
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                arr.push_back(temp);
                temp="";
            }
            else temp+=data[i];
        }

        if(arr[0]=="n") return NULL;
        queue<TreeNode*>q;
        TreeNode* root= new TreeNode(stoi(arr[0]));
        q.push(root);
        int curr=1;
        while(!q.empty() && curr<arr.size()){
            TreeNode* el=q.front();
            q.pop();
            if(arr[curr]!="n"){
                el->left=new TreeNode(stoi(arr[curr]));
                q.push(el->left);
            }
            curr++;

            if(curr<arr.size() && arr[curr]!="n"){
                el->right= new TreeNode(stoi(arr[curr]));
                q.push(el->right);
            }
            curr++;
        }
        return root;
    }        
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));