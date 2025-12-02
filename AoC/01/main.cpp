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
    std::string input = {};
    uint32_t startingNum = 50u; 

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-i") == 0 && input.empty()) {
            printf("Loading input [%s]\n", argv[i + 1]); 
            input = LoadInputFile(argv[++i]);
        }

        if (strcmp(argv[i], "-h") == 0) {
            printf("Help:\n\t-h - Display this help page.\n\t-i - Process a given input text file.\n\t-s - Set the starting count.\n");
        }

        if (strcmp(argv[i], "-s") == 0) {
            startingNum = std::atoi(argv[++i]); 
            printf("Setting starting number to %d.\n", startingNum); 
        }

    }

    if (argc <= 1) {    
        printf("Help:\n\t-h - Display this help page.\n\t-i - Process a given input text file.\n\t-s - Set the starting count.\n");
    }

    if (input.empty()) {
        printf("Loading default input (input.txt)\nTo override, launch the application using -i [input]. See help for more. (-h)\n");
        input = LoadInputFile("input.txt");
    }



    auto instructions = AoC::ParseInstructions(input);
    uint32_t code = AoC::PickLock_Zeroes(startingNum, instructions);
    uint32_t code_2 = AoC::PickLock_0x434C49434B(startingNum, instructions);

    printf("Cracked Code (Zeroes): %d\n", code);
    printf("Cracked Code (0x434C49434B): %d\n", code_2);

    return 0;
}