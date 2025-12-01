#include <cstdio> 
#include <string>
#include <fstream>
#include "aoc-01.h"

std::string LoadInputFile(const std::string& path) {
    std::string input = {}; 
    printf("Processing input file [%s].\n", path.c_str());

    std::ifstream file(path, std::ios::ate);
    if (!file.is_open() || !file.good()) {
        printf("Bad File!\n");
        file.close();
        return {};
    }

    size_t sz = file.tellg();
    input.resize(sz);

    file.seekg(0);
    file.read(&input[0], input.size());

    file.close();

    return input; 
}
int main(int argc, char** argv) {
    printf("Hello AoC!\n"); 

    if (argc <= 1 || strcmp(argv[1], "-h") == 0){
        printf("Help:\n\t-h - Display this help page.\n\t-i - Process an input text file."); 
    }

    std::string input = {}; 

    if (argc > 1) {
        if (strcmp(argv[1], "-i") == 0) {
            input = LoadInputFile(argv[2]); 
        }
    }
    if (input.empty()) {
        input = LoadInputFile("input.txt"); 
    }
    
    printf("Input: \n%s\n", input.c_str()); 

    uint32_t startingNum = 50u; //TODO: cmd

    auto instructions = AoC::ParseInstructions(input); 
    uint32_t code = AoC::PickLock(startingNum, instructions); 

    printf("Cracked Code: %d\n", code); 

    return 0; 
}