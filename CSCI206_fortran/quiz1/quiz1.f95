!--------------------------------------------------------------------------
!  TITLE: CSCI260A Programming Quiz 1
!  AUTHOR: Adam Longoria
!  CLASS:  CSCI260A
!  DATE WRITTEN: 02/21/14
!  LAST REVISION: 02/21/14
!  DESCRIPTION: Quadratic formula root calculator
!  VARIABLES USED:
!    NAME:           TYPE:     COMMENT:
!	 a				 INT       coefficient of second order term
!	 b               INT 	   coefficient of first order term
!	 c	             INT       coefficient of constant term
!    r1				 REAL	   one of the roots
!    r2				 REAl	   other root
!---------------------------------------------------------------------------

PROGRAM the_root_of_all_evil 

IMPLICIT NONE  !Must explicitly declare all variables

! Declare the variables and initialize.
INTEGER :: a, b, c
REAL :: r1, r2

WRITE(*,*) "Please enter A coefficient"
READ(*,*) A
WRITE(*,*) "Please enter B coefficient"
READ(*,*) B
WRITE(*,*) "Please enter C coefficient"
READ(*,*) C

! Code the Problem Here
IF ((b**2.0-4.0*a*c) < 0) THEN
	WRITE(*,*) "ERROR: Roots are imaginary"
ELSE
	r1 = (-b + sqrt(b**2.0-4.0*a*c))/(2.0*a)
	r2 = (-b - sqrt(b**2.0-4.0*a*c))/(2.0*a)
	WRITE(*,*) "Roots for coefficients A = ", a, ", B = ", b, ", C = ", c, " are r1 = ", r1, " and r2 = ", r2
END IF

 
! Say Goodbye
   WRITE(*,*)
   WRITE(*,*) 'Good Day!!! '
   WRITE(*,*)

END PROGRAM
