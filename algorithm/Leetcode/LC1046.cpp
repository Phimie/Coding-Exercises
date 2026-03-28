#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (int w : stones)
            pq.push(w);
        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a != b)
                pq.push(a - b);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

int main()
{
    return 0;
}