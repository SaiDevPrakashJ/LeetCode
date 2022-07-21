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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*> queue;
        vector<int> inside1;
        inside1.push_back(root->val);
        result.push_back(inside1);
        queue.push(root);
        bool flag_reverse=true;
        while(queue.size()!=0){
            int size = queue.size();
            vector<int> inside;
            for(int i=0;i<size;i++){
                TreeNode* current = queue.front();
                queue.pop();
                if(current->left!=NULL){
                    queue.push(current->left);
                    inside.push_back(current->left->val);
                }
                if(current->right!=NULL){
                    queue.push(current->right);
                    inside.push_back(current->right->val);
                }
            }
            if(flag_reverse==true){
                reverse(inside.begin(), inside.end());
                flag_reverse=false;
            }else{
                flag_reverse=true;
            }
            if(!inside.empty())
                result.push_back(inside);
        }
        
        return result;
        
        
        
    }
};