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

#include <stdlib.h>
#include "unittest/unittest.h"

extern void register_inittests(Suite *s);
extern void register_constructtests(Suite *s);
extern void register_authenticationtests(Suite *s);


static testCaseInfo testcases[] =
{
	{.register_testcase = register_inittests,
	 .name = "Security library initialisation tests"},
    {.register_testcase = register_constructtests,
     .name = "Security construct/destruct tests"},
    {.register_testcase = register_authenticationtests,
     .name = "Security authentication tests"},
	{NULL}
};

static testSuiteInfo testsuite =
{
	.name = "Qeo C Security Lib",
	.desc = "Qeo C Security Lib test suite",
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
