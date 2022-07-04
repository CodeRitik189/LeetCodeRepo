class Solution {
public:
    int ans = 0;
    vector<int>vis;
    int find2(string& s, int i, int j){
        if(i>j)return 0;
        
        if(vis[i])return find2(s,i+1,j);
        if(vis[j])return find2(s,i,j-1);
        
        if(s[i]==s[j]){
           return (i!=j?2:1)+find2(s,i+1,j-1);
        }
        return max(find2(s,i+1,j),find2(s,i,j-1));
    }
    void find(string& s, int i, int j,int ct){
        if(i>j){
            return;
        }
        if(s[i]==s[j]){
            vis[i]=1;
            vis[j]=1;
            ans = max(ans,(ct+(i!=j?2:1))*find2(s,0,s.size()-1));
            find(s,i+1,j-1,ct+(i!=j?2:1));
            vis[i]=0;
            vis[j]=0;
        }
        find(s,i+1,j,ct);
        find(s,i,j-1,ct);
    }
    int maxProduct(string s){
        if(s.size()==2 && s[0]==s[1])return 1;
        vis = vector<int>(s.size(),0);
        find(s,0,s.size()-1,0);
        return ans;
    }
};