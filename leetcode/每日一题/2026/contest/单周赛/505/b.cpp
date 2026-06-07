class Solution {
public:
    void dfs(int idx,string str,int n,int k,int prev,vector<string>& res,int tol){
        if(idx == n){
            res.push_back(str);
            return;
        }
        dfs(idx + 1,str + "0",n,k,0,res,tol);
        if(prev != 1){
            if(tol + idx <= k){
                dfs(idx + 1,str + "1" ,n,k,1,res,tol + idx);
            }
            
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        string str;
        dfs(0,str,n,k,-1,res,0);
        return res;
    }
};