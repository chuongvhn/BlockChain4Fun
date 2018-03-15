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
		explicit Blc4fTransaction(std::string const sender, std::string const recipient, uint32_t const amount ) 
			:m_sender(sender), m_recipient(recipient), m_amount(amount) {}
		virtual ~Blc4fTransaction();

		std::string m_sender;
		std::string m_recipient;
		uint32_t m_amount;

		
	};
}



#endif 
