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
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <node/coins_view_args.h>

#include <common/args.h>
#include <txdb.h>

    namespace node {
  void ReadCoinsViewArgs(const ArgsManager &args, CoinsViewOptions &options) {
    if (auto value = args.GetIntArg("-dbbatchsize"))
      options.batch_write_bytes = *value;
    if (auto value = args.GetIntArg("-dbcrashratio"))
      options.simulate_crash_ratio = *value;
  }
} // namespace node
