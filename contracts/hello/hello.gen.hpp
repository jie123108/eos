#pragma once
#include <eoslib/types.hpp>
#include <eoslib/message.hpp>
#include <eoslib/datastream.hpp>
#include <eoslib/raw_fwd.hpp>

namespace eosio { namespace raw {
   template<typename Stream> inline void pack( Stream& s, const transfer& value ) {
      raw::pack(s, value.from);
      raw::pack(s, value.to);
      raw::pack(s, value.quantity);
   }
   template<typename Stream> inline void unpack( Stream& s, transfer& value ) {
      raw::unpack(s, value.from);
      raw::unpack(s, value.to);
      raw::unpack(s, value.quantity);
   }
   template<typename Stream> inline void pack( Stream& s, const login& value ) {
      raw::pack(s, value.username);
      raw::pack(s, value.password);
      raw::pack(s, value.code);
   }
   template<typename Stream> inline void unpack( Stream& s, login& value ) {
      raw::unpack(s, value.username);
      raw::unpack(s, value.password);
      raw::unpack(s, value.code);
   }
} }

#include <eoslib/raw.hpp>
namespace eosio {
   void print_ident(int n){while(n-->0){print("  ");}};
   template<typename Type>
   Type current_message_ex() {
      uint32_t size = message_size();
      char* data = (char *)eosio::malloc(size);
      assert(data && read_message(data, size) == size, "error reading message");
      Type value;
      eosio::raw::unpack(data, size, value);
      eosio::free(data);
      return value;
   }
   void dump(const transfer& value, int tab=0) {
      print_ident(tab);print("from:[");printn(value.from);print("]\n");
      print_ident(tab);print("to:[");printn(value.to);print("]\n");
      print_ident(tab);print("quantity:[");printi(uint64_t(value.quantity));print("]\n");
   }
   template<>
   transfer current_message<transfer>() {
      return current_message_ex<transfer>();
   }
   void dump(const login& value, int tab=0) {
      print_ident(tab);print("username:[");prints_l(value.username.get_data(), value.username.get_size());print("]\n");
      print_ident(tab);print("password:[");prints_l(value.password.get_data(), value.password.get_size());print("]\n");
      print_ident(tab);print("code:[");printi(uint64_t(value.code));print("]\n");
   }
   template<>
   login current_message<login>() {
      return current_message_ex<login>();
   }
} //eosio

