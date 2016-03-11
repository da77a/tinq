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

package module.second;

import org.qeo.QeoType;

/**
 * this is the device ID 2 generated by Qeo.
 */
@QeoType
public class Class1
{
    public long upper2;

    public long lower2;

    /**
     * Default constructor.  This is used by Qeo to construct new objects.
     */
    public Class1()
    {
    }

    @Override
    public boolean equals(Object obj)
    {
        if (obj == this) {
            return true;
        }
        if ((obj == null) || (obj.getClass() != this.getClass())) {
            return false;
        }
        final Class1 myObj = (Class1) obj;
        if (upper2 != myObj.upper2) {
            return false;
        }
        if (lower2 != myObj.lower2) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode()
    {
        final int prime = 31;
        int result = 1;
        result = prime * result + (int) (upper2 ^ (upper2 >>> 32));
        result = prime * result + (int) (lower2 ^ (lower2 >>> 32));
        return result;
    }
}
