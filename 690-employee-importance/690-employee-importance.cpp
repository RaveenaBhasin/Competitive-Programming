/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    int helper(int id, unordered_map<int, Employee*>mp){
        auto total = mp[id]->importance;
        for(const auto it : mp[id]->subordinates){
            total += helper(it, mp);
        }
        return total;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*>mp;
        for(const auto it : employees){
            mp[it->id] = it;
        }
        return helper(id, mp);
    }
};


