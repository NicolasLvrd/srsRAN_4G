/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2021 Software Radio Systems Limited
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the distribution.
 *
 */

/**********************************************************************************************
 *  File:         convcoder.h
 *
 *  Description:  Cyclic Redundancy Check
 *                LTE requires CRC lengths 8, 16, 24A and 24B, each with it's own generator
 *                polynomial.
 *
 *  Reference:    3GPP TS 36.212 version 10.0.0 Release 10 Sec. 5.1.1
 *********************************************************************************************/

#ifndef SRSRAN_CRC_H
#define SRSRAN_CRC_H

#include "srsran/config.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct SRSRAN_API {
  uint64_t table[256];
  int      polynom;
  int      order;
  uint64_t crcinit;
  uint64_t crcmask;
  uint64_t crchighbit;
  uint32_t srsran_crc_out;
} srsran_crc_t;

SRSRAN_API int srsran_crc_init(srsran_crc_t* h, uint32_t srsran_crc_poly, int srsran_crc_order);

SRSRAN_API int srsran_crc_set_init(srsran_crc_t* h, uint64_t init_value);

SRSRAN_API uint32_t srsran_crc_attach(srsran_crc_t* h, uint8_t* data, int len);

SRSRAN_API uint32_t srsran_crc_attach_byte(srsran_crc_t* h, uint8_t* data, int len);

static inline void srsran_crc_checksum_put_byte(srsran_crc_t* h, uint8_t byte)
{

  uint64_t crc = h->crcinit;

  uint32_t idx;
  if (h->order > 8) {
    // For more than 8 bits
    uint32_t ord = h->order - 8U;
    idx          = ((crc >> (ord)) & 0xffU) ^ byte;
  } else {
    // For 8 bits or less
    uint32_t ord = 8U - h->order;
    idx          = ((crc << (ord)) & 0xffU) ^ byte;
  }

  crc        = (crc << 8U) ^ h->table[idx];
  h->crcinit = crc;
}

static inline uint64_t srsran_crc_checksum_get(srsran_crc_t* h)
{
  return (h->crcinit & h->crcmask);
}

SRSRAN_API uint32_t srsran_crc_checksum_byte(srsran_crc_t* h, const uint8_t* data, int len);

SRSRAN_API uint32_t srsran_crc_checksum(srsran_crc_t* h, uint8_t* data, int len);

SRSRAN_API bool srsran_crc_match(srsran_crc_t* h, uint8_t* data, int len);

#endif // SRSRAN_CRC_H
