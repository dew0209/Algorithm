//https://leetcode.cn/problems/count-nodes-equal-to-average-of-subtree/?envType=daily-question&envId=2026-09-10


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
    int averageOfSubtree(TreeNode* root) {
        int r = 0;
        dfs(root,r);
        return r;
    }
    vector<int> dfs(TreeNode* root,int& r){
        if(root == nullptr){
            return {0,0};
        }
        int sum = root->val;
        int tol = 1;

        if(root->left != nullptr){
            auto res1 = dfs(root->left,r);
            sum += res1[0];
            tol += res1[1];
        }
        if(root->right != nullptr){
            auto res1 = dfs(root->right,r);
            sum += res1[0];
            tol += res1[1];
        }
        if(root->val == sum / tol){
            //cout << root->val << endl;
            r = r + 1;
        }
        return {sum,tol};
    }
};