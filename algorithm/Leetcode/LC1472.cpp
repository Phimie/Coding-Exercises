#include <iostream>
#include <vector>
#include <string>

class BrowserHistory
{
private:
    std::vector<std::string> history;
    int cur;

public:
    BrowserHistory(std::string homepage)
    {
        history.push_back(homepage);
        cur = 0;
    }

    void visit(std::string url)
    {
        history.resize(cur + 1);
        history.push_back(url);
        cur++;
    }

    std::string back(int steps)
    {
        int newCur = std::max(0, cur - steps);
        cur = newCur;
        return history[cur];
    }

    std::string forward(int steps)
    {
        int newCur = std::min((int)history.size() - 1, cur + steps);
        cur = newCur;
        return history[cur];
    }
};