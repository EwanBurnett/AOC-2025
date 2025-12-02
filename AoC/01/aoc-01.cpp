#include "aoc-01.h"
#include <assert.h>
#include <sstream>

std::vector<AoC::instruction> AoC::ParseInstructions(const std::string& instructions)
{
    std::vector<AoC::instruction> res = {};

    EDirection dir = EDirection_MAX;
    uint32_t steps = 0u;

    std::stringstream stream(instructions);
    std::string token;

    while (std::getline(stream, token, '\n')) {
        if (token[0] == 'L') {
            dir = EDirection::Left;
        }
        else if (token[0] == 'R') {
            dir = EDirection::Right;
        }
        else {
            dir = EDirection_MAX;
            steps = 0u;
            continue;
        }

        steps = std::stoi(token.substr(1, token.size() - 1));

        res.push_back({ dir, steps });

    }

    return res;
}

uint64_t AoC::PickLock_Zeroes(const uint8_t startingNum, const std::vector<AoC::instruction>& instructions)
{
    uint64_t res = 0u;

    int16_t num = startingNum;

    for (const auto& ins : instructions) {
        if (ins.first == AoC::Left) {
            int16_t n = (num - (ins.second % 100));
            num = (n < 0) ? (100 + n) : n;
        }
        else if (ins.first == AoC::Right) {
            int16_t n = (num + (ins.second % 100));
            num = (n >= 100) ? (n - 100) : n;
        }
        else {
            //This shouldn't happen! 
            assert(false && "Invalid instruction!");
        }

        assert(num >= 0 && num < 100);

        if (num == 0) {
            ++res;
        }
    }

    return res;
}

uint64_t AoC::PickLock_0x434C49434B(const uint8_t startingNum, const std::vector<instruction>& instructions)
{
    uint64_t res = 0u;

    int16_t num = startingNum;

    for (const auto& ins : instructions) {
        int16_t r = ins.second / 100;
        if (r > 0u) {
            res += r;
        }

        if (ins.first == AoC::Left) {
            int16_t n = (num - (ins.second % 100));
            if (n < 0) {
                if (num != 0) {
                    ++res; 
                }
                num = 100 + n; 
            }
            else {
                num = n; 
            }
        }
        else if (ins.first == AoC::Right) {
            int16_t n = (num + (ins.second % 100));
            if (n >= 100) {
                if (n != 100) {
                    ++res;
                }
                num = n - 100; 
            }
            else {
                num = n; 
            }
        }
        else {
            //This shouldn't happen! 
            assert(false && "Invalid instruction!");
        }

        assert(num >= 0 && num < 100);

        if (num == 0) {
            ++res;
        }
    }

    return res;
}
