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
class TextEditor
{
public:
//TLE
    TextEditor()
    {
        cursorIdx = 0;
        tmp = {};
    }

    void addText(string text)
    {
        tmp.insert(tmp.begin() + cursorIdx, text.begin(), text.end());
        cursorIdx += (int)text.size();
        // cout << "Add Finished" << endl;
    }

    int deleteText(int k)
    {
        k = min(k, cursorIdx);
        tmp.erase(max(cursorIdx - k, 0), k);
        cursorIdx -= k;
        return k;
    }

    string cursorLeft(int k)
    {
        cursorIdx -= k;
        if (cursorIdx < 0)
            cursorIdx = 0;
        string res = tmp.substr(max(cursorIdx - 10, 0), min(10, (int)tmp.size()));

        return tmp.substr(max(cursorIdx - 10, 0), min(10, cursorIdx));
    }

    string cursorRight(int k)
    {
        cursorIdx += k;
        if (cursorIdx >= tmp.size())
            cursorIdx = tmp.size();

        return tmp.substr(max(cursorIdx - 10, 0), min(10, cursorIdx));
    }

private:
    int cursorIdx;
    string tmp;
};
class TextEditor_votrubac
{
public:
    string before, after;
    TextEditor_votrubac()
    {
    }

    void addText(string text)
    {
        before.insert(end(before), begin(text), end(text));
    }
    int deleteText(int k)
    {
        k = min(k, (int)before.size());
        before.resize(before.size() - k);
        return k;
    }
    string cursorLeft(int k)
    {
        while (k-- && !before.empty())
        {
            after.push_back(before.back());
            before.pop_back();
        }
        return before.substr(before.size() - min((int)before.size(), 10));
    }
    string cursorRight(int k)
    {
        while (k-- && !after.empty())
        {
            before.push_back(after.back());
            after.pop_back();
        }
        return before.substr(before.size() - min((int)before.size(), 10));
    }
};

// ["TextEditor","addText","deleteText","addText","cursorLeft","addText","deleteText","addText","cursorLeft","deleteText"]
// [[],["arnvmumatgmyw"],[5],["zrlufuifuy"],[2],["unh"],[20],["kwwp"],[6],[9]]
int main()
{
    TextEditor te = TextEditor();
    te.addText("arnvmumatgmyw");
    te.deleteText(5);
    te.addText("zrlufuifuy");
    te.cursorLeft(2);
    cout << "Program End" << endl;
}