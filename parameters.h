#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <stdint.h>
#include <stdio.h>

#define ORIGINAL 0
#define ALT      1

#ifndef PRIMES
    #define PRIMES ORIGINAL
#endif

// Architecture parameters
#define RADIX           64
#define LOG2RADIX       6  
typedef uint64_t        digit_t;        // Unsigned 64-bit digit
typedef uint32_t        hdigit_t;       // Unsigned 32-bit digit

#if (SEC_LEVEL == 0)
    #define NBITS_FIELD     64
    #define NBYTES_FIELD    8
    #define WORDS_FIELD     1
#elif (SEC_LEVEL == 1)
    #define NBITS_FIELD     128
    #define NBYTES_FIELD    16
    #define WORDS_FIELD     2
#elif (SEC_LEVEL == 2)
    #define NBITS_FIELD     192
    #define NBYTES_FIELD    24
    #define WORDS_FIELD     3
#elif (SEC_LEVEL == 3)
    #define NBITS_FIELD     256
    #define NBYTES_FIELD    32
    #define WORDS_FIELD     4
#elif (SEC_LEVEL == 4)
    #define NBITS_FIELD     512
    #define NBYTES_FIELD    64
    #define WORDS_FIELD     8
#else
    #error -- "Unsupported SEC_LEVEL"
#endif

#ifndef FIELD_PARAMS_H
#define FIELD_PARAMS_H
#if (NBITS_FIELD == 64)
    #if (PRIMES == ORIGINAL)
    static const digit_t p[WORDS_FIELD]         = {0x1FFFFFFFFFFFFFFF}; // Field order p
    static const digit_t Mont_one[WORDS_FIELD]  = {0x0000000000000008}; // R  =  2^{NBITS_PRIME} (mod p)
    static const digit_t R2[WORDS_FIELD]        = {0x0000000000000040}; // R2 = (2^{NBITS_PRIME})^2 (mod p)
    static const digit_t iR[WORDS_FIELD]        = {0x4000000000000000}; // iR =  R^(-1) (mod p)
    static const digit_t pp[WORDS_FIELD]        = {0x2000000000000001}; // pp = -p^(-1) mod R
    static const digit_t ip[WORDS_FIELD]        = {0xDFFFFFFFFFFFFFFF}; // ip =  p^(-1) mod R    
    static const digit_t Zero[WORDS_FIELD]      = {0x0000000000000000}; // Zero = 0
    static const digit_t One[WORDS_FIELD]       = {0x0000000000000001}; // One = 1
    #elif (PRIMES == ALT)
    static const digit_t p[WORDS_FIELD]         = {0xFFFFFFFFFFFFFFC5}; // Field order p
    static const digit_t Mont_one[WORDS_FIELD]  = {0x000000000000003B}; // R  =  2^{NBITS_PRIME} (mod p)
    static const digit_t R2[WORDS_FIELD]        = {0x0000000000000D99}; // R2 = (2^{NBITS_PRIME})^2 (mod p)
    static const digit_t iR[WORDS_FIELD]        = {0xCBEEA4E1A08AD8C4}; // iR =  R^(-1) (mod p)
    static const digit_t pp[WORDS_FIELD]        = {0xCBEEA4E1A08AD8F3}; // pp = -p^(-1) mod R
    static const digit_t ip[WORDS_FIELD]        = {0x34115B1E5F75270D}; // ip =  p^(-1) mod R    
    static const digit_t Zero[WORDS_FIELD]      = {0x0000000000000000}; // Zero = 0
    static const digit_t One[WORDS_FIELD]       = {0x0000000000000001}; // One = 1
    #endif
