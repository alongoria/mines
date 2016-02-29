!--------------------------------------------------------------------------
!  TITLE: CS260 Lab8 Lesson 2
!  AUTHOR:Yang Liu	
!  CLASS:CSCI260A
!  DATE WRITTEN:3/7/2014
!  LAST REVISION:3/7/2014
!  DESCRIPTION:This program is to merge the two files
!  VARIABLES USED:
!    NAME:           TYPE:     COMMENT:
!	err1			Integer		the first error for this program
!	err2			Integer		the second error for this program
!	c1				Integer		the number for the location 1
!	c2				Integer		the number for the location 2
!	i				Integer		the number of the steps for i
!	j				Integer		the number of the steps for j
!	aCount			Integer		the number of values that the user input for a
!	bCount			Integer		the number of values that the user input for b
!	cCount			Integer		the number of values that the user input for c
!	a				Integer		the array number sets for a
!	b				Integer		the array number sets for b
!	c				Integer		the array number sets for c
!---------------------------------------------------------------------------

PROGRAM Merge

IMPLICIT NONE  !Must explicitly declare all variables

! Declare the variables and initialize.
INTEGER::err1,err2,err3, c1, c2, i, j, aCount, bCount, cCount
INTEGER,DIMENSION(100):: a, b, c
! Code here
OPEN(UNIT=22, FILE="location1.dat",STATUS="OLD",ACTION="READ", IOSTAT=err1)
OPEN(UNIT=25, FILE="location2.dat",STATUS="OLD",ACTION="READ", IOSTAT=err2)

OPEN(UNIT=34, FILE="Merge.dat",STATUS="UNKNOWN",ACTION="WRITE", IOSTAT=err3)


IF (err1/=0 .or. err2/=0 .or.err3/=0 ) THEN
	WRITE(*,*)"ERROR in file open"
	STOP
END IF

c1 = 0
DO 
	READ(22,*,IOSTAT=err1) a(c1+1)
write(*,*) a(c1+1)
	IF(err1/=0) EXIT
	
	c1 = c1 + 1
END DO
c2 = 0

DO
	READ(25,*,IOSTAT=err2) b(c2+1)
	write(*,*) b(c2+1)
	IF(err2/=0) EXIT
	c2 = c2 + 1
END DO
aCount = 1
bCount= 1
cCount = 0

DO
write(*,*)a(aCount),"  ", b(bCount)
write(*,*)"aCount is ", aCount, "bCount is ", bCount, "cCount is ", cCount
	IF (aCount >= c1 .AND. bCount>=c2) EXIT
	IF (aCount<c1.AND.bCount<c2)THEN
		
		IF (a(aCount)<b(bCount)) THEN
			cCount = cCount+1
			c(cCount) = a(aCount)
			aCount=aCount+1
		ELSE
			cCount = cCount+1
			c(cCount) = b(bCount)
			bCount=bCount+1
		END IF
	ELSE IF (aCount>=c1.AND.bCount<c2)THEN
			cCount = cCount+1
			c(cCount) = b(bCount)
			bCount=bCount+1
	ELSE IF (aCount<c1.AND.bCount>=c2)THEN
			cCount = cCount+1
			c(cCount) = a(aCount)
			aCount=aCount+1
	END IF
END DO	
DO i = 1, cCount
	WRITE(34,39)c(i)
39	FORMAT (2X,I8)
END DO

CLOSE(22)
CLOSE(25)


! Say Goodbye
	WRITE(*,*)
	WRITE(*,*) 
	WRITE(*,*) "You can see the Data in the Merge File"
	WRITE(*,*)
	WRITE(*,*) 
	WRITE(*,*) ' Have a Great Afternoon!!! '
	WRITE(*,*)

END PROGRAM
