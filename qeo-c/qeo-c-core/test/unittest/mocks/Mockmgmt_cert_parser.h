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

/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCKMGMT_CERT_PARSER_H
#define _MOCKMGMT_CERT_PARSER_H

#include "unity.h"
#include "qeo/mgmt_cert_parser.h"

void Mockmgmt_cert_parser_Init(void);
void Mockmgmt_cert_parser_Destroy(void);
void Mockmgmt_cert_parser_Verify(void);




#define qeo_mgmt_cert_parse_IgnoreAndReturn(cmock_retval) qeo_mgmt_cert_parse_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void qeo_mgmt_cert_parse_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, qeo_mgmt_cert_retcode_t cmock_to_return);
#define qeo_mgmt_cert_parse_ExpectAndReturn(chain, contents, cmock_retval) qeo_mgmt_cert_parse_CMockExpectAndReturn(__LINE__, chain, contents, cmock_retval)
void qeo_mgmt_cert_parse_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, STACK_OF(X509)* chain, qeo_mgmt_cert_contents* contents, qeo_mgmt_cert_retcode_t cmock_to_return);
typedef qeo_mgmt_cert_retcode_t (* CMOCK_qeo_mgmt_cert_parse_CALLBACK)(STACK_OF(X509)* chain, qeo_mgmt_cert_contents* contents, int cmock_num_calls);
void qeo_mgmt_cert_parse_StubWithCallback(CMOCK_qeo_mgmt_cert_parse_CALLBACK Callback);

#endif
