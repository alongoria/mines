!--------------------------------------------------------------------------
!  Header section:
!  TITLE: CSCI260 Lab 3 Lesson 2
!  AUTHOR: Adam	Longoria
!  CLASS:  CSCI260A
!  DATE WRITTEN: 1/24/14
!  LAST REVISION: 1/28/14
!  DESCRIPTION: This program demonstrates the Fortran's basic math operations.
!  VARIABLES USED:
!       NAME:           TYPE:           COMMENT:
!       player1			CHARACTER		length of 10, user input 		
!		player2			CHARACTER		length of 10, user input
!
!---------------------------------------------------------------------------

PROGRAM Lab3Lesson2

IMPLICIT NONE  !Must explicitly declare all variables

! Declare the variables.

CHARACTER(len=10) :: player1, player2


! Begin your code on the next line

WRITE(*,*) 'Player 1 enter choice'
READ(*,*) player1
WRITE(*,*) 'Player 2 enter choice'
READ(*,*) player2

!WRITE(*,*) 'player1 chose :', player1, ' player2 chose ', player2 

!
! Player 1 chooses rock
!

IF (player1 == 'ROCK' .OR. player1 == 'rock') THEN
	select case (player2)
	
		case ('paper')
			WRITE(*,*) 'Paper covers rock'
		case ('PAPER')
			WRITE(*,*) 'Paper covers rock'
			
		case ('scissors')
			WRITE(*,*) 'Rock crushes scissors'
		case ('SCISSORS')
			WRITE(*,*) 'Rock crushes scissors'
			
		case ('lizard')
			WRITE(*,*) 'Rock crushes lizard'
		case ('LIZARD')
			WRITE(*,*) 'Rock crushes lizard'

		case ('SPOCK')
			WRITE(*,*) 'Spock vaporizes rock'
		case ('spock')
			WRITE(*,*) 'Spock vaporizes rock'	
			
		case default
			WRITE(*,*) 'Nobody wins'
	end select

END IF

!
! Player 1 chooses paper
!

IF (player1 == 'PAPER' .OR. player1 == 'paper') THEN
	select case (player2)
	
		case ('rock')
			WRITE(*,*) 'Paper covers rock'
		case ('ROCK')
			WRITE(*,*) 'Paper covers rock'
			
		case ('scissors')
			WRITE(*,*) 'Scissors cuts paper'
		case ('SCISSORS')
			WRITE(*,*) 'Scissors cuts paper'
			
		case ('lizard')
			WRITE(*,*) 'Lizard eats paper'
		case ('LIZARD')
			WRITE(*,*) 'Lizard eats paper'

		case ('SPOCK')
			WRITE(*,*) 'Paper disproves Spock'
		case ('spock')
			WRITE(*,*) 'Paper disproves Spock'	
			
		case default
			WRITE(*,*) 'Nobody wins'
	end select

END IF

!
! Player 1 chooses scissors
!

IF (player1 == 'SCISSORS' .OR. player1 == 'scissors') THEN
	select case (player2)
	
		case ('paper')
			WRITE(*,*) 'Scissors cuts paper'
		case ('PAPER')
			WRITE(*,*) 'Scissors cuts paper'
			
		case ('rock')
			WRITE(*,*) 'Rock crushes scissors'
		case ('ROCK')
			WRITE(*,*) 'Rock crushes scissors'
			
		case ('lizard')
			WRITE(*,*) 'Scissors decapitates lizard'
		case ('LIZARD')
			WRITE(*,*) 'Scissors decapitates lizard'

		case ('SPOCK')
			WRITE(*,*) 'Spock smashes scissors'
		case ('spock')
			WRITE(*,*) 'Spock smashes scissors'	
			
		case default
			WRITE(*,*) 'Nobody wins'
	end select

END IF

!
! Player 1 chooses lizard
!


IF (player1 == 'LIZARD' .OR. player1 == 'lizard') THEN
	select case (player2)
	
		case ('paper')
			WRITE(*,*) 'Lizard eats paper'
		case ('PAPER')
			WRITE(*,*) 'Lizard eats paper'
			
		case ('scissors')
			WRITE(*,*) 'Scissors decapitates lizard'
		case ('SCISSORS')
			WRITE(*,*) 'Scissors decapitates lizard'
			
		case ('rock')
			WRITE(*,*) 'Rock crushes lizard'
		case ('ROCK')
			WRITE(*,*) 'Rock crushes lizard'

		case ('SPOCK')
			WRITE(*,*) 'Lizard poisons Spock'
		case ('spock')
			WRITE(*,*) 'Lizard poisons Spock'	
			
		case default
			WRITE(*,*) 'Nobody wins'
	end select

END IF

!
! Player 1 chooses spock
!


IF (player1 == 'SPOCK' .OR. player1 == 'spock') THEN
	select case (player2)
	
		case ('paper')
			WRITE(*,*) 'Paper disproves Spock'
		case ('PAPER')
			WRITE(*,*) 'Paper disproves Spock'
			
		case ('scissors')
			WRITE(*,*) 'Spock smashes scissors'
		case ('SCISSORS')
			WRITE(*,*) 'Spock smashes scissors'
			
		case ('lizard')
			WRITE(*,*) 'Lizard poisons Spock'
		case ('LIZARD')
			WRITE(*,*) 'Lizard poisons Spock'

		case ('ROCK')
			WRITE(*,*) 'Spock vaporizes rock'
		case ('rock')
			WRITE(*,*) 'Spock vaporizes rock'	
			
		case default
			WRITE(*,*) 'Nobody wins'
	end select

END IF


! Now let's add a little class to our program
   WRITE(*,*)
   WRITE(*,*) 'Have a Great Day!!! '
   WRITE(*,*)

   STOP
END PROGRAM !Lab3Lesson2

