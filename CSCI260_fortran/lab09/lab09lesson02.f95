!--------------------------------------------------------------------------
!  TITLE: CS260 Lab5 lesson 2
!  AUTHOR: 
!  CLASS:  
!  DATE WRITTEN: 
!  LAST REVISION: 
!  DESCRIPTION: 
!  VARIABLES USED:
!    NAME:           TYPE:     COMMENT:
!
!
!
!---------------------------------------------------------------------------
Program As_Traffic_Goes_By

Implicit None  !Must explicitly declare all variables

! Declare the variables and initialize.
REAL:: lambda, t, p
INTEGER:: k 


! Code the Problem Here

WRITE(*,*)"This program ...."
WRITE(*,*)"Please enter a value for lambda"
READ(*,*)lambda
WRITE(*,*)"Please enter a value for t"
READ(*,*)t
WRITE(*,*)"Please enter the number of cars passing in the time t"
READ(*,*)k



 p = Poisson(lambda, t, k)

WRITE(*,*) "The probability of the cars passing within the given time is ", p








! Say Goodbye
   Write(*,*)
   Write(*,*) ' Have a Great Afternoon!!! '
   Write(*,*)

CONTAINS


REAL FUNCTION Poisson (lambda, t, k)
	REAL,INTENT(IN)::lambda, t
	INTEGER,INTENT(IN)::k
	INTEGER::fac,i
	REAL:: e = 2.71828

	fac=1
	DO i = 1, k
		fac = fac * i
	END DO

	Poisson = e**(-lambda*t) * ((lambda*t)**k)/(fac)
END FUNCTION


End Program   !As_Traffic_Goes_By
