class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        int sum = 0;
        for(int i=0; i<ops.size(); i++){
            if(ops[i]=="D"){
              sum += (st.top()*2);
              st.push(st.top()*2);
            }else if(ops[i]=="C"){
               sum -= (st.top());
               st.pop(); 
            }else if(ops[i]=="+"){
                int a1 = st.top();
                st.pop();
                int a2 = st.top();
                st.pop();
                st.push(a2);
                st.push(a1);
                st.push(a1+a2);
                sum += (a1+a2);
            }else{
               int val;
               if(ops[i][0]=='-')
                 val = -(stoi(ops[i].substr(1)));
               else
                 val = stoi(ops[i]);
               sum += val;
               st.push(val); 
            }
        }
        return sum;
    }
};