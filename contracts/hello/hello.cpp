/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <hello.hpp>

/**
 *  The init() and apply() methods must have C calling convention so that the blockchain can lookup and
 *  call these methods.
 */
extern "C" {
    /**
     *  This method is called once when the contract is published or updated.
     */
    void init()  {
       eosio::print( "005 Init World!\n" );
    }

    /// The apply method implements the dispatch of events to this contract
    void apply( uint64_t code, uint64_t action ) {
       eosio::print( "005 Hello World: ", eosio::name(code), "->", eosio::name(action), "\n" );
		if(action == N(transfer)){
			// transfer message;
			// static_assert(sizeof(message) == 3*sizeof(uint64_t), "unexpected padding");
			// auto read = read_message(&message, sizeof(message));
			// assert(read == sizeof(message), "message too short");
            auto message = eosio::current_action<transfer>();
            eosio::print("Transfer ", message.quantity, " from ", eosio::name(message.from), " to ", eosio::name(message.to), "\n");
		}else 
        if (action == N(login)) {
            auto msg = eosio::current_action<login>();
            eosio::print("Username: ", msg.username, "\nPassword: ", msg.password, "\nCode: ", msg.code);
            // eosio::print("Username: ", msg.username, "\nCode: ", msg.code);
        }
    }

} // extern "C"
