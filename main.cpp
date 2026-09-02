#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

std::pair<int, int> twoSumBruteForce(const std::vector<int>& nums, int target){
    for(int i = 0; i < static_cast<int>(nums.size()); i++){
        for(int j = i + 1; j < static_cast<int>(nums.size()); j++){
            if(nums[i] + nums[j] == target){
                return {i, j};
            }
        }
    }
    return {};
}

std::pair<int, int> twoSumHash(const std::vector<int>& nums, int target){
    std::unordered_map<int, int> map;
    for(int i = 0; i < static_cast<int>(nums.size()); i++){
        int rem = target - nums[i];
        if(map.find(rem) != map.end()){
            return {map[rem], i};
        }
        else{
            map[nums[i]] = i;
        }
    }
    return {};
}

int main() {
    std::vector<std::vector<int>> tests = {{15, 4, 18, 8, 19, 22, 24, 59, 20, 18, 12, 36, 42, 9},
    {1, 2, 3},
    {2, 4, 8, 16},
    {10, 9, 8, 7},
    {0, 11, 0, 33, 44}};
    std::vector<int> tars = {24, 5, 18, 17, 44};

    std::string bValid;
    std::string hValid;

    for(int i = 0; i < static_cast<int>(tests.size()); i++){
        std::pair<int, int> bRes = twoSumBruteForce(tests[i], tars[i]);
        std::pair<int, int> hRes = twoSumHash(tests[i], tars[i]);

        if(tests[i][bRes.first] + tests[i][bRes.second] == tars[i]){
            bValid = "= " + std::to_string(tars[i]) + "? valid";
        }
        else{
            bValid = "= " + std::to_string(tars[i]) + "? invalid";
        }

        if(tests[i][hRes.first] + tests[i][hRes.second] == tars[i]){
            hValid = "= " + std::to_string(tars[i]) + "? valid";
        }
        else{
            hValid = "= " + std::to_string(tars[i]) + "? invalid";
        }

        std::cout<<"[" << bRes.first << ", " << bRes.second << "]\n" << tests[i][bRes.first] << ", " << tests[i][bRes.second] << "\n" << bValid << 		"\n[" << hRes.first << ", " << hRes.second << "]\n" << tests[i][hRes.first] << ", " << tests[i][hRes.second] << "\n" << hValid << "\n\n";
    }
}