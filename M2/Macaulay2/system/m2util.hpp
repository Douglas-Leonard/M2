#ifndef _system_m2util_h_
#define _system_m2util_h_

#include "mutexclass.hpp"

    /* gc doc tells us to include pthread.h before gc.h */
    #ifndef _REENTRANT
      #define _REENTRANT
    #endif
    #include <pthread.h>
    #define GC_THREADS
    #include <gc/gc.h>

#include <gc/gc_cpp.h>

extern M2_string M2_tostring_3(const char *);
struct parse_Sequence_struct {unsigned short type_;int len;parse_Expr array[1];};

typedef struct parse_Sequence_struct * parse_Sequence;

extern parse_Sequence expr_emptySequence;

parse_Sequence allocSequence(int len)
{
  return (parse_Sequence)GC_MALLOC(sizeof(parse_Sequence_struct)+sizeof(parse_Expr)*(len-1));
}

#endif
