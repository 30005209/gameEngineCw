(* Copyright (C) 2012 Free Software Foundation, Inc. *)
(* This file is part of GNU Modula-2.

GNU Modula-2 is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GNU Modula-2 is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License along
with gm2; see the file COPYING.  If not, write to the Free Software
Foundation, 51 Franklin Street, Fifth Floor,
Boston, MA 02110-1301, USA. *)

MODULE wallh ;


IMPORT popWorld ;
IMPORT twoDsim ;

FROM deviceGroff IMPORT Colour, red, blue, green ;
FROM Fractions IMPORT Fract, initFract, zero, one, two, cardinal, negate ;
FROM Points IMPORT Point, initPoint ;

FROM macroObjects IMPORT Macro, circle, moveTo, up, down, left, right,
                         append, translate, rootMacro, dup, unRootMacro, initMacro, rectangle ;


CONST
   testCorner = FALSE ;
   testRight  = FALSE ;


(*
   placeWall - 
*)

PROCEDURE placeWall ;
VAR
   m: Macro ;
BEGIN
   m := initMacro() ;
   m := moveTo(m, initPoint(initFract(0, 2, 10), initFract(0, 8, 10))) ;
   m := rectangle(m, TRUE, zero(), red(), initFract(0, 6, 10), initFract(0, 1, 10)) ;

   m := moveTo(m, initPoint(initFract(0, 2, 10), initFract(0, 2, 10))) ;
   m := rectangle(m, TRUE, zero(), red(), initFract(0, 6, 10), initFract(0, 1, 10)) ;

   m := rootMacro(m) ;
   popWorld.populate(m, TRUE, TRUE)
END placeWall ;


(*
   fireCue - 
*)

PROCEDURE fireCue ;
VAR
   m: Macro ;
BEGIN
   m := initMacro() ;
   IF testCorner
   THEN
      IF testRight
      THEN
         (* this will hit the right corner *)
         m := moveTo(m, initPoint(initFract(0, 8, 10), initFract(0, 5, 10)))
      ELSE
         (* this will hit the left corner *)
         m := moveTo(m, initPoint(initFract(0, 2, 10), initFract(0, 5, 10)))
      END
   ELSE
      (* fire against the wall *)
      m := moveTo(m, initPoint(initFract(0, 5, 10), initFract(0, 5, 10)))
   END ;

   m := circle(m, TRUE, zero(), green(), size) ;
   m := rootMacro(m) ;
   popWorld.mass(cardinal(3)) ;
   popWorld.velocity(initPoint(initFract(0, 1, 2), negate(initFract(2, 0, 0)))) ;
   popWorld.populate(m, FALSE, TRUE) ;
   twoDsim.simulateFor(0.75)
END fireCue ;


(*
   fireBox - 
*)

PROCEDURE fireBox ;
VAR
   m: Macro ;
BEGIN
   m := initMacro() ;

   IF testCorner
   THEN
      IF testRight
      THEN
         (* this will hit the right corner *)
         m := moveTo(m, initPoint(initFract(0, 8, 10), initFract(0, 5, 10)))
      ELSE
         (* this will hit the left corner *)
         m := moveTo(m, initPoint(initFract(0, 2, 10), initFract(0, 5, 10)))
      END
   ELSE
      (* fire against the wall *)
      m := moveTo(m, initPoint(initFract(0, 5, 10), initFract(0, 5, 10)))
   END ;

   m := rectangle(m, TRUE, zero(), green(), initFract(0, 1, 20), initFract(0, 1, 20)) ;
   m := rootMacro(m) ;

   popWorld.mass(cardinal(1)) ;
   popWorld.velocity(initPoint(initFract(0, 1, 2), negate(initFract(2, 0, 0)))) ;
   popWorld.populate(m, FALSE, TRUE) ;
   twoDsim.simulateFor(0.75)
END fireBox ;


VAR
   size: Fract ;
BEGIN
   popWorld.init(FALSE) ;
   size := initFract(0, 1, 21) ;
   placeWall ;
   fireBox
END wallh.
