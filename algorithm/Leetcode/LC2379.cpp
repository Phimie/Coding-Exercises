#include <iostream>
#include <string>

class Solution {
public:
    int minimumRecolors(std::string blocks, int k) {
        int ans = k;
        int count = 0;
        for (int i = 0 ; i < k ; i++){
            if (blocks[i] == 'W') count++;
        }
        ans = (count < ans)?count:ans;
        for (int i = 1 ; i < (int)blocks.size() - k + 1 ; i++){
            if (blocks[i - 1] == 'W') count--;
            if (blocks[i + k -1] == 'W') count++;
            ans = (count < ans)?count:ans;
        }
        return ans;
    }
};

int main (){
    Solution S1;
    std::string blocks = "WBWBBBW";//size = 10
    int k = 2;
    std::cout << S1.minimumRecolors(blocks,k) << std::endl;
    return 0;
}