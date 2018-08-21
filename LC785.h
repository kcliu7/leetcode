class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size());
        for(int i=0; i<graph.size(); ++i){
            if(colors[i] != 0) continue;
            colors[i] = 1;
            queue<int> q{{i}};
            while(!q.empty()){
                int t = q.front();   q.pop();
                for(auto a : graph[t] ){
                    if(colors[a] == 0 ){
                        colors[a] = -1 * colors[t]; 
                        q.push(a);
                    } 
                    else{
                        if(colors[a] == colors[t] ) return false;
                    }
                }
            }
        }
        return true;
    }
};