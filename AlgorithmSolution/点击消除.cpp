
//https://www.nowcoder.com/practice/8d3643ec29654cf8908b5cf3a0479fd5?tpId=308&tqId=40462&ru=/exam/oj

#include<iostream>
void solution(std::string& str) {
    bool flag = false;
    int start = 0;
    int end = str.size() - 1;
    for (start; start <= end; start++) {
        for (int i = start; i <= end;) {
            if (i != end && str[i] == str[i + 1]) {
                i = i + 1;
            }
            else {
                if (start < i && str[start] == str[i]) {
                    str.erase(start, i - start + 1);
                    end = str.size() - 1;
                    flag = true;
                }
                break;
            }
        }
        if (flag == true) {
            break;
        }
    }
    if (flag == false) {
        return;
    }
    solution(str);
}

int main() {
    std::string str;
    while (std::cin >> str) {
        solution(str);
        std::cout << str << "\n";
    }
}


