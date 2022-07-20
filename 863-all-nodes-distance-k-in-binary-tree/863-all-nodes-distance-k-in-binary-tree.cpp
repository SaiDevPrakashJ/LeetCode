/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode* , TreeNode*> parent;
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> queue;
        queue.push(root);
        while(queue.size()!=0){
            TreeNode* current = queue.front();
            queue.pop();
            if(current->left!=NULL){
                parent[current->left] = current;
                queue.push(current->left);
            }
            if(current->right!=NULL){
                parent[current->right] = current;
                queue.push(current->right);
            }
        }
        
        visited[target] = true;
        queue.push(target);
        int current_level=0;
        while(queue.size()!=0){
            if(current_level++ == k)
                break;
            int size = queue.size();
            for(int i=0;i<size;i++){
                TreeNode* current = queue.front();
                queue.pop();
                if(current->left && !visited[current->left]){
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                
                if(current->right!=NULL && !visited[current->right]){
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                
                
                if(parent[current]!=NULL && !visited[parent[current]]){
                    queue.push(parent[current]);
                    visited[parent[current]] = true;
                } 
            }
        
            
            
            
        }
        
        while(!queue.empty()){
              ans.push_back(queue.front()->val);
              queue.pop();
        }  
        
        
        return ans;
    }
};