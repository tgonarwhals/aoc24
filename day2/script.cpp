#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


std::vector<int> split(const std::string& s) {
    std::stringstream ss(s);
    std::vector<std::string> words;
    std::vector<int> nums;
    for(std::string w; ss>>w;) words.push_back(w);
    for(int i = 0; i < words.size(); i++) {
        nums.push_back(std::stoi(words[i]));
    }
    return nums;
}
bool increasing(int num1, int num2) {
    return (num1 < num2);
}


int main() {

    std::ifstream input("input.txt");
    std::string line;

    int num_safe = 0;
    while (std::getline(input, line)) {
        std::vector<int> nums = split(line);
        // std::cout << nums.size() << std::endl;
        bool flag = true;
        if (increasing(nums[0], nums[1])) { //numbers are increasing, should continue increasing
            for (int i = 0; i < nums.size() - 1; i++) {
                if((nums[i+1] - nums[i]) <= 3 && (nums[i+1] - nums[i]) > 0) {
                    // still increasing in a safe margin; do nothing
                } else {
                    flag = false;
                    break;
                }
            }
        } else { // numbers are decreasing, should continue decreasing
            for (int i = 0; i < nums.size() - 1; i++) {
                if((nums[i] - nums[i+1]) <= 3 && (nums[i] - nums[i+1]) > 0) {
                    // still decreasing in a safe margin; do nothing
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {num_safe++;}
    }

    std::cout << num_safe << std::endl;
    
    return 0;
}