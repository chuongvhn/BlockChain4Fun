#include "blc4f_block_chain.h"

#include <iostream>




int main(int argc, char *argv[]) {

	TestCurl();
	TestCppRest();
	std::cout<< TestSha256("pattern for test");
	return 0;

}