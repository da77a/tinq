/*
 * Copyright (c) 2014 - Qeo LLC
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

package org.qeo.test;

import java.util.Arrays;
import org.qeo.QeoType;
import org.qeo.QeoType.Behavior;

/**
 * struct representing an event containing an unbound array (sequence) of a struct
 */
@QeoType(behavior = Behavior.EVENT)
public class EventWithUnbArrayOfStruct
{
    public MyStructWithPrimitives[] MyUnbArrayOfStructWithPrimitives;

    /**
     * Default constructor.  This is used by Qeo to construct new objects.
     */
    public EventWithUnbArrayOfStruct()
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
        final EventWithUnbArrayOfStruct myObj = (EventWithUnbArrayOfStruct) obj;
        if (!Arrays.equals(MyUnbArrayOfStructWithPrimitives, myObj.MyUnbArrayOfStructWithPrimitives)) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode()
    {
        final int prime = 31;
        int result = 1;
        result = prime * result + Arrays.hashCode(MyUnbArrayOfStructWithPrimitives);
        return result;
    }
}
