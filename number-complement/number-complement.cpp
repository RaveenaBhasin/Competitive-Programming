class Solution {
public:
    int findComplement(int num) {
        vector<int>v; 
	    // convert to binary representation
        while(num != 0){
            v.push_back(num % 2);
            num /= 2;
        } 
		// make complement
        for(int i=0; i<v.size(); i++){
            if(v[i] == 1){
                v[i] = 0;
            }
            else if(v[i] == 0){
                v[i] = 1;
            }
        } 
        //convert binary to decimal
        int res = 0;
        for(int i=v.size()-1; i>=0; i--){
            res = res * 2 + v[i];
        }
        return res;
    }
};