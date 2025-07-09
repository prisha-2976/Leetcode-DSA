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
vector<vector<int>> ans;
void function(TreeNode* curr, int sum, vector<int> &storage, int &targetSum){
    sum+=curr->val;
    storage.push_back(curr->val);
    // base condition
    if(curr->left==nullptr && curr->right==nullptr && sum==targetSum){
        ans.push_back(storage);

    }
    if(curr->left)function(curr->left, sum, storage, targetSum);
     if(curr->right)function(curr->right, sum, storage, targetSum);
     sum-=curr->val;
     storage.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return {};
        ans={};
        vector<int> storage;
        function(root,0,storage, targetSum);
        return ans;

        
    }
};