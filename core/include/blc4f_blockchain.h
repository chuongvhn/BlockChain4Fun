#ifndef __BLOCK_CHAIN_4FUN_BLOCK_
#define __BLOCK_CHAIN_4FUN_BLOCK_

#include "blc4f_transaction.h"

#include <vector>
#include <string>
#include <stdint.h>
#include <memory>


void TestCurl();
void TestCppRest();

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
		void NewBlock();

		//Create new transaction for a block
		Blc4fTransaction NewTransaction( std::string const & sender, 
										 std::string const & recipient,
										 uint32_t const amount );

		Blc4fBlockChain GetLastBlock(void) const;

		std::string ToString() const;
		std::vector<Blc4fTransaction> m_current_trans_list;

		//chain should be persistent storage in final version
		//for demo version by now made it via smart pointer as a handy way
		std::vector<Blc4fBlockChain> m_chain;
		std::string m_previous_hash;
		double m_proof;

	private:
		double m_index;
		double m_time_stamp;
		std::string Sha256(const std::string str);

		bool ValidateProof(double last_proof, double proof);

		void ProofOfWork(double last_proof);

		std::string TransToString() const;
		void ClearBlock();

	};

}

#endif //__BLOCK_CHAIN_4FUN_