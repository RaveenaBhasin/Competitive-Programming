class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector< vector<int> > arr (board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[0].size();j++)
            {
                int cnt0=0,cnt1=0;
                for (int x=-1;x<=1;x++)
                {
                    for (int y=-1;y<=1;y++)
                    {
                        if ((x!=0 or y!=0) and i+x>=0 and i+x < board.size() and j+y>=0 and j+y< board[0].size())
                        {
                            if (board[i+x][j+y]==0 or board[i+x][j+y]==2 or board[i+x][j+y]==3)
                            {
                                cnt0++;
                            }
                            else
                            {
                                cnt1++;
                            }
                        }
                    }
                }
                if (board[i][j]==0 and cnt1==3) 
                {
                    board[i][j]=3;
                }
                else if (board[i][j]==1 and (cnt1<2 or cnt1>3))
                {
                    board[i][j]=4;
                }
                else if (board[i][j]==1)
                {
                    board[i][j]=5;
                }
                else
                {
                    board[i][j]=2;
                }
            }
        }
        for (int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[0].size();j++)
            {
                if (board[i][j]==3 or board[i][j]==5)
                {
                    board[i][j]=1;
                }
                else if (board[i][j]==2 or board[i][j]==4)
                {
                    board[i][j]=0;
                }
            }
        }
    }
};