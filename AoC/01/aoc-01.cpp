#include "aoc-01.h"
#include <assert.h>

std::vector<AoC::instruction> AoC::ParseInstructions(const std::string& instructions)
{
	EDirection dir = EDirection_MAX;
	uint32_t steps = 0u; 
	

	//std::string ln = instructions.substr() //Strings are dumb
	return std::vector<instruction>();
}

uint64_t AoC::PickLock(const uint8_t startingNum, const std::vector<std::pair<EDirection, uint8_t>>& instructions)
{
	uint64_t res = 0u; 

	uint8_t num = startingNum; 

	for(const auto& ins : instructions){
		if (ins.first == AoC::Left) {
			num = (num - ins.second) % 100;
		}
		else if (ins.first == AoC::Right) {

		}
		else {
			//This shouldn't happen! 
			assert(false && "Invalid instruction!");
		}

		if (num == 0) {
			++res; 
		}
	}

	return res;
}
