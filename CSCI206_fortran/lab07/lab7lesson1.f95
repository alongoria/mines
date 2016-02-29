!--------------------------------------------------------------------------
!  TITLE: CSCI260A Lab7 Lesson 1
!  AUTHOR: Adam Longoria
!  CLASS: CSCI260A
!  DATE WRITTEN: 03/03/2014
!  LAST REVISION: 03/04/2014
!  DESCRIPTION: Trig Tables
!  VARIABLES USED:
!    NAME:           TYPE:     COMMENT:
!     i				INTEGER	   counter var for DO loop
!     deg			INTEGER	   degrees
!     err1			INTEGER	   error var for open file
!     th			REAL       theta
!     conv			REAL       conversion factor from deg to rad
!---------------------------------------------------------------------------
PROGRAM A_Format_Of_Things
IMPLICIT NONE  !Must explicitly declare all variables

INTEGER :: i, deg, err1
REAL :: th, conv = 0.0174532925

! open file to write to
OPEN (UNIT=44, FILE="07_01_table.dat", STATUS='UNKNOWN', ACTION='WRITE', IOSTAT=err1)
! check for error opening file
IF (err1/=0) THEN
	WRITE(*,*) "error in file open"
	STOP
END IF

! initialize theta to zero
th = 0
! write header to file
WRITE(44,*) "Theta    SIN(Theta) COS(Theta) TAN(Theta)"
WRITE(44,*) "-----------------------------------------"
! write formatted values to file
DO i=0, 32, 1
	th = REAL(i) / 10
	WRITE(44,24) th, sin(th), cos(th), tan(th)
	24 FORMAT(F5.1,F12.4,F12.4,F12.4)
END DO

! write white space between tables
WRITE(44,*) " "
WRITE(44,*) " "
WRITE(44,*) " "

! write header to file
WRITE(44,*) "DEG     SIN(DEG)   COS(DEG)   TAN(DEG)"
WRITE(44,*) "--------------------------------------"
! write formatted and converted values to file
DO deg=0, 180, 5
	WRITE(44,25) deg, sin(REAL(deg*conv)), cos(REAL(deg*conv)), tan(REAL(deg*conv))
	25 FORMAT(I5,F11.4,F11.4,F11.4)
END DO

! close the file
CLOSE(44)

! Say Goodbye
   WRITE(*,*)
   WRITE(*,*) ' Have a Great Afternoon!!! '
   WRITE(*,*)

END PROGRAM