#elif (NBITS_FIELD == 128)
    #if (PRIMES == ORIGINAL)
    static const digit_t p[WORDS_FIELD]         = {0xFFFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF}; // Field order p
    static const digit_t Mont_one[WORDS_FIELD]  = {0x0000000000000002, 0x0000000000000000}; // R  =  2^{NBITS_PRIME} (mod p)
    static const digit_t R2[WORDS_FIELD]        = {0x0000000000000004, 0x0000000000000000}; // R2 = (2^{NBITS_PRIME})^2 (mod p)
    static const digit_t iR[WORDS_FIELD]        = {0x0000000000000000, 0x4000000000000000}; // iR =  R^(-1) (mod p)
    static const digit_t pp[WORDS_FIELD]        = {0x0000000000000001, 0x8000000000000000}; // pp = -p^(-1) mod R
    static const digit_t ip[WORDS_FIELD]        = {0xFFFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF}; // ip =  p^(-1) mod R
    static const digit_t Zero[WORDS_FIELD]      = {0x0000000000000000, 0x0000000000000000}; // 0
    static const digit_t One[WORDS_FIELD]       = {0x0000000000000001, 0x0000000000000000}; // 1
    #elif (PRIMES == ALT)
    static const digit_t p[WORDS_FIELD]         = {0xFFFFFFFFFFFFFF53, 0xFFFFFFFFFFFFFFFF}; // Field order p
    static const digit_t Mont_one[WORDS_FIELD]  = {0x00000000000000AD, 0x0000000000000000}; // R  =  2^{NBITS_PRIME} (mod p)
    static const digit_t R2[WORDS_FIELD]        = {0x00000000000074E9, 0x0000000000000000}; // R2 = (2^{NBITS_PRIME})^2 (mod p)
    static const digit_t iR[WORDS_FIELD]        = {0x882383B30D516318, 0x133CABA736C05EB4}; // iR =  R^(-1) (mod p)
    static const digit_t pp[WORDS_FIELD]        = {0x882383B30D516325, 0x133CABA736C05EB4}; // pp = -p^(-1) mod R
    static const digit_t ip[WORDS_FIELD]        = {0x77DC7C4CF2AE9CDB, 0xECC35458C93FA14B}; // ip =  p^(-1) mod R
    static const digit_t Zero[WORDS_FIELD]      = {0x0000000000000000, 0x0000000000000000}; // 0
    static const digit_t One[WORDS_FIELD]       = {0x0000000000000001, 0x0000000000000000}; // 1
    #endif
#elif (NBITS_FIELD == 192)
    #if (PRIMES == ORIGINAL)
    static const digit_t p[WORDS_FIELD]         = {0xFFFFFFFFFFFFFF13, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF}; // Field order p
    static const digit_t Mont_one[WORDS_FIELD]  = {0x00000000000000ED, 0x0000000000000000, 0x0000000000000000}; // R  =  2^{NBITS_PRIME} (mod p)
    static const digit_t R2[WORDS_FIELD]        = {0x000000000000DB69, 0x0000000000000000, 0x0000000000000000}; // R2 = (2^{NBITS_PRIME})^2 (mod p)
    static const digit_t iR[WORDS_FIELD]        = {0xDE83C7D4CB125C9E, 0xF1F532C497393FBA, 0x4CB125CE4FEEB7A0}; // iR =  R^(-1) (mod p)
    static const digit_t pp[WORDS_FIELD]        = {0xDE83C7D4CB125CE5, 0xF1F532C497393FBA, 0x4CB125CE4FEEB7A0}; // pp = -p^(-1) mod R
    static const digit_t ip[WORDS_FIELD]        = {0x217C382B34EDA31B, 0x0E0ACD3B68C6C045, 0xB34EDA31B011485F}; // ip =  p^(-1) mod R
    static const digit_t Zero[WORDS_FIELD]      = {0x0000000000000000, 0x0000000000000000, 0x0000000000000000}; // 0
    static const digit_t One[WORDS_FIELD]       = {0x0000000000000001, 0x0000000000000000, 0x0000000000000000}; // 1
    #elif (PRIMES == ALT)
    static const digit_t p[WORDS_FIELD]         = {0xFFFFFFFFFFFFFFED, 0xFFFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF}; // Field order p
    static const digit_t Mont_one[WORDS_FIELD]  = {0x0000000000000026, 0x0000000000000000, 0x0000000000000000}; // R  =  2^{NBITS_PRIME} (mod p)
    static const digit_t R2[WORDS_FIELD]        = {0x00000000000005A4, 0x0000000000000000, 0x0000000000000000}; // R2 = (2^{NBITS_PRIME})^2 (mod p)
    static const digit_t iR[WORDS_FIELD]        = {0x435E50D79435E50B, 0x5E50D79435E50D79, 0x10D79435E50D7943}; // iR =  R^(-1) (mod p)
    static const digit_t pp[WORDS_FIELD]        = {0x86BCA1AF286BCA1B, 0xBCA1AF286BCA1AF2, 0x21AF286BCA1AF286}; // pp = -p^(-1) mod R
    static const digit_t ip[WORDS_FIELD]        = {0x79435E50D79435E5, 0x435E50D79435E50D, 0xDE50D79435E50D79}; // ip =  p^(-1) mod R
    static const digit_t Zero[WORDS_FIELD]      = {0x0000000000000000, 0x0000000000000000, 0x0000000000000000}; // 0
    static const digit_t One[WORDS_FIELD]       = {0x0000000000000001, 0x0000000000000000, 0x0000000000000000}; // 1
    #endif
