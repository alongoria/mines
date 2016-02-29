PROGRAM HW5

	INTEGER :: i, i1, i2
	REAL :: a, b , suum, diff
	CHARACTER(5) :: x
	CHARACTER(10) :: y
	CHARACTER(15) :: z
	CHARACTER(len=20) :: fmt
	fmt =  "('1','i=',I6.5)"
	i = -123
	WRITE(*,fmt) i
	
	
	a = 1.0020E6
	b = 1.0001E6
	suum = a + b
	diff = a - b
	WRITE(*,100) a, b, suum, diff
	100 FORMAT (1X, 'A = ', ES14.6, ' B = ', E14.6, ' Sum = ', E14.6, ' Diff = ', F14.6)
	
	i1 = 10
	i2 = 4**2
	WRITE(*,300) i1 > i2
	300 FORMAT (' ','Result = ', L6)
	
	READ(*,'(3A10)') x, y, z
	WRITE(*,*) x
	WRITE(*,*) y
	WRITE(*,*) z
	
END PROGRAM HW5