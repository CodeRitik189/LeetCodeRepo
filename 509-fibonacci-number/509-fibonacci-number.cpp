class Solution {
public:
    int find(int n){
        if(n<=1)return n;
        return find(n-1)+find(n-2);
    }
    int fib(int n) {
       return find(n); 
    }
};