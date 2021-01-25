/******************************************************************************
Copyright 2011-2020 Hikvision Digital Technology Co., Ltd.
FileName: cType.h
Description:   data type definition
Author:
Date: 2012-03-05
Modification History:
    <version > <time> <author> <desc>
    <2018-01-03> Zhao Yan Jun. 类型定义整理，并增加 CHAR, SHORT, FLOAT, INT8,
                 INT64 等几种类型定义。
    <2018-03-02> Deng Wei Wei. 整合HK_cType.h
    <2018-05-07> Zhao Yan Jun. 1. 增加 DOUBLE 浮点类型。2. 调整缩进对齐。
    <2019-06-25> Zhu Yi. 1. 增加获取行号宏定义, 2、增加double HAT_PI宏定义。
*******************************************************************************/
#ifndef _C_TYPE_H_
#define _C_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_SHARE_ADDR       			(4)   /*必须为偶数0-APP_v ...*/

#ifdef AMBA_DEV
#define CPU_BITS                        UINT32
#endif

#ifdef HISI_3516D_DEV
#define CPU_BITS                        UINT32
#endif

#ifdef J6_DEV
#define CPU_BITS                        UINT32
#endif

#ifdef NVT_DEV
#define CPU_BITS                        UINT32
#endif

#ifdef FH8830_DEV
#define CPU_BITS                        UINT32
#endif

#ifdef MPSOC_DEV
#ifdef  LINUX_OS
#define CPU_BITS                        UINT64
#else
#define CPU_BITS                        UINT32
#endif
#endif

#ifdef HISI_3559A
#define CPU_BITS                        UINT64
#endif

#ifndef GET_CODE_LINE
#define GET_CODE_LINE                 	__LINE__
#endif

#ifndef HAT_PI
#define HAT_PI 							((DOUBLE)3.1415926535897932384626433832795)
#endif

/*fixed for enum type*/
#ifndef INT_MINI
#define INT_MINI     (-2147483647 - 1) /* minimum (signed) int value */
#endif

#ifndef INT_MAXI
#define INT_MAXI      (2147483647)    /* maximum (signed) int value */
#endif

/*日期、时间*/
#ifndef _DATE_TIME_
#define _DATE_TIME_
typedef struct
{
    short year;
    short month;
    short dayOfWeek;        /*0:星期日-6:星期六*/
    short day;
    short hour;
    short minute;
    short second;
    short milliSecond;
} DATE_TIME;
#endif

/*视频标准*/
#ifndef _VIDEO_STANDARD_
#define _VIDEO_STANDARD_
typedef enum
{
    VS_NON      = 0,
    VS_NTSC     = 1,
    VS_PAL      = 2,

    VIDEO_STANDARD_INT_MIN  = INT_MINI,
    VIDEO_STANDARD_INT_MAX  = INT_MAXI
}VIDEO_STANDARD;
#endif

#ifndef NULL
#define NULL    (void *)0
#endif

#ifndef OK
#define OK      (0)
#endif

#ifndef NG
#define NG      (-1)
#endif

#ifndef ERROR
#define ERROR   (-1)
#endif

#ifndef TRUE
#define TRUE    (1)
#endif

#ifndef FALSE
#define FALSE   (0)
#endif


#ifndef HIK_TYPE_ERR
#define HIK_TYPE_ERR
typedef unsigned int        ERR;
#endif

/*******************************************
 * 基本类型
 ******************************************/
#ifndef HIK_TYPE_BOOL
#define HIK_TYPE_BOOL
typedef int                 BOOL;
#endif

#ifndef HIK_TYPE_CHAR
#define HIK_TYPE_CHAR
typedef char                CHAR;
#endif

#ifndef HIK_TYPE_SHORT
#define HIK_TYPE_SHORT
typedef short               SHORT;
#endif

#ifndef HIK_TYPE_INT
#define HIK_TYPE_INT
typedef int                 INT;
#endif

#ifndef HIK_TYPE_UINT
#define HIK_TYPE_UINT
typedef unsigned int        UINT;
#endif

#ifndef HIK_TYPE_FLOAT
#define HIK_TYPE_FLOAT
typedef float               FLOAT;
#endif

#ifndef HIK_TYPE_FLOAT32
#define HIK_TYPE_FLOAT32
typedef float               FLOAT32;
#endif

#ifndef HIK_TYPE_DOUBLE
#define HIK_TYPE_DOUBLE
typedef double              DOUBLE;
#endif

#ifndef HIK_TYPE_VOID
#define HIK_TYPE_VOID
typedef void                VOID;
#endif

/*******************************************
 * 8位，16位，32位，64位整型
 ******************************************/
#ifndef HIK_TYPE_UINT8
#define HIK_TYPE_UINT8
typedef unsigned char       UINT8;
#endif

#ifndef HIK_TYPE_UINT16
#define HIK_TYPE_UINT16
typedef unsigned short      UINT16;
#endif

#ifndef HIK_TYPE_UINT32
#define HIK_TYPE_UINT32
typedef unsigned int        UINT32;
#endif

#ifndef HIK_TYPE_UINT64
#define HIK_TYPE_UINT64
typedef unsigned long long  UINT64;
#endif

#ifndef HIK_TYPE_INT8
#define HIK_TYPE_INT8
typedef char                INT8;
#endif

#ifndef HIK_TYPE_INT16
#define HIK_TYPE_INT16
typedef short               INT16;
#endif

#ifndef HIK_TYPE_INT32
#define HIK_TYPE_INT32
typedef int                 INT32;
#endif

#ifndef HIK_TYPE_INT64
#define HIK_TYPE_INT64
typedef long long           INT64;
#endif

/*******************************************
 * 指针类型及 volatile 类型
 ******************************************/
#ifndef HIK_TYPE_PINT
#define HIK_TYPE_PINT
typedef int                *PINT;
#endif

#ifndef HIK_TYPE_PUINT
#define HIK_TYPE_PUINT
typedef unsigned int       *PUINT;
#endif

#ifndef HIK_TYPE_PVOID
#define HIK_TYPE_PVOID
typedef void               *PVOID;
#endif

#ifndef HIK_TYPE_PUINT8
#define HIK_TYPE_PUINT8
typedef unsigned char      *PUINT8;
#endif

#ifndef HIK_TYPE_PUINT16
#define HIK_TYPE_PUINT16
typedef unsigned short     *PUINT16;
#endif

#ifndef HIK_TYPE_UINTV
#define HIK_TYPE_UINTV
typedef volatile UINT       UINTV;
#endif

#ifndef HIK_TYPE_PUINTV
#define HIK_TYPE_PUINTV
typedef volatile UINT *     PUINTV;
#endif

typedef unsigned long       UINT40;
typedef long                INT40;


#ifdef __cplusplus
}
#endif

#endif
