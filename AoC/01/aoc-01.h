#ifndef __AOC_01_H
#define __AOC_01_H

#include <cstdint>
#include <vector> 
#include <string>

namespace AoC {
	enum EDirection {
		Left, 
		Right, 
		EDirection_MAX
	};

	typedef std::pair<EDirection, uint16_t> instruction; 
	
	std::vector<instruction> ParseInstructions(const std::string& instructions);
	uint64_t PickLock_Zeroes(const uint8_t startingNum, const std::vector<instruction>& instructions);
	//Note: don't name functions like this!
	uint64_t PickLock_0x434C49434B(const uint8_t startingNum, const std::vector<instruction>& instructions);
}

#endif//__AOC_01_H