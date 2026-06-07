//https://leetcode.cn/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2026-06-07


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
    TreeNode* get_node(int u){
        TreeNode* node = new TreeNode();
        node->val = u;
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,vector<pair<int,int>>> cnt;
        map<int,bool> count;
        set<int> num;
        for(auto& desc : descriptions){
            int p = desc[0];
            int ch = desc[1];
            int isLeft = desc[2];
            count[ch] = true;
            num.insert(ch);
            num.insert(p);
            cnt[p].push_back({ch,isLeft});
        }
        int root = -1;
        for(auto it : num){
            if(!count.count(it)){
                root = it;
                break;
            }
        }
        TreeNode* rooNode = get_node(root);
        map<int,TreeNode*> cnt2;
        cnt2[root] = rooNode;
        for(auto [x,it] : cnt){
            
            TreeNode* pnode = cnt2[x];
            if(pnode == nullptr){
                pnode = get_node(x);
            }
            for(auto its : it){
                int v = its.first;
                int w = its.second;
                TreeNode* vnode = cnt2[v];
                if(vnode == nullptr){
                    vnode = get_node(v);
                }
                if(w == 1){
                    pnode->left = vnode;
                }else {
                    pnode->right = vnode;
                }
                cnt2[v] = vnode;
            }
            cnt2[x] = pnode;
        }
        return rooNode;
    }
};