/*! @file hash.c
 *  @brief Wraps the SHA-3 implementation.
 *
 *  This file is part of the reference implementation of the Picnic signature scheme.
 *  See the accompanying documentation for complete details.
 *
 *  The code is provided under the MIT license, see LICENSE for
 *  more details.
 *  SPDX-License-Identifier: MIT
 */

#include "hash.h"
#include <stdio.h>
#include <assert.h>
#include "sha3/brg_endian.h"

void HashUpdate(HashInstance* ctx, const uint8_t* data, size_t byteLen)
{
//	static size_t bytelen_max = 0;
//	if(bytelen_max < byteLen) {
//		printf("bytelen max = %d, bytelen = %d\n",bytelen_max, byteLen);
//		bytelen_max = byteLen;
//	}
    HashReturn ret = Keccak_HashUpdate(ctx, data, byteLen * 8);

//    if (ret != SUCCESS) {
//        fprintf(stderr, "%s: Keccak_HashUpdate failed (returned %d)\n", __func__, ret);
//        assert(!"Keccak_HashUpdate failed");
//    }
}

void HashUpdate_2(HashInstance* ctx, const uint32_t* data, size_t byteLen)
{
	uint8_t temp[75] = {0};
	uint32_t temp2;
	int loop;
	HashUpdate_2_label2:for(loop=0;loop<byteLen;loop=loop+4) {
		temp2        = data[loop/4];
		temp[loop]   = temp2%256;
		temp2        = temp2/256;
		temp[loop+1] = temp2%256;
		temp2        = temp2/256;
		temp[loop+2] = temp2%256;
		temp2        = temp2/256;
		temp[loop+3] = temp2%256;
	}
    HashReturn ret = Keccak_HashUpdate(ctx, temp, byteLen * 8);

//    if (ret != SUCCESS) {
//        fprintf(stderr, "%s: Keccak_HashUpdate failed (returned %d)\n", __func__, ret);
//        assert(!"Keccak_HashUpdate failed");
//    }
}

void HashInit(HashInstance* ctx, paramset_t* params, uint8_t hashPrefix)
{
	uint8_t temp[1];
	temp[0] = hashPrefix;
    if (params->stateSizeBits == 128) {         /* L1 */
        Keccak_HashInitialize_SHAKE128(ctx);
    }
    else {                                      /* L3, L5 */
        Keccak_HashInitialize_SHAKE256(ctx);
    }

    if (hashPrefix != HASH_PREFIX_NONE) {
        HashUpdate(ctx, temp, 1);
    }
}

void HashFinal(HashInstance* ctx)
{
    HashReturn ret = Keccak_HashFinal(ctx, NULL);

    if (ret != SUCCESS) {
        fprintf(stderr, "%s: Keccak_HashFinal failed (returned %d)\n", __func__, ret);
    }
}


void HashSqueeze(HashInstance* ctx, uint8_t* digest, size_t byteLen)
{
    HashReturn ret = Keccak_HashSqueeze(ctx, digest, byteLen * 8);

    if (ret != SUCCESS) {
        fprintf(stderr, "%s: Keccak_HashSqueeze failed (returned %d)\n", __func__, ret);
    }
}

uint16_t toLittleEndian(uint16_t x)
{
#if (PLATFORM_BYTE_ORDER == IS_BIG_ENDIAN)
    return (x << 8) | (x >> 8);
#else
    return x;
#endif

}

uint16_t fromLittleEndian(uint16_t x)
{
#if (PLATFORM_BYTE_ORDER == IS_BIG_ENDIAN)
    return (x << 8) | (x >> 8);
#else
    return x;
#endif
}

void HashUpdateIntLE(HashInstance* ctx, uint16_t x)
{
//    uint16_t outputBytesLE = toLittleEndian(x);
	uint8_t temp[2];
	temp[0] = x %256;
	temp[1] = x /256;

//    HashUpdate(ctx, (uint8_t*)&outputBytesLE, sizeof(uint16_t));
    HashUpdate(ctx, temp, sizeof(uint16_t));
}

