PROGRAM stuff

	CHARACTER(len=4) :: string1  = 'Johnson', n1, n2, n3, n4, n5
	CHARACTER(len=10) :: string2 = ', Hi Bob.'
	REAL :: x = -3.141592654
	INTEGER :: i = 0
	CHARACTER(len=15), DIMENSION(10) :: names
	

	WRITE(*,100) string1, string2
	100 FORMAT (A8, A14)


	WRITE(*,101) x
	101 FORMAT(3X, F7.5)

	DO i = 0, 100
		WRITE(*,108) i
		108 FORMAT('+',I3) 
	END DO

	READ(*,*)n1, n2, n3, n4, n5 
	
	!WRITE(*,104) n1, n2, n3, n4, n5
	!104 FORMAT(5A5)
	
	names(1:5) = (/n1, n2 ,n3, n4, n5/)
	DO i = 1, 5
		WRITE(*,*) names(i)
	END DO
END PROGRAM stuff