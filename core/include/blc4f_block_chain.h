#ifndef __BLOCK_CHAIN_4FUN_BLOCK_
#define __BLOCK_CHAIN_4FUN_BLOCK_

#include "blc4f_transaction.h"

#include <vector>
#include <string>
#include <stdint.h>


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

		//Create new block and add to chain
		void NewBlock(std::string & previous_hash, std::string & proof);
		//Create new transaction for a block
		Blc4fTransaction NewTransaction(std::string const & sender, std::string const & recipient,
										uint32_t amount );
		Blc4fBlockChain GetLastBlock(void) const;

		std::vector<Blc4fTransaction> m_current_trans_list;
		std::vector<Blc4fBlockChain> m_chain;
		std::string m_previous_hash;
		double m_proof;

	private:
		std::string Hashing(Blc4fBlockChain block);
		bool ValidateProof(double last_proof, double proof);
		void ProofOfWork(double last_proof);

	};

}

#endif //__BLOCK_CHAIN_4FUN_