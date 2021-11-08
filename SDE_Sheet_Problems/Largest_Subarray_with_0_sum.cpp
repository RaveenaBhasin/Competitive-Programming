class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        //Initialise a variable say sum = 0 which stores the sum of elements traversed so far and another variable say mx = 0 which stores the length of longest subarray with sum zero.
        int sum = 0, mx = 0;
        // Declare a HashMap<Integer, Integer> which stores the prefix sum of every element as key and its index as value.
        unordered_map<int, int>m;
        // Traverse the array and add the array element to our sum. 
        for(int i = 0; i<n; i++){
            sum += A[i];
            if(sum == 0){
                mx = i + 1;
            }
            // if HashMap contains sum -> this is where the subarray with equal sum, so we update our max 
            else{
                if(m.find(sum)!=m.end()){
                    mx = max(mx, i-m[sum]);
                }
                // else -> Insert (sum, current_index) into hashmap to store prefix sum until current index
                else{
                    m[sum] = i;
                }
            }
        }
        return mx;
    }
};
// T.C : O(n)  S.C : O(n)