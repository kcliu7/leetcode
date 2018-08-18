class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size(), color = image[sr][sc];
        //vector<vector<int>> res = image;
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};        
        queue<pair<int, int>> q{{{sr, sc} }};
        vector<bool> vis(m*n , 0 );
        
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i<len; ++i){
                auto tmp = q.front();   q.pop();
                vis[tmp.first*n + tmp.second] = 1;
                image[tmp.first][tmp.second] = newColor;
                for(auto dir : dirs){
                    int x = dir[0] + tmp.first, y = dir[1] + tmp.second;
                    if(x<0 || x>m-1 || y<0 || y>n-1 || image[x][y] != color|| vis[x*n + y]) continue;
                    q.push({x , y });
                }
            }            
        }
        return image;
    }
};