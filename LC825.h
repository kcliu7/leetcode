class Solution {
public:
    
    
    int numFriendRequests(vector<int>& ages) {
    sort(ages.begin(), ages.end(), [](int x, int y) {return x > y;});
    int result = 0;
    vector<int> age, people;
    int i = 0;
    while (i < ages.size()) {
        int a = ages[i];
        int index = i;
        while (i < ages.size() && ages[i] == a)i++;
        age.push_back(a);
        people.push_back(i - index);
    }
    //for(auto x : age) cout<<x<<"\t";cout<<endl;
    //for(auto x : people) cout<<x<<"\t";cout<<endl;
    int head = 0, tail = 1, total = 0;
    while (head < age.size()) {
        if (head == tail) {
            total = 0;
            tail++;
        }
        while (tail < age.size() && 2 * age[tail] > age[head] + 14) total += people[tail++];
        //cout<<"head: "<<age[head]<<" tail: "<<tail<<" total: "<<total<<endl;
        result += people[head] * total;
        if (age[head] > 14) result += people[head] * (people[head] - 1);
        total -= people[++head]; 
    }
    return result;
}
};