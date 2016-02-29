!--------------------------------------------------------------------------
!  TITLE: CS260 Lab9 lesson 1
!  AUTHOR: 
!  CLASS:  
!  DATE WRITTEN: 
!  LAST REVISION: 
!  DESCRIPTION: 
!  VARIABLES USED:
!    NAME:           TYPE:     COMMENT:
!
!
!
!---------------------------------------------------------------------------

Program lucky_7

implicit none  !Must explicitly declare all variables

! Declare the variables and initialize.
REAL:: x
INTEGER::d1, d2, munny = 100, ch, bet
CHARACTER::ans


! Code the Problem Here

WRITE(*,*)" ************************************************************"
WRITE(*,*)" This is a betting game called Lucky - 7, you start with $100"
WRITE(*,*)" Dice are rolled and you can bet on different dice values"
WRITE(*,*)"     1 - 6  pays out 1:1"
WRITE(*,*)"     7      pays out 3:1"
WRITE(*,*)"     8 - 12 pays out 1:1"
WRITE(*,*)" ************************************************************"




        CALL RANDOM_SEED
        DO
                CALL getBet(bet, ch)
                CALL RANDOM_NUMBER(x)
                d1 = INT(x * 6) +1
                CALL RANDOM_NUMBER(x)
                d2 = INT(x * 6) +1

                WRITE(*,*)"Die 1 is ", d1
                WRITE(*,*)"Die 2 is ", d2

                IF(ch==1 .AND. d1+d2<7) THEN
                        WRITE(*,*)"You win!!!"
                        munny = munny + bet
                ELSE IF (ch==2 .AND. d1+d2==7) THEN
                        WRITE(*,*)"You win!!!"
                        munny = munny + bet*3
                ELSE IF(ch==3 .AND. d1+d2>7) THEN
                        WRITE(*,*)"You win!!"
                                munny = munny + bet
                ELSE
			WRITE(*,*)"You loose .... :("
			munny = munny - bet
		END IF

		WRITE(*,*)"You have  $", munny

		IF (munny < 0 ) THEN
			WRITE(*,*)"You have ran out of munny.  Game over.."
			EXIT
		END IF
		WRITE(*,*)"Do you wish to continue playing the game? (y/n)"
		READ(*,*)ans
		if(ans=='n') EXIT
	END DO






! Say Goodbye
   Write(*,*)
   Write(*,*) ' Have a Great Afternoon!!! '
   Write(*,*)

CONTAINS


SUBROUTINE getBet(amount, d_values)
IMPLICIT NONE  !Must explicitly declare all variables
        INTEGER, INTENT(OUT):: amount, d_values

		WRITE(*,*)"*****************************************************"
 		WRITE(*,*)"What range of dice values do you wish to bet on?"
        	WRITE(*,*)"1.  For 1 - 6 "
        	WRITE(*,*)"2.  For 7 "
        	WRITE(*,*)"3.  For 8 - 12 "
        	WRITE(*,*)"*****************************************************"
        	READ(*,*) d_values
        	DO
                	IF (d_values >= 1 .AND. d_values <= 3)EXIT
                	WRITE(*,*)"You entered an invalid choice, choose again"
                	READ(*,*) d_values
        	END DO
        	WRITE(*,*)"*****************************************************"
        	WRITE(*,*)"How much do you wish to bet??"
        	READ(*,*) amount
        	WRITE(*,*)"*****************************************************"
END SUBROUTINE


End Program   !Lucky_7


