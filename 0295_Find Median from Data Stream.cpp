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
class MedianFinder
{
public:
    priority_queue<long> small, large;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size())
        {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian()
    {
        return small.size()>large.size()? small.top():(small.top()-large.top())/2.0;
    }
};
int main(){
    MedianFinder mf = MedianFinder();
    mf.addNum(2);
    mf.addNum(3);
    mf.addNum(4);
    mf.addNum(5);
    mf.addNum(7);
    mf.addNum(2);
    auto ans =  mf.findMedian();
}