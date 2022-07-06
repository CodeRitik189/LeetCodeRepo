class Solution {
public:
    int val = INT_MAX;
    string ans;
    
    int cal(string& str, int st, int endi){
        int num = 0;
        for(int i = st; i<= endi; i++){
            num = num* 10 + (str[i]-'0');
        }
        return max(num,1);
    }
    void check(string& s, int st, int mid, int endi){
        for(int i = mid-1; i>= st ; i--){
          for(int j = mid+1; j<= endi ; j++){
int num = cal(s,st,i-1)*cal(s,j+1,endi)*(stoi(s.substr(i,mid-i))+stoi(s.substr(mid+1,j-mid)));
            if(num<val){
                val = num;
                ans = s.substr(0,i)+'('+s.substr(i,j-i+1)+')'+s.substr(j+1);
            }
          }
        }
    }
    string minimizeResult(string expression) {
        int n = expression.size(),mid;
        for(int i = 1; i<n-1; i++){
            if(expression[i] == '+'){
                mid = i;
                break;
            }
        }
        check(expression,0,mid,n-1);
        return ans;
    }
};