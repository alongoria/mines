PROGRAM stuff

IMPLICIT NONE

	REAL :: temp

	WRITE(*,*) "Enter temperature"
	READ(*,*) temp

	IF (temp < 97.5) THEN
		WRITE(*,*) "temp below normal"
	ELSE IF (temp > 103.0) THEN
		WRITE(*,*) "temp dangerously high"
	ELSE IF (temp > 99.5) THEN
		WRITE(*,*) "temp slightly high"
	ELSE IF (temp >= 97.5) THEN
		WRITE(*,*) "temp normal"
	END IF

END PROGRAM stuff