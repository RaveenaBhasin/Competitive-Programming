class Solution {
private:
    unordered_map<string, vector<pair<string, double>> > equation_graph;
    unordered_set<string> vis;
    bool calculate_dfs(string source, string destination, double curr_product, double& answer){
        if(source == destination && equation_graph.find(destination) != equation_graph.end()){
            answer = curr_product;
            return true;
        }
        
        vis.insert(source);
        for(pair<string, double>& neighbour : equation_graph[source]){
            if(vis.find(neighbour.first) == vis.end() && 
                    calculate_dfs(neighbour.first, destination, curr_product * neighbour.second, answer))
                return true;
        }
        return false;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for(int i = 0; i < n; i++){    
            equation_graph[equations[i][0]].push_back({equations[i][1], values[i]});
            equation_graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        
        vector<double> answers;
        for(vector<string>& query : queries){
            vis.clear();
            double answer = -1.0F, curr_product = 1.0F;
            calculate_dfs(query[0], query[1], curr_product, answer);
            answers.push_back(answer);
        }
        return answers;
    }
};