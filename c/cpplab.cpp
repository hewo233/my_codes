#include <bits/stdc++.h>

int main() {
    int number = 12345;
    
    // ʹ���ַ�����������ת��Ϊ�ַ���
    std::stringstream ss;
    ss << number;
    std::string strNumber = ss.str();
    
    // ���ַ���ת��Ϊ�ַ�����
    char charArray[strNumber.length() + 1];
    strcpy(charArray, strNumber.c_str());
    
    // ��ӡ�ַ�����
    std::cout << "Character Array: " << charArray << std::endl;
    
    return 0;
}