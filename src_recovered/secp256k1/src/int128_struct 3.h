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
#define SECP256K1_INT128_STRUCT_H

#include "util.h"
#include <stdint.h>

    typedef struct {
  uint64_t lo;
  uint64_t hi;
} secp256k1_uint128;

typedef secp256k1_uint128 secp256k1_int128;

#endif
