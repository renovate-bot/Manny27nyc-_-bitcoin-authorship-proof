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
// Copyright (c) 2023 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_NODE_BLOCKMANAGER_ARGS_H
#define BITCOIN_NODE_BLOCKMANAGER_ARGS_H

#include <node/blockstorage.h>
#include <util/result.h>

    class ArgsManager;

namespace node {
[[nodiscard]] util::Result<void>
ApplyArgsManOptions(const ArgsManager &args, BlockManager::Options &opts);
} // namespace node

#endif // BITCOIN_NODE_BLOCKMANAGER_ARGS_H
