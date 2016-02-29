!--------------------------------------------------------------------------
!  Header section:
!  TITLE: CSCI260 Lab 2 Lesson 2
!  AUTHOR: Adam Longoria
!  CLASS:   CSCI260A
!  DATE WRITTEN: 1/17/14
!  LAST REVISION: 1/17/14
!  DESCRIPTION: This program demonstrates the Fortran's basic math operations.
!  VARIABLES USED:
!
!       NAME:           TYPE:           COMMENT:
!		f				REAL			future value
!		p				REAL			present value
!		arp				REAL			annual interest rate
!		m				REAL			time compounded a year
!		n				REAL			number of years
!	
!---------------------------------------------------------------------------

PROGRAM lab02_02
IMPLICIT NONE

! Declare the variables.
	REAL f, p, arp, m, n
	
! Begin your code on the next line
	WRITE(*,*) 'Enter present value: '
	READ(*,*) p
	
	WRITE(*,*) 'Enter annual interest rate: '
	READ(*,*) arp
	
	WRITE(*,*) 'Enter times compounded a year: '
	READ(*,*) m
	
	WRITE(*,*) 'Enter number of years: '
	READ(*,*) n
	
	
	f = p * (1 + arp / (100 * m)) ** (m * n)
	
	WRITE(*,*) 'The future value of the account = ', f


! Now let's add a little class to our program
	WRITE(*,*)
	WRITE(*,*) 'Have a Great Day!!! '
	WRITE(*,*)

	STOP
END PROGRAM 