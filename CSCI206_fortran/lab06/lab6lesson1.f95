!--------------------------------------------------------------------------
!  TITLE: CSCI260A Lab6 lesson 1
!  AUTHOR: Adam Longoria
!  CLASS: CSCI260A
!  DATE WRITTEN: 02/14/14
!  LAST REVISION: 02/14/14
!  DESCRIPTION: Calculates an infinite series
!  VARIABLES USED:
!    NAME:           TYPE:     COMMENT:
!	 terms			 INT	   user specified amount of terms for series
!    i				 INT	   outside do loop counter
!    j				 INT	   inside do loop counter
!    fact			 INT	   temp var for holding current factorial sum
!    sums			 REAL	   overall sum of the series
!---------------------------------------------------------------------------

PROGRAM to_infinity_and_beyond

IMPLICIT NONE  !Must explicitly declare all variables

! Declare the variables and initialize.

INTEGER :: terms, i, j, fact
REAL :: sums = 0

fact = 1
! Code the Problem Here

WRITE(*,*) "Infinite sum calculator: enter number of terms for infinite series"
READ(*,*) terms

!for loop for terms
	!calculate factorial
	
DO i=0, terms
	!WRITE(*,*) i
	DO j=1, i
		fact = fact * j
	END DO
	!WRITE(*,*) "factorial of ", i, " equals", fact
	sums = sums + (1.0/fact)
	fact = 1
END DO

WRITE(*,*) "Series equals ", sums

! Say Goodbye
   WRITE(*,*)
   WRITE(*,*) ' Have a Great Afternoon!!! '
   WRITE(*,*)

END PROGRAM
