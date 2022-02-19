class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
		priority_queue<int> pq;
        int mini = INT_MAX;
		for(auto it : nums){
			if(it % 2 == 1){
				it *= 2;
			}
			mini = min(mini, it);
			pq.push(it);
		}
		int ans = INT_MAX;
		while(true){
			int temp = pq.top();
			pq.pop();
			ans = min(ans, temp - mini);
			if(temp % 2 == 1){
				break;
			}
			mini = min(mini, temp / 2);
			pq.push(temp/2);
		}
		return ans;
    }
};