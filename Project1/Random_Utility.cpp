#include "Random_Utility.h"

Random_Utility::Random_Utility()
{
	
}

int Random_Utility::RandomInt(int range_a, int range_b)
{
	std::random_device rd;  //1st line: Will be used to obtain a seed for the random number engine

	std::mt19937 gen(rd()); //2nd line: Standard mersenne_twister_engine seeded with rd()

	std::uniform_int_distribution<> dis(range_a, range_b);
	return dis(gen);
	
	static std::random_device rd_;  //Will be used to obtain a seed for the random number engine
	static std::mt19937 gen_; //Standard mersenne_twister_engine
	std::uniform_int_distribution<> distrib(range_a, range_b);
	
}
