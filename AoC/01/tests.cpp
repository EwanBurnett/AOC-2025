#include <gtest/gtest.h>
#include <string> 
#include "aoc-01.h"

TEST(AoC_01, Case_1) {
	const std::string testCase = "\
		L68\
		L30\
		R48\
		L5\
		R60\
		L55\
		L1\
		L99\
		R14\
		L82\n";

	std::vector<AoC::instruction> instructions = AoC::ParseInstructions(testCase); 

	uint64_t res = AoC::PickLock(50, instructions);

	ASSERT_EQ(res, 3);
}
