/*
 * Copyright (c) 2015 - Qeo LLC
 *
 * The source code form of this Qeo Open Source Project component is subject
 * to the terms of the Clear BSD license.
 *
 * You can redistribute it and/or modify it under the terms of the Clear BSD
 * License (http://directory.fsf.org/wiki/License:ClearBSD). See LICENSE file
 * for more details.
 *
 * The Qeo Open Source Project also includes third party Open Source Software.
 * See LICENSE file for more details.
 */

/* crc32.h -- Calculate crc32 checksum. */

#ifndef __crc32_h_
#define	__crc32_h_

#include <stdint.h>
#include <stdlib.h>

uint32_t crc32(uint32_t crc, const void *buf, size_t size);

#endif
