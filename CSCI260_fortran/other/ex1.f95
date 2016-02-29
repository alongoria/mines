! comment 
PROGRAM ex1
IMPLICIT NONE

INTEGER:: i, j, k

WRITE(*,*)"Please enter two integers"
READ(*,*)i, j
k = i + j
WRITE(*,*)i, "+", j, "=", k
STOP

END PROGRAM