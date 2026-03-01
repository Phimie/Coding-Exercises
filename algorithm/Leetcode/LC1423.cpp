#include <iostream>
#include <vector>
class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        int sum = 0;
        int min_sum = 0;
        int n = cardPoints.size();
        for (int i = 0 ; i < n ; i++){
            sum += cardPoints[i];
        }
        for (int i = 0 ; i < n - k ; i++){
            min_sum += cardPoints[i];
        }
        int ans = min_sum;
        for (int i = n - k; i < n; i++){
            min_sum += cardPoints[i];
            min_sum -= cardPoints[i - (n - k)];
            ans = (ans > min_sum)?min_sum:ans;
        }
        return sum - ans;
    }
};

int main (){
    Solution s1;
    std::vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    std::cout << s1.maxScore(cardPoints,k) << std::endl;
    return 0;
}