!--------------------------------------------------------------------------
!  TITLE: CSCI260A Lab5 lesson 1
!  AUTHOR: ADAM LONGORIA     
!  CLASS: CSCI260A
!  DATE WRITTEN: 02/10/14
!  LAST REVISION: 02/10/14
!  DESCRIPTION: guessing game using a DO statement
!  VARIABLES USED:
!    NAME:           TYPE:     COMMENT:
!    x	             REAL      used for random number
!    ans	     INTEGER   scaled random number
!    guess	     INTEGER   user input guess
!---------------------------------------------------------------------------

PROGRAM guessGame

IMPLICIT NONE  !Must explicitly declare all variables

! Declare the variables and initialize.
    REAL:: x
    INTEGER:: ans, guess
    CALL random_seed()         
    CALL RANDOM_NUMBER(x)
    ans = 1 + INT(x * 100)
! Code the Problem Here
	
	WRITE(*,*) "Enter a guess"
    READ(*,*) guess
    
    
    DO 
        IF (guess < ans) THEN
            WRITE(*,*) "too low"
        END IF
        
        IF (guess > ans) THEN
            WRITE(*,*) "too high"
        END IF
        
        IF (guess == ans) THEN
            WRITE(*,*) "correct"
            EXIT
        END IF
        
        READ(*,*) guess
    END DO
    
! Say Goodbye
   WRITE(*,*)
   WRITE(*,*) ' Have a Great Afternoon!!! '
   WRITE(*,*)

END PROGRAM


