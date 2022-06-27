#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) 
    {
        string res = senders[0];
        int _max = 1;
        vector<int> count(senders.size(),1);
        for(int i = 0;i<messages.size();i++){
            for(int idx = 0;idx<messages[i].size();idx++){
                if(messages[i][idx]==' '){
                    count[i]++;
                }
            }
        }
        unordered_map<string,int> mp;
        for(int idx = 0;idx<senders.size();idx++){
            mp[senders[idx]]+=count[idx];
            if(mp[senders[idx]]>_max){
                res = senders[idx];
                _max = mp[senders[idx]];
            }
            if(mp[senders[idx]]==_max){
                vector<string> tmpS = {res,senders[idx]};
                sort(tmpS.begin(),tmpS.end());
                res = tmpS.back();
            }
        }
        return res;
    }
};
/**
 * @brief ["tP x M VC h lmD","D X XF w V","sh m Pgl","pN pa","C SL m G Pn v","K z UL B W ee","Yf yo n V U Za f np","j J sk f qr e v t","L Q cJ c J Z jp E","Be a aO","nI c Gb k Y C QS N","Yi Bts","gp No g s VR","py A S sNf","ZS H Bi De dj dsh","ep MA KI Q Ou"]
["OXlq","IFGaW","XQPeWJRszU","Gb","HArIr","Gb","FnZd","FnZd","HArIr","OXlq","IFGaW","XQPeWJRszU","EMoUs","Gb","EMoUs","EMoUs"]
 * 
 */
int main(){
    Solution sol;
    vector<string> a = {"tP x M VC h lmD","D X XF w V","sh m Pgl","pN pa","C SL m G Pn v","K z UL B W ee","Yf yo n V U Za f np","j J sk f qr e v t","L Q cJ c J Z jp E","Be a aO","nI c Gb k Y C QS N","Yi Bts","gp No g s VR","py A S sNf","ZS H Bi De dj dsh","ep MA KI Q Ou"};
    vector<string> s = {"OXlq","IFGaW","XQPeWJRszU","Gb","HArIr","Gb","FnZd","FnZd","HArIr","OXlq","IFGaW","XQPeWJRszU","EMoUs","Gb","EMoUs","EMoUs"};
    string ans = sol.largestWordCount(a,s);
}