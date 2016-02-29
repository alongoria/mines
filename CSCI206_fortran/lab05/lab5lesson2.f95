!--------------------------------------------------------------------------
!  TITLE: CSCI260A Lab 5 Lesson 2 Factorial
!  AUTHOR: Adam Longoria
!  CLASS:  CSCI260A
!  DATE WRITTEN: 02/07/14
!  LAST REVISION: 02/11/14
!  DESCRIPTION: calculate pressure at given temperature
!  VARIABLES USED:
!    NAME:           TYPE:     COMMENT:
!    R		REAL, PARAMETER     Ryberg gas constant
!    n		REAL, PARAMETER     number of mols
!    V		REAL, PARAMETER     volume
!    P		REAL		    resulting pressure
!    i          INTEGER	            tempterature
!---------------------------------------------------------------------------

PROGRAM HaveGas

IMPLICIT NONE  !Must explicitly declare all variables

! P*V = n*R*T -> P = n*R*T / V

! Declare the variables and initialize.

REAL, PARAMETER :: R = 8.214, n = 1, V = 10
REAL :: P
INTEGER :: i

! Code the Problem Here

DO i = 250, 400
    P = n * R * i / V
    WRITE(*,*) " Pressure at ", i, " K is ", P, " pressure units."
END DO



! Say Goodbye
   WRITE(*,*)
   WRITE(*,*) ' Have a Great Afternoon!!! '
   WRITE(*,*)

END PROGRAM
