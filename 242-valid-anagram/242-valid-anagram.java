class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()){return false;}
        
        ArrayList<Integer> v = new ArrayList<>();
        for(int i=0;i<26;i++){v.add(0);}
        for(int i=0;i<s.length();i++){
            int index=s.charAt(i)-'a';
             int index1=t.charAt(i)-'a';
          //  System.out.print(index+" "+index1+" ");
            int ans1=v.get(index)+1;
             v.set(index,ans1);
            int ans2=v.get(index1)-1;
        
           
            v.set(index1,ans2);
            
        }
        // for(int e:v)
        // {
        //     System.out.println(e+" ");
        // }
        for(int i=0;i<26;i++){
            if(v.get(i)!=0){
                return false;
            }
        }
        return true;
    }
}