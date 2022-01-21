#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i + 2 < s.size(); i++)
        {
            if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2])
            {
                count++;
            }
        }
        return count;
    }
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int tmp = -1001;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == tmp)
            {
                continue;
            }
            int beg = i;
            int end = numbers.size() - 1;
            while (beg <= end)
            {
                int mid = (beg + end) / 2;
                if (numbers[i] + numbers[mid] == target)
                {
                    return {i + 1, mid + 1};
                }
                if (numbers[i] + numbers[mid] < target)
                {
                    beg++;
                }
                if (numbers[i] + numbers[mid] > target)
                {
                    end--;
                }
            }
            tmp = numbers[i];
        }
        return {0, 0};
    }
    void reverseString(vector<char> &s)
    {
        int beg = 0, end = s.size() - 1;
        while (beg < end)
        {
            swap(s[beg], s[end]);
            beg++;
            end--;
        }
    }
    string reverseWords(string s)
    {
        string res = "", word = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' || i==s.size()-1)
            {
                if(i==s.size()-1){
                    word+=s[i];
                }
                int beg = 0, end = word.size() - 1;
                while (beg < end)
                {
                    swap(word[beg], word[end]);
                    beg++;
                    end--;
                }
                res+= word;
                if(i<s.size()-1)
                {
                    res += ' ';
                }
                word = "";           
                continue;
            }
            word += s[i];
        }
        return res;
    }
};