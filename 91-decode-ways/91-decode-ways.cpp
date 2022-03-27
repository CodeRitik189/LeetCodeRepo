class Solution {
public:
  int counti( string s , int i , int* dp ){
      if(s.size()==i){
         return 1;
      }
       if(i==(s.size()-1)&&s[ i ]!='0'){
          dp[ i ] = 1;
           return 1;
       }else if(s[ i ]=='0'){
           dp[ i ]=0;
           return 0;
         }
         if( dp[ i ]!=-1){
           return dp[ i ] ;
         }
           int ans = 0;
           if(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6')){
               ans += counti(s,i+2 , dp);
           }
           ans += counti(s,i+1 , dp);
           dp[ i ] = ans;
           return ans;
   }
    int numDecodings(string s) {
        int* dp = new int [ s.size( ) ];
        for( int i = 0 ; i< s.size( ); i++){
             dp[ i ]= -1;
        }
        return counti(s ,0 , dp);
    }
};