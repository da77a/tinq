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

#include <stdlib.h>
#include "unittest/unittest.h"

extern void register_device_api_tests(Suite *s);

static testCaseInfo testcases[] =
{
	{.register_testcase = register_device_api_tests,
	 .name = "Device Info API tests"},
	{NULL}
};

static testSuiteInfo testsuite =
{
	.name = "Qeo C Device Info",
	.desc = "Qeo C Device Info test suite",
};

static void init_tcase()
{
}

static void fini_tcase()
{
}

__attribute__((constructor))
void my_init(void)
{
    register_testsuite(&testsuite, testcases, init_tcase, fini_tcase);
}
