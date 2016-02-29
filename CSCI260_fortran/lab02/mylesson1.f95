!--------------------------------------------------------------------------
!  Header section:
!  TITLE: CSCI260 Lab 2 Lesson 1
!  AUTHOR: Adam Longoria
!  CLASS:  CSCI260A
!  DATE WRITTEN: 1/17/14
!  LAST REVISION: 1/17/14
!  DESCRIPTION: This program demonstrates the Fortran's basic math operations.
!  VARIABLES USED:
!       NAME:           TYPE:           COMMENT:
!
!
!
!
!---------------------------------------------------------------------------

PROGRAM lab02

IMPLICIT NONE

	INTEGER :: int1, int2, int3, int4, intAns, r1, r2, r3, rAns

	int1 = 4
	int2 = 18
	int3 = -42
	int4 = 24

	intAns = int1+int2+int3+int4
	WRITE(*,*) int1, '+',int2,'+',int3,'+',int4,'=',intAns

	intAns = int2 - int1
	WRITE(*,*) int2,'-',int1,'=',intAns

	intAns = int3*int4
	WRITE(*,*) int3, '*', int4,'=',intAns

	intAns = int1 / int2
	WRITE(*,*)int1,'/',int2,'=',intAns

	r1 = 1.1
	r2 = 13.5
	r3 = -9.999

	rAns = r1+r2
	WRITE(*,*) r1,'+',r2,'=',rAns

	rAns = r2 - r3
	WRITE(*,*) r2,'-',r3,'=',rAns

	rAns = r1*r2
	WRITE(*,*) r1,'*',r2,'=',rAns

	rAns = r2 / r3
	WRITE(*,*) r2,'/',r3,'=',rAns



	WRITE(*,*)
	WRITE(*,*)'Have a nice day!'
	WRITE(*,*)

STOP

END PROGRAM
