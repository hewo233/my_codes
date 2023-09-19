#include <bits/stdc++.h>

int main() {
    int number = 12345;
    
    // 使用字符串流将整数转换为字符串
    std::stringstream ss;
    ss << number;
    std::string strNumber = ss.str();
    
    // 将字符串转换为字符数组
    char charArray[strNumber.length() + 1];
    strcpy(charArray, strNumber.c_str());
    
    // 打印字符数组
    std::cout << "Character Array: " << charArray << std::endl;
    
    return 0;
}