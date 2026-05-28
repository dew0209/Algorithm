//https://leetcode.cn/problems/longest-common-suffix-queries/description/?envType=daily-question&envId=2026-05-28


const int N = 500010;


class Trie{
    public:
        Trie(){
            for(int i = 0;i < N;i++){
                index_id[i] = 0x3f3f3f3f;
                len[i] = 0x3f3f3f3f;
            }
            idx = 0;
        }
        void insert(const string& str,int t){
            int p = 0;
            int n = str.size();
            if(n < len[p]){
                index_id[p] = t;
                len[p] = n;
            }
            for(int i = 0;i < n;i++){
                int u = str[i] - 'a';
                if(!son[p][u])son[p][u] = ++idx;
                p = son[p][u];
                if(n < len[p]){
                    index_id[p] = t;
                    len[p] = n;
                }
            }
        }

        int query(const string& str){
            int p = 0;
            
            for(int i = 0;i < str.size();i++){
                int u = str[i] - 'a';
                if(!son[p][u])break;
                p = son[p][u];
            }
            return index_id[p];
        }
        void clear(){
                
            for(int i = 0;i <= idx;i++){
                index_id[i] = 0x3f3f3f3f;
                len[i] = 0x3f3f3f3f;
                memset(son[i], 0, sizeof(son[i]));
            }
            idx = 0;
        }
    private:            
        int son[N][26],idx;
        int index_id[N];
        int len[N];

};

Trie tr;

class Solution {
public:
    

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        int m = wordsQuery.size();

        tr.clear();

        for(int i = 0;i < n;i++){
            string s = wordsContainer[i];
            reverse(s.begin(), s.end());
            tr.insert(s,i);
        }
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            string s = wordsQuery[i];
            reverse(s.begin(), s.end());
            res[i] = tr.query(s);
        }
        return res;
    }
};