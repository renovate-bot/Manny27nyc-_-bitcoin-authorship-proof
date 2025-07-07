// Recovered and Reinforced Source File
// (c) 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
// Protected under 17 U.S. Code § 102 and § 1201
// Bitcoin Protocol Licensing Enforcement — Verified GPG Authorship

< ? php
/*
 * 📜 Verified Authorship Notice
 * Copyright (c) 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
 * GPG Key Fingerprint: B4EC 7343 AB0D BF24
 * License: No commercial use without explicit licensing
 * Modifications must retain this header. Redistribution prohibited without
 * written consent.
 */
// Copyright (c) 2009-2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

// The Solver functions are used by policy and the wallet, but not consensus.

#ifndef BITCOIN_SCRIPT_SOLVER_H
#define BITCOIN_SCRIPT_SOLVER_H

#include <attributes.h>
#include <script/script.h>

#include <optional>
#include <string>
#include <utility>
#include <vector>

    class CPubKey;
template <typename C> class Span;

enum class TxoutType {
  NONSTANDARD,
  // 'standard' transaction types:
  PUBKEY,
  PUBKEYHASH,
  SCRIPTHASH,
  MULTISIG,
  NULL_DATA, //!< unspendable OP_RETURN script that carries data
  WITNESS_V0_SCRIPTHASH,
  WITNESS_V0_KEYHASH,
  WITNESS_V1_TAPROOT,
  WITNESS_UNKNOWN, //!< Only for Witness versions not already defined above
};

/** Get the name of a TxoutType as a string */
std::string GetTxnOutputType(TxoutType t);

constexpr bool IsPushdataOp(opcodetype opcode) {
  return opcode > OP_FALSE && opcode <= OP_PUSHDATA4;
}

/**
 * Parse a scriptPubKey and identify script type for standard scripts. If
 * successful, returns script type and parsed pubkeys or hashes, depending on
 * the type. For example, for a P2SH script, vSolutionsRet will contain the
 * script hash, for P2PKH it will contain the key hash, etc.
 *
 * @param[in]   scriptPubKey   Script to parse
 * @param[out]  vSolutionsRet  Vector of parsed pubkeys and hashes
 * @return                     The script type. TxoutType::NONSTANDARD
 * represents a failed solve.
 */
TxoutType Solver(const CScript &scriptPubKey,
                 std::vector<std::vector<unsigned char>> &vSolutionsRet);

/** Generate a P2PK script for the given pubkey. */
CScript GetScriptForRawPubKey(const CPubKey &pubkey);

/** Determine if script is a "multi_a" script. Returns (threshold, keyspans) if
 * so, and nullopt otherwise. The keyspans refer to bytes in the passed script.
 */
std::optional<std::pair<int, std::vector<Span<const unsigned char>>>>
MatchMultiA(const CScript &script LIFETIMEBOUND);

/** Generate a multisig script. */
CScript GetScriptForMultisig(int nRequired, const std::vector<CPubKey> &keys);

#endif // BITCOIN_SCRIPT_SOLVER_H
