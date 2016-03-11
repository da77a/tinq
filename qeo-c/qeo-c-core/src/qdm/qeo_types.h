/*
 * Copyright (c) 2016 - Qeo LLC
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

/**************************************************************
 ********          THIS IS A GENERATED FILE         ***********
 **************************************************************/

#ifndef QDM_QEO_TYPES_H_
#define QDM_QEO_TYPES_H_

#include <qeo/types.h>

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * this is the device ID generated by Qeo.
 */
typedef struct {
  /**
   * Upper 64-bit of identifier.
   */
    int64_t upper;
  /**
   * Lower 64-bit of identifier.
   */
    int64_t lower;
} org_qeo_system_DeviceId_t;
extern const DDS_TypeSupport_meta org_qeo_system_DeviceId_type[];

/**
 * A generic 128-bit UUID.
 */
typedef struct {
  /**
   * Upper 64-bit of identifier.
   */
    int64_t upper;
  /**
   * Lower 64-bit of identifier.
   */
    int64_t lower;
} org_qeo_UUID_t;
extern const DDS_TypeSupport_meta org_qeo_UUID_type[];

#ifdef __cplusplus
}
#endif

#endif /* QDM_QEO_TYPES_H_ */

