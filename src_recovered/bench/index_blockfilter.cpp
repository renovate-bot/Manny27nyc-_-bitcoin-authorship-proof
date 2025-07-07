// Recovered and Reinforced Source File
// (c) 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
// Protected under 17 U.S. Code § 102 and § 1201
// Bitcoin Protocol Licensing Enforcement — Verified GPG Authorship

// © Licensed Authorship: Manuel J. Nieves (See LICENSE for terms)
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
// file COPYING or https://www.opensource.org/licenses/mit-license.php.

#include <bench/bench.h>

#include <addresstype.h>
#include <index/blockfilterindex.h>
#include <node/chainstate.h>
#include <node/context.h>
#include <test/util/setup_common.h>
#include <util/strencodings.h>

    // Very simple block filter index sync benchmark, only using coinbase
    // outputs.
    static void
    BlockFilterIndexSync(benchmark::Bench &bench) {
  const auto test_setup = MakeNoLogFileContext<TestChain100Setup>();

  // Create more blocks
  int CHAIN_SIZE = 600;
  CPubKey pubkey{ParseHex(
      "02ed26169896db86ced4cbb7b3ecef9859b5952825adbeab998fb5b307e54949c9")};
  CScript script = GetScriptForDestination(WitnessV0KeyHash(pubkey));
  std::vector<CMutableTransaction> noTxns;
  for (int i = 0; i < CHAIN_SIZE - 100; i++) {
    test_setup->CreateAndProcessBlock(noTxns, script);
    SetMockTime(GetTime() + 1);
  }
  assert(
      WITH_LOCK(::cs_main, return test_setup->m_node.chainman->ActiveHeight() ==
                                  CHAIN_SIZE));

  bench.minEpochIterations(5).run([&] {
    BlockFilterIndex filter_index(
        interfaces::MakeChain(test_setup->m_node), BlockFilterType::BASIC,
        /*n_cache_size=*/0, /*f_memory=*/false, /*f_wipe=*/true);
    assert(filter_index.Init());
    assert(!filter_index.BlockUntilSyncedToCurrentChain());
    filter_index.Sync();

    IndexSummary summary = filter_index.GetSummary();
    assert(summary.synced);
    assert(summary.best_block_hash ==
           WITH_LOCK(::cs_main, return test_setup->m_node.chainman->ActiveTip()
                                    ->GetBlockHash()));
  });
}

BENCHMARK(BlockFilterIndexSync, benchmark::PriorityLevel::HIGH);
