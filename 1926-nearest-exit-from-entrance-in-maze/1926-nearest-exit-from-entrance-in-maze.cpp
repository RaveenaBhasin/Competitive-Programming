class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>>q;
        q.push({entrance[0], entrance[1]});
        int m = maze.size(), n = maze[0].size();
        int moves = 1;
        vector<vector<int>>paths = {{0,1}, {1,0}, {-1, 0}, {0,-1}};
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto [k, l] = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    int x = k + paths[j][0];
                    int y = l + paths[j][1];
                    if(x < 0 || x >= m || y < 0 || y >= n || maze[x][y] == '+'){
                        continue;
                    }
                    if(x == 0 || x == m-1 || y == 0 || y == n-1){
                        return moves;
                    }
                    maze[x][y] = '+';
                    q.push({x,y});
                }
            }
            moves++;
        }
        return -1;
    }
};