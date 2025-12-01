#include <gtest/gtest.h>
#include <string> 
#include "aoc-01.h"

TEST(AoC_01, Case_1) {
	const std::string testCase = "\
L68\n\
L30\n\
R48\n\
L5\n\
R60\n\
L55\n\
L1\n\
L99\n\
R14\n\
L82\n";

	std::vector<AoC::instruction> instructions = AoC::ParseInstructions(testCase); 

	uint64_t res = AoC::PickLock(50, instructions);

	ASSERT_EQ(res, 3);
}
