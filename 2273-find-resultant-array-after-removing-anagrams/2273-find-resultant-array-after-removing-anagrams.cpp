class Solution {
public:
    vector<string> removeAnagrams(vector<string>& wordi) {
        vector<string> words = wordi;
        int k=1;
        sort(words[0].begin(),words[0].end());
        for(int i=1;i<words.size();i++){
            sort(words[i].begin(),words[i].end());
            if(words[i]!=words[i-1]){
                wordi[k++] = wordi[i];
            }
        }
        for(int i=0;i<words.size()-k;i++){
            wordi.pop_back();
        }
        return wordi;
    }
};