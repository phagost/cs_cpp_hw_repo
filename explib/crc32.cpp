#include "crc32.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

void crc32(std::ifstream &ifs){

unsigned long crc_table[256];
unsigned long crc;
for (int i = 0; i < 256; i++)
{
crc = i;
for (int j = 0; j < 8; j++)
crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;

crc_table[i] = crc;
}

crc = 0xFFFFFFFFUL;

const unsigned BUFSIZE = 4;
std::vector<char> buffer(BUFSIZE);
unsigned long crc32_num(unsigned char *buf, unsigned long len, unsigned long crc);

while (true)
{
ifs.read(&buffer[0], buffer.size());
const unsigned n = ifs.gcount();
if (!n)
break;
std::string s(&buffer[0], n);
// string to the array of unsigned chars
unsigned char trap[256];
std::copy( s.begin(), s.end(), trap );
trap[s.length()] = 0;
crc=crc32_num(trap,4,crc);
}

    std::cout << crc << std::endl;
}

unsigned long crc32_num(unsigned char *buf, unsigned long len, unsigned long crc) {
    unsigned long crc_table[256];
    while (len--)
        crc = crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);

    return crc ^ 0xFFFFFFFFUL;
}