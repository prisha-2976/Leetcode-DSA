class Solution {
    public int reverse(int x) {
        int lastdigit;
         int rev=0;
        if(x==0){
          return 0;
        }
        else{
        while(x>0|| x<0){
             lastdigit=x%10;
             if (rev>Integer.MAX_VALUE/10 || rev<Integer.MIN_VALUE/10){
                return 0;
            }
            rev=(rev*10)+lastdigit;
            x=x/10;
           
             

        }
         return rev;
        
    }
    }
    // return rev;
}
