class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) return res;
        int M = matrix.size();
        int N = matrix[0].size();
        for(int i = 0; i <= M+N-2; ++i){
            if(i % 2 ==0){
                for(int j =0; j<=i; ++j){
                    if((i-j)<M && j<N){
                        res.push_back(matrix[i-j][j]);
                    }                        
                }
            }
            else{
                for(int j =0; j<=i; ++j){
                    if(j<M && (i-j)<N){
                        res.push_back(matrix[j][i-j]);
                    }                        
                }
            }
        }
        return res;
    }
};