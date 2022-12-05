#ifndef __COMMON_HPP__
#define __COMMON_HPP__

#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define VAR_NAME_VALUE(var) #var "=" VALUE(var)
#endif
