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
		Blc4fTransaction(std::string sender, std::string recipient, uint32_t amount)
			:m_sender(sender), m_recipient(m_recipient), m_amount(amount) {}
		virtual ~Blc4fTransaction();

		std::string m_sender;
		std::string m_recipient;
		uint32_t m_amount;

		
	};
}



#endif 
