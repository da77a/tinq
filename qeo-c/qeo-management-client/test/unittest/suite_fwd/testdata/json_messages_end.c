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


/*#######################################################################
#                   STATIC FUNCTION IMPLEMENTATION                      #
########################################################################*/

/*#######################################################################
#                   PUBLIC FUNCTION IMPLEMENTATION                      #
########################################################################*/
char* get_success_list_fwds(int id){
    return success_list_fwds[id];
}

char* get_error_list_fwds(int id){
    return error_list_fwds[id];
}

char* get_success_register_fwd(int id){
    return success_register_fwd[id];
}
