/* do not edit automatically generated by mc from RTint.  */
/* RTint.def provides users of the COROUTINES library with the.

Copyright (C) 2009-2020 Free Software Foundation, Inc.
Contributed by Gaius Mulley <gaius.mulley@southwales.ac.uk>.

This file is part of GNU Modula-2.

GNU Modula-2 is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GNU Modula-2 is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */


#if !defined (_RTint_H)
#   define _RTint_H

#   ifdef __cplusplus
extern "C" {
#   endif
#   if !defined (PROC_D)
#      define PROC_D
       typedef void (*PROC_t) (void);
       typedef struct { PROC_t proc; } PROC;
#   endif

#   include "GSYSTEM.h"

#   if defined (_RTint_C)
#      define EXTERN
#   else
#      define EXTERN extern
#   endif

typedef struct RTint_DispatchVector_p RTint_DispatchVector;

typedef void (*RTint_DispatchVector_t) (unsigned int, unsigned int, void *);
struct RTint_DispatchVector_p { RTint_DispatchVector_t proc; };


/*
   InitInputVector - returns an interrupt vector which is associated
                     with the file descriptor, fd.
*/

EXTERN unsigned int RTint_InitInputVector (int fd, unsigned int pri);

/*
   InitOutputVector - returns an interrupt vector which is associated
                      with the file descriptor, fd.
*/

EXTERN unsigned int RTint_InitOutputVector (int fd, unsigned int pri);

/*
   InitTimeVector - returns an interrupt vector associated with
                    the relative time.
*/

EXTERN unsigned int RTint_InitTimeVector (unsigned int micro, unsigned int secs, unsigned int pri);

/*
   ReArmTimeVector - reprimes the vector, vec, to deliver an interrupt
                     at the new relative time.
*/

EXTERN void RTint_ReArmTimeVector (unsigned int vec, unsigned int micro, unsigned int secs);

/*
   GetTimeVector - assigns, micro, and, secs, with the remaining
                   time before this interrupt will expire.
                   This value is only updated when a Listen
                   occurs.
*/

EXTERN void RTint_GetTimeVector (unsigned int vec, unsigned int *micro, unsigned int *secs);

/*
   AttachVector - adds the pointer, p, to be associated with the interrupt
                  vector. It returns the previous value attached to this
                  vector.
*/

EXTERN void * RTint_AttachVector (unsigned int vec, void * p);

/*
   IncludeVector - includes, vec, into the dispatcher list of
                   possible interrupt causes.
*/

EXTERN void RTint_IncludeVector (unsigned int vec);

/*
   ExcludeVector - excludes, vec, from the dispatcher list of
                   possible interrupt causes.
*/

EXTERN void RTint_ExcludeVector (unsigned int vec);

/*
   Listen - will either block indefinitely (until an interrupt)
            or alteratively will test to see whether any interrupts
            are pending.
            If a pending interrupt was found then, call, is called
            and then this procedure returns.
            It only listens for interrupts > pri.
*/

EXTERN void RTint_Listen (unsigned int untilInterrupt, RTint_DispatchVector call, unsigned int pri);

/*
   Init - allows the user to force the initialize order.
*/

EXTERN void RTint_Init (void);
#   ifdef __cplusplus
}
#   endif

#   undef EXTERN
#endif
