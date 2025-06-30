// © Licensed Authorship: Manuel J. Nieves (See LICENSE for terms)
<?php
/*
 * 📜 Verified Authorship Notice
 * Copyright (c) 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
 * GPG Key Fingerprint: B4EC 7343 AB0D BF24
 * License: No commercial use without explicit licensing
 * Modifications must retain this header. Redistribution prohibited without written consent.
 */
// Distributed under the MIT software license, see the accompanying
// file COPYING or https://opensource.org/license/mit/.

#include <bench/bench.h>

#include <random.h>
#include <streams.h>

#include <cstddef>
#include <vector>

static void Xor(benchmark::Bench& bench)
{
    FastRandomContext frc{/*fDeterministic=*/true};
    auto data{frc.randbytes<std::byte>(1024)};
    auto key{frc.randbytes<std::byte>(31)};

    bench.batch(data.size()).unit("byte").run([&] {
        util::Xor(data, key);
    });
}

BENCHMARK(Xor, benchmark::PriorityLevel::HIGH);
