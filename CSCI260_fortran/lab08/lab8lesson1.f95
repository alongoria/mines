!--------------------------------------------------------------------------
!  TITLE: CSCI260A Lab8 Lesson 1
!  AUTHOR: Adam Longoria
!  CLASS: CSCI260A
!  DATE WRITTEN: 03/18/14
!  LAST REVISION: 03/18/14
!  DESCRIPTION: calculate least squares regression line
!  VARIABLES USED:
!    NAME:     TYPE:	     	COMMENT:
!    points    INT		number of data points
!    err1      INT		holder for error code
!    err2      INT		holder for error code
!    x	       REAL		x value from data
!    y	       REAL		y value from data
!    x_sum     REAL		sum of x values
!    y_sum     REAL		sum of y values
!    x2_sum    REAL		sum of x^2 values
!    xy_sum    REAL		sum of x*y values
!    x_avg     REAL		average of x values
!    y_avg     REAL 		average of y values
!    slope     REAL		best fit slope
!    y_in      REAL		y-intercept
!---------------------------------------------------------------------------

PROGRAM least_squares

IMPLICIT NONE  !Must explicitly declare all variables

INTEGER :: points, err1, err2
REAL :: x = 0, y = 0, x_sum = 0, y_sum = 0, x2_sum = 0, xy_sum = 0, x_avg = 0, y_avg = 0, slope = 0, y_in = 0

OPEN (UNIT=19, FILE="inData.dat", STATUS='OLD', ACTION='READ', IOSTAT=err1)

DO
	! read data from file
	READ(19,*,IOSTAT=err2) x, y
	! check for EOF
	IF (err2/=0) EXIT
	! increase points count 
	points = points + 1
	
	x_sum = x_sum + x
	y_sum = y_sum + y
	x2_sum = x2_sum + x**x
	xy_sum = xy_sum + x*y
	
END DO

x_avg = x_sum / points
y_avg = y_sum / points

slope = ((xy_sum) - (x_sum * y_avg)) / ((x2_sum) - (x_sum * x_avg))
y_in = (y_avg - (slope * x_avg))

WRITE(*,*) "Slope equals: ", slope
WRITE(*,*) "Y-intercept equals: ", y_in
WRITE(*,*) "Number of input values is: ", points

CLOSE(19)

END PROGRAM