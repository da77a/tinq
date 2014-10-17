/**************************************************************
 ********          THIS IS A GENERATED FILE         ***********
 **************************************************************/

#define XTYPES_USED
#import <Qeo/dds/dds_tsm.h>
#import "StateWithNestedStructKeyIsInt16.h"

extern const DDS_TypeSupport_meta _org_qeo_test_MyStructWithPrimitives_type[]; 
extern const DDS_TypeSupport_meta _org_qeo_DeviceId_type[]; 

const DDS_TypeSupport_meta _org_qeo_test_StateWithNestedStructKeyIsInt16_type[] = {
    { .tc = CDR_TYPECODE_STRUCT, .name = "org.qeo.test.StateWithNestedStructKeyIsInt16", .flags = TSMFLAG_DYNAMIC|TSMFLAG_GENID|TSMFLAG_KEY|TSMFLAG_MUTABLE, .nelem = 9 },
    { .tc = CDR_TYPECODE_BOOLEAN, .name = "MyBoolean" },
    { .tc = CDR_TYPECODE_OCTET, .name = "MyByte" },
    { .tc = CDR_TYPECODE_SHORT, .name = "MyInt16", .flags = TSMFLAG_KEY },
    { .tc = CDR_TYPECODE_LONG, .name = "MyInt32" },
    { .tc = CDR_TYPECODE_LONGLONG, .name = "MyInt64" },
    { .tc = CDR_TYPECODE_FLOAT, .name = "MyFloat32" },
    { .tc = CDR_TYPECODE_CSTRING, .name = "MyString", .flags = TSMFLAG_DYNAMIC },
    { .tc = CDR_TYPECODE_TYPEREF, .name = "MyStructWithPrimitives", .tsm = _org_qeo_test_MyStructWithPrimitives_type },
    { .tc = CDR_TYPECODE_TYPEREF, .name = "MyDeviceId", .tsm = _org_qeo_DeviceId_type },
};


@implementation org_qeo_test_StateWithNestedStructKeyIsInt16
{
}

+ (const DDS_TypeSupport_meta *)getMetaType {
    return _org_qeo_test_StateWithNestedStructKeyIsInt16_type;
}
@end
