#include <iostream>
#include <bitset>
#include <string>


bool ispalindrome(std::string s) {
    if (s.size() < 2) return true;
    int end = s.size() - 1;
    // std::cout << "begin: " << s[0] << ", end: " << s[end] << std::endl;
    // std::cout << "calling on " << s.substr(1, end-1) << std::endl;
    // std::cout << s.size() << std::endl;
    if (s[0] == s[end]) return ispalindrome(s.substr(1, end-1));
    return false;
}

std::string removeleadingzeros(std::string s) {
    int index = 0;
    while (index < s.size()) {
        if (s[index] == '1') break;
        index++;
    }
    if (index == s.size() ) return "0";
    return s.substr(index, s.size() - 1);
}


int main () {
    int sum = 0;

    for(int i = 0; i < 1000000; i++ ) {
        // std::cout << i << std::endl;
        std::string binary = removeleadingzeros(std::bitset<32>(i).to_string());
        if (ispalindrome(std::to_string(i))) {
            // std::cout << removeleadingzeros(binary) << std::endl;
            if (ispalindrome(binary)) {
                sum += i;
                std::cout << "found palindrome: " << i << ", " << binary <<  std::endl;
            }
        }
    }
    
    std::cout << sum << std::endl;
    return 0;
}

// 554455
// 10001110111101110001
// 10001110111101110001

// 73737
// 10010000000001001
// 10010000000001001
