#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef char           byte;
typedef signed char    int8;
typedef unsigned char  uint8;
typedef signed short   int16;
typedef unsigned short uint16;
typedef signed long    int32;
typedef unsigned long  uint32;

typedef unsigned char  _BOOL;           /**< for use with TRUE/FALSE        */
typedef unsigned char  stdReturnType;

typedef void*          t_drte_data;

#ifndef NULL
  #define NULL           0
#endif

#define TRUE           1==1
#define FALSE          !TRUE

#endif
