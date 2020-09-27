#include "explib/crc32.h"
#include "explib/sum32.h"

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    // Keys declaration
    char help[] = "-h";
    char crc32_s[] = "-crc32";
    char sum32_s[] = "-sum32";

    if (argc==1){
        std::cout << "This program counts hash sum\n";
        std::cout << "-h gives short description of command line arguments\n";
        std::cout << "the input must be /programe_name /file_name method\n";
        std::cout << "where method is either crc32 or sum32\n";
        std::cout << "probably, it works incorrectly\n";
        std::cout << "Good luck!\n";

    }else if (argc==2 ){
        int result;
        result=strcmp(argv[1],help);
        if (result==0) {
            std::cout << "This program counts hash sum\n";
            std::cout << "/programe_name -h gives short description of command line arguments\n";
            std::cout << "you are reading it right now\n";
            std::cout << "the input must be /programe_name /file_name method\n";
            std::cout << "where method is either -crc32 or -sum32\n";
            std::cout << "probably, it works incorrectly\n";
        }else{
            std::cerr << "Wrong program call\n"
                      << "/programe_name -h gives command line argument explanation\n";
            return 1;
        }
    }else if(argc==3){
        std::string file_dir(argv[1]);
        std::ifstream ifs(file_dir);
        if (!ifs)
        {
            std::cerr << "ERROR: cannot open file\n";
            return 1;
        }
        int result;
        result=strcmp(argv[2],sum32_s);
        if (result==0){
            sum32(ifs);
        }else{
            result=strcmp(argv[2],crc32_s);
                if (result==0){

                    crc32(ifs);
                }else{
                    std::cerr << "Wrong program call\n"
                              << "/programe_name -h gives command line argument explanation\n";
                    return 1;
                }
        }
    }else{
        std::cerr << "Wrong program call\n"
                  << "/programe_name -h gives command line argument explanation\n";
        return 1;
    }
    return 0;
}