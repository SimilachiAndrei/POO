#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

ifstream f("fis.txt");

struct Compare {
    bool operator() (pair<string, int> p1, pair<string, int> p2) {
        if (p1.second < p2.second)
            return true;
        if (p1.second > p2.second)
            return false;
        if (p1.first < p2.first)
            return false;
        return true;
    }
};

int main()
{
    map<string, int> wordCount;
    string s;
    if (getline(f, s))
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string delimiters = " .,!?";
        size_t pos = 0;
        while ((pos = s.find_first_of(delimiters)) != string::npos) {
            string word = s.substr(0, pos);
            if (!word.empty()) {
                if (wordCount.find(word) == wordCount.end())
                {
                    wordCount.insert(make_pair(word, 1));
                }
                else
                {
                    wordCount[word]++;
                }
            }
            s.erase(0, pos + 1);
        }
        string word = s;
        if (!word.empty()) {
            if (wordCount.find(word) == wordCount.end())
            {
                wordCount.insert(make_pair(word, 1));
            }
            else
            {
                wordCount[word]++;
            }
        }
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq(wordCount.begin(),wordCount.end());

    while (!pq.empty())
    {
        auto entry = pq.top();
        cout << entry.second << " => " << entry.first << endl;
        pq.pop();
    }
}
