#include "sum32.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <bitset>

void sum32(std::ifstream &ifs){

    const unsigned BUFSIZE = 4;
    std::vector<char> buffer(BUFSIZE);
    unsigned long sum = 0;

    while (true)
    {
        ifs.read(&buffer[0], buffer.size());
        const unsigned n = ifs.gcount();
        if (!n)
            break;

        std::string s(&buffer[0], n);
        std::bitset<8> x;
        for (int i = 0; i < s.size(); i += 1) {
            x = std::bitset<8>(s[i]);//.to_string();// + std::bitset<8>(s[i + 1]).to_string();
            for (int j = 0; j <= 8; j += 1) {
                if (x[j] == true) {
                    sum = sum + pow(2, (8 - j) * (4 - i));
                }
            }
        }
    }
    std::cout << sum << std::endl;

}