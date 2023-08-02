#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef __NO_EXPORTS
  #ifdef __cplusplus
      #define EXPORT_API extern "C" __attribute__((visibility("default")))
    #else
      #define EXPORT_API __attribute__((visibility("default")))
  #endif
#else
  #define EXPORT_API
#endif