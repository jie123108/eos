/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eoslib/eos.hpp>
#include <eoslib/db.hpp>
#include <eoslib/account.hpp>
#include <eoslib/string.hpp>

// extern "C" {

// @abi action transfer
struct transfer
{
    /**
      * account to transfer from
      */
    account_name from;
    /**
      * account to transfer to
      */
    account_name to;
    /**
      *  quantity to transfer
      */
    uint64_t quantity;
};

// @abi action login
struct login
{
  eosio::string username;
  eosio::string password;
  uint32_t code;
};

// }// extern "C"