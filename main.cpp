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
    return {-1, -1};
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
    return {-1, -1};
}

int main() {
    std::vector<std::vector<int>> tests = {{15, 4, 18, 8, 19, 22, 24, 59, 20, 18, 12, 36, 42, 9},
    {1, 5, 3},
    {2, 4, 8, 16},
    {9, 10, 7, 8},
    {0, 11, 0, 33, 44}};
    std::vector<int> tars = {24, 5, 18, 17, 0};
    std::string bValid;
    std::string hValid;

    for(int i = 0; i < (tests.size()); i++) {
        std::pair<int, int> bRes = twoSumBruteForce(tests[i], tars[i]);
        std::pair<int, int> hRes = twoSumHash(tests[i], tars[i]);
        std::cout<< "test case " << i + 1;
        if(bRes.first == -1 or hRes.first == -1){
            std::cout<< "\nno solution exists\n\n";
        }
        else{
            if(tests[i][bRes.first] + tests[i][bRes.second] == tars[i]){
                bValid = "\n= " + std::to_string(tars[i]) + "? valid\n";
            }
            else{
                bValid = "\n= " + std::to_string(tars[i]) + "? invalid\n";
            }

            if(tests[i][hRes.first] + tests[i][hRes.second] == tars[i]){
                hValid = "\n= " + std::to_string(tars[i]) + "? valid\n";
            }
            else{
                hValid = "\n= " + std::to_string(tars[i]) + "? invalid\n";
            }
            std::cout<< "\nbruteforce\n[" << bRes.first << ", " << bRes.second << "]\n" << tests[i][bRes.first] << ", " << tests[i][bRes.second] << bValid << "hashmap\n[" << hRes.first << ", " << hRes.second << "]\n" << tests[i][hRes.first] << ", " << tests[i][hRes.second] << hValid << "\n";
        }
    }
}