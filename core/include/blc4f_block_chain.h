#ifndef __BLOCK_CHAIN_4FUN_BLOCK_
#define __BLOCK_CHAIN_4FUN_BLOCK_

#include "blc4f_transaction.h"

#include <vector>
#include <string>


void TestCurl();
void TestCppRest();
std::string TestSha256(const std::string str);

namespace blc4f {
	/**
	*	block = {
	*		'index':
	*		'timestamps:
	*		'transaction': [
	*			{
	*				'sender':
	*				'recipient':
	*				'amount':
	*			}
	*		],
	*		'proof':
	*		'previous_hash':
	*	}
	*/
	class Blc4fBlockChain {
	public:
		Blc4fBlockChain();
		virtual ~Blc4fBlockChain();

		void CreateBlock(std::string previous_hash, std::string proof);

		std::vector<Blc4fTransaction> m_current_transaction;
		std::vector<Blc4fBlockChain> m_chain;
		std::string m_previous_hash;
		std::string m_proof;

	private:
		std::string Hashing(Blc4fBlockChain block);
		//test checkin github

	};

}

#endif //__BLOCK_CHAIN_4FUN_