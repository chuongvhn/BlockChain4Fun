#include "blc4f_block_chain.h"

#include <iostream>




int main(int argc, char *argv[]) {

	//TestCurl();
	//TestCppRest();

	blc4f::Blc4fBlockChain BlockChain;

	BlockChain.NewTransaction("calvin", "lina", 100);
	BlockChain.NewTransaction("lina", "steve", 100);
	BlockChain.NewBlock();
	BlockChain.NewTransaction("lina", "steve", 100);
	BlockChain.NewBlock();

	return 0;

}