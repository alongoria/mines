!--------------------------------------------------------------------------
!  Header section:
!  TITLE: CSCI260 Lab 4 Lesson 2
!  AUTHOR: Adam Longoria
!  CLASS:  CSCI260A
!  DATE WRITTEN: 1/31/14
!  LAST REVISION: 1/31/14
!  DESCRIPTION: This program demonstrates  
!
!  VARIABLES USED:
!       NAME:           TYPE:           COMMENT:
!		income			REAL			income of an individual
!		tax				REAL			tax on income			
!		care			REAL			1.5% tax for medicare levy
!		total			REAL			total amount of tax payable
!---------------------------------------------------------------------------

PROGRAM Lab4Lesson2

IMPLICIT NONE  !Must explicitly declare all variables

! Declare the variables.

REAL :: income, tax, care, total

! prompt user for input

WRITE(*,*) "Enter total income"
READ(*,*) income

! Begin your code on the next line

! calculate medicare levy tax

care = income * .015

! calculate income tax

IF (income < 6001) THEN
	tax = 0
ELSE IF (income >= 6001 .AND. income < 20001) THEN
	tax = income * .17
ELSE IF (income >= 20001 .AND. income < 50001) THEN
	tax = 2380 + .30 * (income - 20000)
ELSE IF (income >= 50001 .AND. income < 60001) THEN
	tax = 11380 + .42 * (income - 50000)
ELSE IF (income >= 60001) THEN
	tax = 15580 + .47 * (income - 50000)
END IF

! calculate total tax

total = tax + care

WRITE(*,*) "Total tax payable by the individual is", total

! Now let's add a little class to our program
   WRITE(*,*)
   WRITE(*,*) ' Have a Great Day!!! '
   WRITE(*,*)

   STOP
END PROGRAM !Lab4Lesson2
