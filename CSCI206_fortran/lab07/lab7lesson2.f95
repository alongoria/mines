!--------------------------------------------------------------------------
!  TITLE: CSCI260A Lab7 Lesson 2
!  AUTHOR: Adam Longoria
!  CLASS: CSCI260A
!  DATE WRITTEN: 03/04/14
!  LAST REVISION: 03/04/14
!  DESCRIPTION: Corrects error in dat file
!  VARIABLES USED:
!    NAME:     TYPE:	     	COMMENT:
!	 err1	   INTEGER		    error var for in file
!	 err2	   INTEGER			error var for out file
!	 col1  	   REAL				var for values in 1st column
!    col2	   REAL				var for values in 2nd column
!    correct   REAL, PARAMETER	constant var for 7.2% offset in data
!---------------------------------------------------------------------------

PROGRAM From_Here_to_There

IMPLICIT NONE  !Must explicitly declare all variables

INTEGER :: err1, err2
REAL :: col1, col2
REAL, PARAMETER :: correct = 1.072

! open input and output files 
OPEN (UNIT=19, FILE="inData.dat", STATUS='OLD', ACTION='READ', IOSTAT=err1)
OPEN (UNIT=44, FILE="outData.dat", STATUS='UNKNOWN', ACTION='WRITE', IOSTAT=err2)
! check for errors opening files
IF (err1/=0 .OR. err2/=0) THEN
	WRITE(*,*) "error in opening file"
END IF

! iterate through each line of file
DO 
	! read values from input file into separate variables
	READ(19,*,IOSTAT=err1) col1, col2
	! check for EOF
	IF (err1/=0) EXIT
	! multiply by correction factor
	col2=col2*correct
	! write values to output file
	WRITE(44,24) col1, col2
	24 FORMAT(F5.2,F12.4)
END DO

! close open files
CLOSE(19)
CLOSE(44)

! Say Goodbye
   WRITE(*,*)
   WRITE(*,*) ' Have a Great Afternoon!!! '
   WRITE(*,*)

END PROGRAM