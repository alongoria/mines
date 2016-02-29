PROGRAM ex3
IMPLICIT NONE

CHARACTER(len=30):: first, last
WRITE(*,*)"Enter your first name and last ", &
		  " name "
READ(*,*)first, last
WRITE(*,*)" hello ", first, last

END PRORGAM