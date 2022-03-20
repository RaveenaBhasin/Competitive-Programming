class Solution {
public:
    int helper(vector<int>& A,vector<int>& B,int x){
        
        int total = 0;     
        int countA = 0;   
        int countB = 0;  
        for(int i = 0 ;i<A.size();i++){
            if(A[i] == x || B[i] == x)
                total++;
            if(A[i] == x)
                countA++;
            if(B[i] == x)
                countB++;
        }
        
        if(total != A.size())   
            return -1;
        
        else return min(total - countA,total - countB);      
        
    }
    
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        
        int ans = helper(A,B,A[0]);   
        if(ans != -1) 
            return ans;
        else return helper(A,B,B[0]);
        
    }
};