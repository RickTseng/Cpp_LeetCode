#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class RangeFreqQuery
{
public:
    RangeFreqQuery(vector<int> &arr)
    {
        db = arr;
        for (int i = 0; i < arr.size(); i++)
        {
            bb[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value)
    {
        if (bb.find(value) == bb.end())
        {
            return 0;
        }
        if (left == right && db[left] == value)
        {
            return 1;
        }
        //vector<int> tmp;
        //tmp = bb[value];
        int s = 0;
        int e = bb[value].size() - 1;
        while (s < bb[value].size() && bb[value][s] < left)
        {
            s++;
        }
        while (e >= 0 && bb[value][e] > right)
        {
            e--;
        }
        if(s>=bb[value].size() || e<0){
            return 0;
        }
        else{
            return e-s+1;
        }
    }

private:
    vector<int> db;
    map<int, vector<int>> bb;
};
class RangeFreqQuery_web_tbne1905 {
public:
    unordered_map<int, vector<int>> mp;
    int N; 
    
    RangeFreqQuery_web_tbne1905(vector<int>& arr) {
        int n = arr.size();
        this->N = n;
        
        for(int i=0;i<n;i++)
            mp[ arr[i] ].emplace_back(i);
    }
    
    int query(int left, int right, int value) {
        if(mp.count(value)==0)  return 0;
        
        vector<int>& indices = mp[value];
        int leftIdx = lower_bound(indices.begin(), indices.end(), left) - indices.begin();
        int rightIdx = upper_bound(indices.begin(), indices.end(), right) - indices.begin() - 1;
        
        int freq = rightIdx - leftIdx + 1;
        if(freq<0)  return 0;
        else return freq;
    }
};


int main()
{
    //vector<int> vv = {3, 4, 5, 3, 3, 2, 2, 2, 5, 4};
    //vector<int> vv(100000, 1);
    vector<int> vv = {1,1,1,2,2};
    RangeFreqQuery *rfq = new RangeFreqQuery(vv);
    cout << rfq->query(0, 1, 2) << endl;
}
/*
["RangeFreqQuery","query","query","query","query","query"]
[[[3,4,5,3,3,2,2,2,5,4]],[2,6,3],[5,6,5],[1,6,2],[0,2,3],[5,6,4]]

["RangeFreqQuery","query","query","query","query"]
[[[1,1,1,2,2]],[0,1,2],[0,2,1],[3,3,2],[2,2,1]]








Constraints:






1 <= arr.length <= 10^5
1 <= arr[i], value <= 10^4
0 <= left <= right < arr.length
At most 10^5 calls will be made to query

*/