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

/* 
 * Usecase of test:
 * int64 should be represented as a string in JSON to avaoid issues with languages that can't hande 64-bit precision
 * such as JavaScript
 * For input we allow both integer and string, output will always be a string
 */
/*########################################################################
#                                                                       #
#  HEADER (INCLUDE) SECTION                                             #
#                                                                       #
########################################################################*/
#include <assert.h>
#include <string.h>
#include <semaphore.h>
#include <jansson.h>
#include "verbose.h"

#include <qeojson/api.h>
/*########################################################################
#                                                                       #
#  TYPES and DEFINES SECTION                                            #
#                                                                       #
########################################################################*/
#define STRNUMBER "123456789"
/*########################################################################
#                                                                       #
#  STATIC FUNCTION PROTOTYPES                                           #
#                                                                       #
########################################################################*/
static void qeo_json_factory_init_done (qeo_factory_t *factory,
                                        uintptr_t userdata);
static void on_data(const qeo_json_event_reader_t *reader,
                    const char *json_data,
                    uintptr_t userdata);

static void on_no_more_data(const qeo_json_event_reader_t *reader,
                            uintptr_t userdata);

static void on_reader_policy_update (const qeo_json_event_reader_t *reader,
                                           const char *json_policy,
                                           uintptr_t userdata);

static void on_writer_policy_update (const qeo_json_event_writer_t *writer,
                                           const char *json_policy,
                                           uintptr_t userdata);

/*########################################################################
#                                                                       #
#  STATIC VARIABLE SECTION                                              #
#                                                                       #
########################################################################*/
static qeo_factory_t *_factory = NULL;
static sem_t _sync;
static sem_t _sync_data;
static sem_t _sync_nodata;

static const char *int64_type = "{\
        \"topic\": \"org.qeo.sample.simplechat.ChatMessage\",\
        \"behavior\": \"event\",\
        \"properties\": {\
            \"nr\": { \
                \"type\": \"int64\"\
            }\
        } \
    }";

static const char *int64_strtemplate = "{\
            \"nr\":\"%s\"\
    }";

static const char *int64_template = "{\
            \"nr\":%s\
    }";


/*########################################################################
#                                                                       #
#  STATIC FUNCTION IMPLEMENTATION                                       #
#                                                                       #
########################################################################*/
char value[150]={};

static qeo_json_event_reader_t *_reader = NULL;
static qeo_json_event_writer_t *_writer = NULL;
static uintptr_t _r_userdata = (uintptr_t)0xdeadbeef;
static uintptr_t _w_userdata = (uintptr_t)0xcafebabe;
static uintptr_t _f_userdata = (uintptr_t)0xac1dcafe;

static void on_data(const qeo_json_event_reader_t *reader,
                    const char *json_data,
                    uintptr_t userdata)
{
    log_verbose("%s enter", __FUNCTION__);
    json_t * json_nr = NULL;
    
    assert(reader == _reader);
    assert(userdata == _r_userdata);

    log_verbose("json_data: %s", json_data);
    json_t *json_data_json = json_loads(json_data, 0, NULL);
    assert(json_data_json != NULL);
    json_t *value_json = json_loads(value, 0, NULL);
    assert(value_json != NULL);

    json_nr = json_object_get(json_data_json, "nr");
    assert(true == json_is_string(json_nr));
    assert(!strcmp(STRNUMBER,json_string_value(json_nr)));
    json_decref(json_data_json);
    json_decref(value_json);

    /* release main thread */
    sem_post(&_sync_data);
    log_verbose("%s exit", __FUNCTION__);
}

static void on_no_more_data(const qeo_json_event_reader_t *reader,
                            uintptr_t userdata)
{

    log_verbose("%s enter", __FUNCTION__);  
    assert(reader == _reader);
    assert(userdata == _r_userdata);

    /* release main thread */
    sem_post(&_sync_nodata);
    log_verbose("%s exit", __FUNCTION__);
}

static void on_reader_policy_update (const qeo_json_event_reader_t *reader,
                                           const char* json_policy,
                                           uintptr_t userdata)
{
    log_verbose("%s enter", __FUNCTION__);
    assert(userdata == _r_userdata);
    assert(NULL != json_policy);
    log_verbose("%s json_policy:%s\r\n", __FUNCTION__,json_policy);
    log_verbose("%s exit", __FUNCTION__);

}

static void on_writer_policy_update (const qeo_json_event_writer_t *writer,
                                           const char* json_policy,
                                           uintptr_t userdata)
{
    log_verbose("%s enter", __FUNCTION__);
    assert(userdata == _w_userdata);
    assert(NULL != json_policy);
    log_verbose("%s json_policy:%s\r\n", __FUNCTION__,json_policy);
    log_verbose("%s exit", __FUNCTION__);

}


static void qeo_json_factory_init_done (qeo_factory_t *factory,
                                               uintptr_t userdata)
{
    qeo_json_event_reader_listener_t reader_cbs = { 
        .on_data = on_data,
        .on_no_more_data = on_no_more_data,
        .on_policy_update = on_reader_policy_update
    };
    qeo_json_event_writer_listener_t writer_cbs = {
        .on_policy_update = on_writer_policy_update
    };

    log_verbose("%s enter", __FUNCTION__);
    assert(userdata == _f_userdata);

    /* initialize */  
    assert(NULL != (_reader = qeo_json_factory_create_event_reader(factory, int64_type, &reader_cbs, _r_userdata)));
    assert(QEO_OK == qeo_json_event_reader_enable(_reader));
    assert(NULL != (_writer = qeo_json_factory_create_event_writer(factory, int64_type, &writer_cbs, _w_userdata)));
    assert(QEO_OK == qeo_json_event_writer_enable(_writer));

    /*write */
    sprintf(value,int64_strtemplate,STRNUMBER);
    log_verbose("value: %s",value);
    assert(QEO_OK == qeo_json_event_writer_write(_writer, value));

    sprintf(value,int64_template,STRNUMBER);
    log_verbose("value: %s",value);
    assert(QEO_OK == qeo_json_event_writer_write(_writer, value));

    /* wait for reception */ 
    sem_wait(&_sync_data);
    sem_wait(&_sync_nodata);

    /* clean up */
    qeo_json_event_writer_close(_writer);
    qeo_json_event_reader_close(_reader);
    _factory = factory;
    /* release main thread */
    sem_post(&_sync);

    log_verbose("%s exit", __FUNCTION__);

}

/*########################################################################
#                                                                       #
#  PUBLIC FUNCTION IMPLEMENTATION                                       #
#                                                                       #
########################################################################*/
int main(int argc, const char **argv)
{
    qeo_json_factory_listener_t factory_listener = {
        .on_factory_init_done=qeo_json_factory_init_done
    };

    log_verbose("%s enter", __FUNCTION__);
    sem_init(&_sync_data, 0, 0);
    sem_init(&_sync_data, 0, 0);
    sem_init(&_sync_nodata, 0, 0);
    assert(QEO_OK == qeo_json_factory_create(&factory_listener, _f_userdata));
    sem_wait(&_sync);
    qeo_json_factory_close(_factory);
    sem_destroy(&_sync);
    sem_destroy(&_sync_data);
    sem_destroy(&_sync_nodata);
    
    log_verbose("%s exit", __FUNCTION__);
}