#elif (NBITS_FIELD == 256)
    #if (PRIMES == ORIGINAL)
    static const digit_t p[WORDS_FIELD]         = {0xFFFFFFFFFFFFFFED, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF}; // Field order p
    static const digit_t Mont_one[WORDS_FIELD]  = {0x0000000000000026, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000}; // R  =  2^{NBITS_PRIME} (mod p)
    static const digit_t R2[WORDS_FIELD]        = {0x00000000000005A4, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000}; // R2 = (2^{NBITS_PRIME})^2 (mod p)
    static const digit_t iR[WORDS_FIELD]        = {0x435E50D79435E50A, 0x5E50D79435E50D79, 0x50D79435E50D7943, 0x179435E50D79435E}; // iR =  R^(-1) (mod p)
    static const digit_t pp[WORDS_FIELD]        = {0x86BCA1AF286BCA1B, 0xBCA1AF286BCA1AF2, 0xA1AF286BCA1AF286, 0x2F286BCA1AF286BC}; // pp = -p^(-1) mod R
    static const digit_t ip[WORDS_FIELD]        = {0x79435E50D79435E5, 0x435E50D79435E50D, 0x5E50D79435E50D79, 0xD0D79435E50D7943}; // ip =  p^(-1) mod R
    static const digit_t Zero[WORDS_FIELD]      = {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000}; // 0
    static const digit_t One[WORDS_FIELD]       = {0x0000000000000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000}; // 1
    #elif (PRIMES == ALT)
    static const digit_t p[WORDS_FIELD]         = {0xFFFFFFFFFFFFFFFF, 0x00000000FFFFFFFF, 0x0000000000000000, 0xFFFFFFFF00000001}; // Field order p
    static const digit_t Mont_one[WORDS_FIELD]  = {0x0000000000000001, 0xFFFFFFFF00000000, 0xFFFFFFFFFFFFFFFF, 0x00000000FFFFFFFE}; // R  =  2^{NBITS_PRIME} (mod p)
    static const digit_t R2[WORDS_FIELD]        = {0x0000000000000003, 0xFFFFFFFBFFFFFFFF, 0xFFFFFFFFFFFFFFFE, 0x00000004FFFFFFFD}; // R2 = (2^{NBITS_PRIME})^2 (mod p)
    static const digit_t iR[WORDS_FIELD]        = {0x0000000300000000, 0x00000001FFFFFFFE, 0xFFFFFFFD00000002, 0xFFFFFFFE00000003}; // iR =  R^(-1) (mod p)
    static const digit_t pp[WORDS_FIELD]        = {0x0000000000000001, 0x0000000100000000, 0x0000000000000000, 0xFFFFFFFF00000002}; // pp = -p^(-1) mod R
    static const digit_t ip[WORDS_FIELD]        = {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFEFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x00000000FFFFFFFD}; // ip =  p^(-1) mod R
    static const digit_t Zero[WORDS_FIELD]      = {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000}; // 0
    static const digit_t One[WORDS_FIELD]       = {0x0000000000000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000}; // 1
    #endif
