!--------------------------------------------------------------------------
!  TITLE: CSCI260A Lab8 Lesson 2
!  AUTHOR: Adam Longoria
!  CLASS: CSCI260A
!  DATE WRITTEN: 03/18/14
!  LAST REVISION: 03/18/14
!  DESCRIPTION: program to merge two lists 
!  VARIABLES USED:
!    NAME:     TYPE:	     	COMMENT:
!    i         INT		counter variable
!    j         INT		counter variable
!    err1      INT		holder for error
!    err2      INT		holder for error
!    err3      INT		holder for error
!    a_count   INT		# of items in 'a' list
!    b_count   INT		# of items in 'b' list
!    c_count   INT		# of items in 'c' list
!    a         INT ARRAY	array of 'a' values
!    b         INT ARRAY	array of 'b' values
!    c         INT ARRAY	array of 'c' values
!---------------------------------------------------------------------------

PROGRAM file_merge

IMPLICIT NONE  !Must explicitly declare all variables

INTEGER :: i, j, err1, err2, err3, a_count, b_count, c_count
INTEGER,DIMENSION(100) :: a, b, c 

OPEN (UNIT=20, FILE="location1.dat", STATUS='OLD', ACTION='READ', IOSTAT=err1)
OPEN (UNIT=21, FILE="location2.dat", STATUS='OLD', ACTION='READ', IOSTAT=err2)
OPEN (UNIT=22, FILE="merged.dat", STATUS='UNKNOWN', ACTION='WRITE', IOSTAT=err3)

IF (err1/=0 .or. err2/=0 .or.err3/=0 ) THEN
	WRITE(*,*)"ERROR opening file(s)"
	STOP
END IF

i = 0
DO
	READ(20,*, IOSTAT=err1) a(i+1)
	IF(err1/=0) EXIT
	i = i + 1
END DO

j = 0
DO
	READ(21,*, IOSTAT=err2) b(j+1)
	IF(err2/=0) EXIT
	j = j + 1
END DO

a_count = 1
b_count = 1
c_count = 0

DO
	IF (a_count >= i .AND. b_count >= j) EXIT
	IF (a_count<i.AND.b_count<j)THEN
		
		IF (a(a_count)<b(b_count)) THEN
			c_count = c_count+1
			c(c_count) = a(a_count)
			a_count=a_count+1
		ELSE
			c_count = c_count+1
			c(c_count) = b(b_count)
			b_count=b_count+1
		END IF
	ELSE IF (a_count>=i.AND.b_count<j)THEN
			c_count = c_count+1
			c(c_count) = b(b_count)
			b_count=b_count+1
	ELSE IF (a_count<i.AND.b_count>=j)THEN
			c_count = c_count+1
			c(c_count) = a(a_count)
			a_count=a_count+1
	END IF
END DO	
DO i = 1, c_count
	WRITE(22,*)c(i)
END DO

CLOSE(20)
CLOSE(21)
CLOSE(22)

END PROGRAM





