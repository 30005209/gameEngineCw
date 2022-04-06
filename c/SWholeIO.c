/* do not edit automatically generated by mc from SWholeIO.  */
/* SWholeIO.mod implement the ISO SWholeIO specification.

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

#   if !defined (PROC_D)
#      define PROC_D
       typedef void (*PROC_t) (void);
       typedef struct { PROC_t proc; } PROC;
#   endif

#define _SWholeIO_H
#define _SWholeIO_C

#   include "GStdChans.h"
#   include "GWholeIO.h"

void SWholeIO_ReadInt (int *int_);
void SWholeIO_WriteInt (int int_, unsigned int width);
void SWholeIO_ReadCard (unsigned int *card);
void SWholeIO_WriteCard (unsigned int card, unsigned int width);

void SWholeIO_ReadInt (int *int_)
{
  /* Skips leading spaces, and removes any remaining characters
     from the default input stream that form part of a signed
     whole number.  The value of this number is assigned to int.
     The read result is set to the value allRight, outOfRange,
     wrongFormat, endOfLine, or endOfInput.
  */
  WholeIO_ReadInt ((IOChan_ChanId) StdChans_StdInChan (), int);
}

void SWholeIO_WriteInt (int int_, unsigned int width)
{
  /* Writes the value of int to the default output stream in
     text form, in a field of the given minimum width.  */
  WholeIO_WriteInt ((IOChan_ChanId) StdChans_StdOutChan (), int_, width);
}

void SWholeIO_ReadCard (unsigned int *card)
{
  /* Skips leading spaces, and removes any remaining characters
     from the default input stream that form part of an unsigned
     whole number.  The value of this number is assigned to card.
     The read result is set to the value allRight, outOfRange,
     wrongFormat, endOfLine, or endOfInput.
  */
  WholeIO_ReadCard ((IOChan_ChanId) StdChans_StdInChan (), card);
}

void SWholeIO_WriteCard (unsigned int card, unsigned int width)
{
  /* Writes the value of card to the default output stream in
     text form, in a field of the given minimum width.  */
  WholeIO_WriteCard ((IOChan_ChanId) StdChans_StdOutChan (), card, width);
}

void _M2_SWholeIO_init (__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
}

void _M2_SWholeIO_finish (__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
}
