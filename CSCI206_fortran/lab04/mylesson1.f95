!--------------------------------------------------------------------------
!  Header section:
!  TITLE: CSCI260 Lab 4 Lesson 1
!  AUTHOR: Adam Longoria
!  CLASS: CSCI260A
!  DATE WRITTEN: 1/31/14
!  LAST REVISION: 1/31/14
!  DESCRIPTION: This program demonstrates the use of the SELECT CASE statement.
!  VARIABLES USED:
!       NAME:           TYPE:           COMMENT:
!		base			REAL
!		height			REAL
!		radius			REAL
!		sideA			REAL
!		sideB			REAL
!		area			REAL
!		option			INTEGER
!		pi				REAL, PARAMETER
!---------------------------------------------------------------------------

PROGRAM Lab4Lesson1

IMPLICIT NONE  !Must explicitly declare all variables

! Declare the variables.
REAL, PARAMETER :: Pi = 3.1415927
INTEGER :: option
REAL :: base, height, radius, sideA, sideB, area


WRITE(*,*) "***** The area calculator, advanced edition *****"
WRITE(*,*) "1. Find the area of a triangle"
WRITE(*,*) "2. Find the area of a circle"
WRITE(*,*) "3. FInd the area of a square"
WRITE(*,*) "4. Find the area of a rectangle"
WRITE(*,*) "*************************************************"

! Begin your code on the next line
READ(*,*) option

select case (option)
	case (1)
		WRITE(*,*) "Enter the base of the triangle"
		READ(*,*) base
		WRITE(*,*) "Enter the height of the triangle"
		READ(*,*) height
		area = .5 * base * height
		WRITE(*,*) "The area of a triangle is: ", area
		
	case (2)
		WRITE(*,*) "Enter the radius of the circle"
		READ(*,*) radius
		area = pi * (radius ** 2)
		WRITE(*,*) "The area of a circle is: ", area
		
	case (3)
		WRITE(*,*) "Enter the side of the square"
		READ(*,*) sideA
		area = sideA * sideA
		WRITE(*,*) "The area of a square is: ", area
		
	case (4)
		WRITE(*,*) "Enter side A of the rectangle"
		READ(*,*) sideA
		WRITE(*,*) "Enter side B of the rectangle"
		READ(*,*) sideB
		area = sideA * sideB
		WRITE(*,*) "The area of a rectangle is: ", area
	
	case default
		WRITE(*,*) "Option does not exist"
	end select

! Now let's add a little class to our program
   WRITE(*,*)
   WRITE(*,*) ' Have an Okay Day!!! '
   WRITE(*,*)

   STOP
END PROGRAM !Lab4Lesson1
