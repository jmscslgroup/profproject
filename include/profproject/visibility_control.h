#ifndef PROFPROJECT__VISIBILITY_CONTROL_H_
#define PROFPROJECT__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define PROFPROJECT_EXPORT __attribute__ ((dllexport))
    #define PROFPROJECT_IMPORT __attribute__ ((dllimport))
  #else
    #define PROFPROJECT_EXPORT __declspec(dllexport)
    #define PROFPROJECT_IMPORT __declspec(dllimport)
  #endif
  #ifdef PROFPROJECT_BUILDING_LIBRARY
    #define PROFPROJECT_PUBLIC PROFPROJECT_EXPORT
  #else
    #define PROFPROJECT_PUBLIC PROFPROJECT_IMPORT
  #endif
  #define PROFPROJECT_PUBLIC_TYPE PROFPROJECT_PUBLIC
  #define PROFPROJECT_LOCAL
#else
  #define PROFPROJECT_EXPORT __attribute__ ((visibility("default")))
  #define PROFPROJECT_IMPORT
  #if __GNUC__ >= 4
    #define PROFPROJECT_PUBLIC __attribute__ ((visibility("default")))
    #define PROFPROJECT_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define PROFPROJECT_PUBLIC
    #define PROFPROJECT_LOCAL
  #endif
  #define PROFPROJECT_PUBLIC_TYPE
#endif
#endif  // PROFPROJECT__VISIBILITY_CONTROL_H_
// Generated 06-Nov-2023 21:43:19
// Copyright 2019-2020 The MathWorks, Inc.
