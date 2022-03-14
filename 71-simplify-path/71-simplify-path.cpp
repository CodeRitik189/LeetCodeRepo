class Solution {
public:
    string simplifyPath(string path) {
        vector<string>v;
        string s="";
        for(int i=0;i<path.size();i++){
            if(path[i]!='/'){
                 s += path[i];
            }else if(s.size()>0){
                if(s[0]!='.'){
                 v.push_back(s);
                }else{
                    if(s.size()==2){
                        if(v.size()>0)
                        v.pop_back();
                    }else if(s.size()>2){
                        v.push_back(s);
                    }
                }
                s="";
            }
        }
        
              if(s.size()>0&&s[0]!='.'){
                 v.push_back(s);
                }else if(s.size()>0){
                    if(s.size()==2){
                        if(v.size()>0)
                        v.pop_back();
                    }else if(s.size()>2){
                        v.push_back(s);
                    }
              }
          
        s="";
        for(int i=0;i<v.size();i++){
            s += '/';
            s += v[i];
        }
        if(s.size()>0)
        return s;
        else
        return "/";
    }
};