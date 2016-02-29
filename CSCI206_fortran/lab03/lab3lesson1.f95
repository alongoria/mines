!--------------------------------------------------------------------------
!  Header section:
!  TITLE: CSCI260 Lab 3 Lesson 1
!  AUTHOR: Adam Longoria
!  CLASS:  CSCI260A
!  DATE WRITTEN: 1/24/14
!  LAST REVISION: 1/28/14
!  DESCRIPTION: This program demonstrates the Fortran's basic math operations.
!  VARIABLES USED:
!       NAME:           TYPE:           COMMENT:
!		temp			REAL			user input for current temp
!
!---------------------------------------------------------------------------

PROGRAM Lab3Lesson1

IMPLICIT NONE  !Must explicitly declare all variables

	! Declare the variables.

	REAL :: temp

	! Begin your code on the next line

	WRITE(*,*) 'What is the current temperature of the tea?'
	READ(*,*) temp

	IF (temp <= 140 .AND. temp >= 90) THEN
		WRITE(*,*) 'Just right'
	END IF
	IF (temp >= 32 .AND. temp < 90) THEN
		WRITE(*,*) 'Too cold'
	END IF
	IF (temp >= 140 .AND. temp <= 212) THEN
		WRITE(*,*) 'Too hot'
	END IF

	IF (temp < 32) THEN
		WRITE(*,*) 'Frozen'
	END IF

	IF (temp > 212) THEN
		WRITE(*,*) 'Broken thermometer'
	END IF



	! Now let's add a little class to our program
	WRITE(*,*)
	WRITE(*,*) ' Have a Great Day!!! '
	WRITE(*,*)

   STOP
END PROGRAM !Lab3Lesson1
