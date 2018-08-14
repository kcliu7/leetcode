class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int pretime = 0, id = 0, time = 0;
        char type[10];
        for(string log: logs){
            sscanf(log.c_str(), "%d:%[^:]:%d", &id, type, &time);
            if(type[0] == 's'){
                if(!st.empty()){
                    res[st.top()] += time - pretime; 
                }
                st.push(id);
            }
            else{
                res[st.top()] += ++time -pretime;
                st.pop();
            }
            pretime = time;
        }        
        return res;
    }
};