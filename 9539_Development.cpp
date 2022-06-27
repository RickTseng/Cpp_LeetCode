#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <fstream>
#include <array>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;
using std::stoi;

#define UP_LIMIT 25;
#define DOWN_LIMIT 25;
#define HISTORY_LENGTH 78;
class MagicalCalculator
{
public:
    bool data_isLoad = false;
    bool loadData(string txtFile)
    {
        pairRecord.resize(40, vector<bool>(40, false));
        ifstream myData(txtFile);
        char tmp[1024];
        int idx = 1;
        try
        {
            if (myData.is_open())
            {
                cout << "Open file success." << endl;
                while (!myData.eof())
                {
                    myData.getline(tmp, 1024, '\n');
                    string dataList(tmp);
                    string year(dataList.begin(), dataList.begin() + 4);
                    string month(dataList.begin() + 5, dataList.begin() + 7);
                    string dayth(dataList.begin() + 8, dataList.begin() + 10);
                    string b1(dataList.begin() + 11, dataList.begin() + 13);
                    string b2(dataList.begin() + 14, dataList.begin() + 16);
                    string b3(dataList.begin() + 17, dataList.begin() + 19);
                    string b4(dataList.begin() + 20, dataList.begin() + 22);
                    string b5(dataList.begin() + 23, dataList.begin() + 25);
                    string period(dataList.begin() + 26, dataList.begin() + 29);
                    db.push_back({idx++, stoi(year), stoi(month), stoi(dayth),
                                  stoi(b1), stoi(b2), stoi(b3), stoi(b4), stoi(b5), stoi(period)});
                }
                myData.close();
                return true;
            }
            cout << "Open file fail." << endl;
            if (!myData)
            {
                cout << "File not exist." << endl;
                return false;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << " Load file error" << endl;
            return false;
        }
        return false;
    }
    void k_calculator()
    {
        starNum.resize(40,0);
        int n = db.size() - HISTORY_LENGTH;
        int count = 0;
        for (int start = db.size() - 1; start >= n; start--)
        {
            for (int idxB1 = 4; idxB1 < 8; idxB1++)
            {
                int idxB2 = idxB1 + 1;
                if (pairRecord[db[start][idxB1]][db[start][idxB2]])
                {
                    continue;
                }
                count = analyzer(db[start][idxB1], db[start][idxB2],'K');
                pairRecord[db[start][idxB1]][db[start][idxB2]] = true;
            }
        }
        cout << "Method of K is finished." << endl;
    }
    void g_calculator()
    {
        starNum.resize(40,0);
        int n = db.size() - HISTORY_LENGTH;
        int count = 0;
        for (int start = db.size() - 1; start >= n; start--)
        {
            for (int idxB1 = 4; idxB1 < 8; idxB1++)
            {
                int idxB2 = idxB1 + 1;
                for (; idxB2 < 9; idxB2++)
                {
                    if (pairRecord[db[start][idxB1]][db[start][idxB2]])
                    {
                        continue;
                    }
                    count = analyzer(db[start][idxB1], db[start][idxB2], 'G');
                    pairRecord[db[start][idxB1]][db[start][idxB2]] = true;
                }
            }
        }
        cout << "Method of G is finished." << endl;
    }
    void monthlyAnalyzer()
    {
        if(!data_isLoad)
        {
            cout << "Data is empty, please load data file." << endl;
            return; 
        }
        vector<int> dp(40,0);
        int len = db.size();
        for (int i = 0; i < db.size(); i++)
        {
            for (int bIdx = 4; bIdx < 9; bIdx++)
            {
                dp[db[len - 1 - i][bIdx]]++;
            }
            if (i != 0 && i % 26 == 0)
            {
                int sum = 0, _min = 1000, _max = 0;
                set<int> od;
                for (int i = 1; i < 40; i++)
                {
                    sum += dp[i];
                    od.insert(dp[i]);
                    _min = min(_min, dp[i]);
                    _max = max(_max, dp[i]);
                }
                sum /= 39;
                dp.clear();
                dp.resize(40,0);
            }
        }
        
        
        
        return;
    }
    void data_revise(string str)
    {
        // time_t t = time()
        char *cha = (char *)str.data();
        tm _tm;
        int year, month, day, hour, minute, sec;
        sscanf(cha, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &sec);
        int idx = 1;

        ifstream myData("DataNew_toNow.txt");
        vector<vector<int>> rc;
        char tmp[1024];
        if (myData.is_open())
        {
            int b1,b2,b3,b4,b5;
            cout << "Open file success." << endl;
            while (!myData.eof())
            {
                myData.getline(tmp, 1024, '\n');
                sscanf(tmp,"%d,%d,%d,%d,%d",&b1,&b2,&b3,&b4,&b5);
                rc.push_back({b1,b2,b3,b4,b5});
            }
            myData.close();
        }
        reverse(rc.begin(),rc.end());
        ofstream file("ReviseDate.txt");

        _tm.tm_year = year - 1900;
        _tm.tm_mon = month - 1;
        _tm.tm_mday = day + 1;
        _tm.tm_hour = hour;
        _tm.tm_min = minute;
        _tm.tm_sec = sec;
        _tm.tm_isdst = 0;
        time_t t_ = mktime(&_tm);
        for (auto r : rc)
        {
            if(_tm.tm_wday == 0){
                _tm.tm_mday++;
                t_ = mktime(&_tm);
            }   
            file << _tm.tm_year + 1900 << "," ;
            file << setfill('0') << setw(2) << _tm.tm_mon + 1 <<  ",";
            file << setfill('0') << setw(2) << _tm.tm_mday << ",";
            file << setfill('0') << setw(2) << r[0] <<  ",";
            file << setfill('0') << setw(2) << r[1] <<  ",";
            file << setfill('0') << setw(2) << r[2] <<  ",";
            file << setfill('0') << setw(2) << r[3] <<  ",";
            file << setfill('0') << setw(2) << r[4] <<  "," << "000,9999" << endl;
            _tm.tm_mday++;
            t_ = mktime(&_tm);
        }
    }

private:
    vector<vector<int>> db;
    vector<int> starNum;
    vector<vector<bool>> pairRecord;
    int analyzer(int b1, int b2,char type)
    {

        int up_limit = UP_LIMIT;
        int down_limit = DOWN_LIMIT;
        vector<int> aprPeriods;
        // 1.find match period
        for (int i = db.size() - 1; i >= 0; i--)
        {
            bool getPair = false;
            // db[i][4~7] = b1~b4 position
            for (int idxB1 = 4; idxB1 < 8 && !getPair; idxB1++)
            {
                int idxB2 = idxB1 + 1;
                if (type == 'K')
                {                   
                    if (db[i][idxB1] == b1 && db[i][idxB2] == b2)
                    {
                        aprPeriods.push_back(i);
                        getPair = true;
                    }
                }
                else
                {
                    for (; idxB2 < 9 && !getPair; idxB2++)
                    {
                        if (db[i][idxB1] == b1 && db[i][idxB2] == b2)
                        {
                            aprPeriods.push_back(i);
                            getPair = true;
                        }
                    }
                }
            }
            // search most 10
            if (aprPeriods.size() > 10)
            {
                break;
            }
        }
        for (int upSide = 0; upSide <= up_limit; upSide++)
        {
            // ubIdx: up side period balls idx
            for (int ubIdx = 4; ubIdx < 9; ubIdx++)
            {
                for (int downSide = 1; downSide <= down_limit; downSide++)
                {
                    for (int magicNum = 0; magicNum < 40; magicNum++)
                    {
                        int res = calculator(aprPeriods, upSide, ubIdx, downSide, magicNum);
                        if (res >= 5)
                        {
                            if (aprPeriods.front() + downSide == db.size())
                            {
                                cout << b1 << "," << b2 << endl;
                                int target = abs(db[aprPeriods[0] - upSide][ubIdx] - magicNum);
                                //int target = db[aprPeriods[0] - upSide][ubIdx] - magicNum;
                                if (target < 1) target += 39;
                                cout << "*" << target << endl;
                                starNum[target] += res;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
    int calculator(vector<int> periods, int upSide, int ubIdx, int downSide, int magicNum)
    {
        int count = 0;
        for (int idx = 1; idx < periods.size(); idx++)
        {
            bool conti = false;
            if (periods[idx] - upSide >= 0 && periods[idx] + downSide < db.size())
            {
                for (int dbIdx = 4; dbIdx < 9; dbIdx++)
                {
                    int target = abs(db[periods[idx] - upSide][ubIdx] - magicNum);
                    //int target = db[periods[idx] - upSide][ubIdx] - magicNum;
                    if (target < 1) target += 39;
                    if (db[periods[idx] + downSide][dbIdx] == target)
                    {
                        count++;
                        conti = true;
                        break;
                    }
                }
            }
            if (!conti)
            {
                break;
            }
        }
        return count;
    }
};
int main()
{
    MagicalCalculator magic;
    //magic.data_revise("2021-06-12 00:00:00");
    magic.data_isLoad = magic.loadData("DataNew.txt");
    char sel = 'a';
    while (sel != 'q' && sel != 'Q')
    {

        magic.k_calculator();
        magic.g_calculator();
        magic.monthlyAnalyzer();
        cout << "Please enter option :" << endl;
        cin >> sel;
        cout << sel << endl;
        // system("pause");
    }
    cout << "Exit the program." << endl;
}