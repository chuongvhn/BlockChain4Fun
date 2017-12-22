#ifndef __BLOCK_CHAIN_4FUN_TRANSACTION_
#define __BLOCK_CHAIN_4FUN_TRANSACTION_



#include <string>


namespace blc4f {
	/**
	*	transaction = {
	*		'sender':
	*		'recipient':
	*		'amount':
	*	}
	*/
	class Blc4fTransaction {
	public:
		Blc4fTransaction();
		virtual ~Blc4fTransaction();

		std::string m_sender;
		std::string m_recipient;
		std::string m_amount;

		
	};
}



#endif 
