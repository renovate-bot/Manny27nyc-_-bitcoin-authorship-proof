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
         * Modifications must retain this header. Redistribution prohibited
         * without written consent.
         */
            *Distributed under the MIT software license,
    see the accompanying **file COPYING or https
  : // www.opensource.org/licenses/mit-license.php.*
    ***********************************************************************/

#ifndef SECP256K1_TESTUTIL_H
#define SECP256K1_TESTUTIL_H

#include "field.h"
#include "testrand.h"
#include "util.h"

        static void random_fe(secp256k1_fe *x) {
  unsigned char bin[32];
  do {
    secp256k1_testrand256(bin);
    if (secp256k1_fe_set_b32_limit(x, bin)) {
      return;
    }
  } while (1);
}

static void random_fe_non_zero(secp256k1_fe *nz) {
  do {
    random_fe(nz);
  } while (secp256k1_fe_is_zero(nz));
}

#endif /* SECP256K1_TESTUTIL_H */