#elif (NBITS_FIELD == 512)
    #if (PRIMES == ORIGINAL)
    static const digit_t p[WORDS_FIELD]         = {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFE, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};// Field order p
    static const digit_t Mont_one[WORDS_FIELD]  = {0x0000000000000001, 0x0000000000000000, 0x0000000000000001, 0xFFFFFFFFFFFFFFFF, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000};// R  =  2^{NBITS_PRIME} (mod p)
    static const digit_t R2[WORDS_FIELD]        = {0x0000000000000001, 0x0000000000000000, 0x0000000000000002, 0xFFFFFFFFFFFFFFFE, 0x0000000000000002, 0xFFFFFFFFFFFFFFFE, 0x0000000000000002, 0xFFFFFFFFFFFFFFFE};// R2 = (2^{NBITS_PRIME})^2 (mod p)
    static const digit_t iR[WORDS_FIELD]        = {0xFFFFFFFFFFFFFFFD, 0x0000000000000002, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFD, 0x0000000000000001, 0x0000000000000001};// iR =  R^(-1) (mod p)
    static const digit_t pp[WORDS_FIELD]        = {0x0000000000000001, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0x0000000000000000, 0x0000000000000000, 0xFFFFFFFFFFFFFFFE, 0x0000000000000001, 0x0000000000000001};// pp = -p^(-1) mod R
    static const digit_t ip[WORDS_FIELD]        = {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x0000000000000001, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFE};// ip =  p^(-1) mod R
    static const digit_t Zero[WORDS_FIELD]      = {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000};// 0
    static const digit_t One[WORDS_FIELD]       = {0x0000000000000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000};// 1
    #elif (PRIMES == ALT)
    static const digit_t p[WORDS_FIELD]         = {0x0000000000000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF}; // Field order p
    static const digit_t Mont_one[WORDS_FIELD]  = {0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x0000000000000001, 0x0000000000000000, 0x0000000000000000}; // R  =  2^{NBITS_PRIME} (mod p)
    static const digit_t R2[WORDS_FIELD]        = {0x0000000000000004, 0x0000000000000000, 0xFFFFFFFFFFFFFFF8, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFF7, 0xFFFFFFFFFFFFFFFF, 0x0000000000000007}; // R2 = (2^{NBITS_PRIME})^2 (mod p)
    static const digit_t iR[WORDS_FIELD]        = {0x0000000000000000, 0x0000000000000000, 0x0000000000000001, 0x0000000000000000, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x3FFFFFFFFFFFFFFF}; // iR =  R^(-1) (mod p)
    static const digit_t pp[WORDS_FIELD]        = {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF}; // pp = -p^(-1) mod R
    static const digit_t ip[WORDS_FIELD]        = {0x0000000000000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000001, 0x0000000000000000, 0x8000000000000000}; // ip =  p^(-1) mod R
    static const digit_t Zero[WORDS_FIELD]      = {0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000}; // 0
    static const digit_t One[WORDS_FIELD]       = {0x0000000000000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000}; // 1
    #endif
#endif
#endif /* FIELD_PARAMS_H */

typedef digit_t        f_elm_t[WORDS_FIELD];
typedef digit_t        sec_key[WORDS_FIELD];
typedef unsigned uint128_t __attribute__((mode(TI)));

#endif