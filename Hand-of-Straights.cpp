class Solution {
public:
    // bool isNStraightHand(vector<int>& hand, int groupSize) {
    //     bool result=hand.size() % groupSize==0;
    //     int numGroups=hand.size() / groupSize;
    //     sort(hand.begin(),hand.end());
    //     // if(hand[0]!=1) return false;
    //     int violate=0;
    //     for(int i=0;i<hand.size();i++)
    //     {
    //         if((i!=hand.size()-1)&&(abs(hand[i]-hand[i+1])==1)&&((i+1)%groupSize!=0))
    //         {
    //             cout<<groupSize<<endl;
    //             cout<<(i+1)%groupSize<<endl;
    //             cout<<hand[i] <<hand[i+1];
    //             return false;
    //         }
    //         cout<<hand[i]<<"  ";
    //     }
    //     cout<<"size is "<<hand.size();
    //     if(groupSize!=1&&hand.size()>=2&&abs(hand[hand.size()-2]-hand[hand.size()-1])>1) return false;
        
    //  return result ;   
    // }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;
    map<int, int> count;
    for (int card : hand) count[card]++;
    
    for (auto& [card, freq] : count) {
        if (freq > 0) {
            for (int i = 1; i < groupSize; ++i) {
                if (count[card + i] < freq)
                    return false;
                count[card + i] -= freq;
            }
        }
    }
    return true;
}

};