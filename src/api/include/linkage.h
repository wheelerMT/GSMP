/* ────────────────────────────────────────────────────────────────── *
 * FILENAME : linkage.h
 *
 * DESCRIPTION : Declares both the linkage and visibility of the C API
 *               build and usage.
 *
 * ────────────────────────────────────────────────────────────────── */

#ifndef LINKAGE_H
#define LINKAGE_H

#include "enums.h"

// Determine linkage
#if defined(__cplusplus)
#define GSMP_LINKAGE extern "C"
#else
#define GSMP_LINKAGE extern
#endif


// Define the visibility of the library with a return code
#if defined(_MSC_VER) && defined(GSMP_BUILD_SHARED)
// Build as Windows Shared Library (.dll)
#define GSMP_API GSMP_LINKAGE __declspec(dllexport) ReturnCode
#elif defined(_MSC_VER) && defined(GSMP_USE_SHARED)
// Use as a Windows Shared Library (.dll)
#define GSMP_API GSMP_LINKAGE __declspec(dllimport) ReturnCode
#elif defined(_MSC_VER) && defined(GSMP_BUILD_SHARED)
// Build as Unix Shared Library (.so)
#define GSMP_API GSMP_LINKAGE __attribute__((visibility("default"))) ReturnCode
#else
// Visibility Unmodified, for Static Linkage (.lib)
#define GSMP_API GSMP_LINKAGE ReturnCode
#endif

#endif // LINKAGE_H
