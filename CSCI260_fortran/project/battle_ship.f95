!  TITLE: Battle Ship
!  AUTHORS: Adam Longoria
!		    Rebecca Ferguson
!           Jalen Champagne
!  CLASS: CSCI260A      
!  DATE WRITTEN: 04/12/14
!  LAST REVISION: 04/22/14 
!  DESCRIPTION: battleship game

PROGRAM BattleShip
IMPLICIT NONE

! PATH=C:\sw\g95\bin;PATH

! Set up Variables
 INTEGER :: check_for_win, check_for_choice, display_menu ! Set Up Functions
 INTEGER, DIMENSION(0:9,0:9) :: p1_locations = 0, p1_shots = 0, p2_locations = 0, p2_shots = 0
 INTEGER :: x = 0 ,y = 0, p1_hits = 0, p2_hits = 0
 INTEGER :: result = 0, win = 0;

 DO
	result = display_menu()
	IF( result == 1 ) THEN
	!////////////////////// RUN GAME ONE PERSON ////////////////////////////
			! NOT YET IMPLEMENTED
			STOP
	!////////////////////// RUN GAME TWO PERSON ////////////////////////////
	ELSE IF( result == 2) THEN
	   CALL  showMessage(1,1)
	   CALL get_locations(p1_locations)
	   CALL  showMessage(2,1)
	   CALL get_locations(p2_locations)
	   CALL  showMessage(3,2)
	   DO WHILE(check_for_win(p1_hits,p2_hits) == 0)
		 ! P1 Turn
		 CALL clear_screen()
		 WRITE(*,*) 'Player 1 Select A Target [Hit Enter To Fire]'
		 CALL draw_field(p1_shots)
		 CALL getInput(x,y)
		 CALL clear_screen()
		 IF( check_for_choice(x,y,p2_shots,p1_locations,p2_hits) == 1) THEN
			WRITE(*,*) 'Player 1 Has Hit Something [Hit Enter To Continue]'
		 ELSE
			WRITE(*,*) 'Player 1 Misses [Hit Enter To Continue]'
		 END IF
		 CALL draw_field(p1_shots)
		 READ(*,*)
		 
		 ! P2 Turn
		 CALL clear_screen()
		 WRITE(*,*) 'Player 2 Select A Target [Hit Enter To Fire]'
		 CALL draw_field(p2_shots)
		 CALL getInput(x,y)
		 CALL clear_screen()
		 IF( check_for_choice(x,y,p2_shots,p1_locations,p2_hits) == 1) THEN
			WRITE(*,*) 'Player 2 Has Hit Something [Hit Enter To Continue]'
		 ELSE
			WRITE(*,*) 'Player 2 Misses [Hit Enter To Continue]'
		 END IF
		 CALL draw_field(p2_shots)
		 READ(*,*)
	   END DO
		 
	   CALL showMessage(check_for_win(p1_hits,p2_hits),3)	 
	   READ(*,*)
	!////////////////////////////// HELP //////////////////////////////////
	ELSE IF( result == 3) THEN
		 CALL showRules()
	!////////////////////////////// QUIT //////////////////////////////////
	ELSE IF( result == 4) THEN
		STOP
 	END IF
 END DO

 READ(*,*)
STOP
END PROGRAM

!///////////////////////////////////// SUB & FUNCTIONS /////////////////////////////////////////////
!///////////////////////////////////////////////////////////////////////////////////////////////////
!///////////////////////////////////////////////////////////////////////////////////////////////////


!///////////////////////////////////// Show the Main menu //////////////////////////////////////////
INTEGER FUNCTION display_menu()
IMPLICIT NONE

    CALL clear_screen()
    ! used ascii generator to make cool texts
	! http://www.network-science.de/ascii/
	WRITE(*,*) "        __                __    __    ___             " 
	WRITE(*,*) "	/\ \              /\ \__/\ \__/\_ \             "
	WRITE(*,*) "	\ \ \____     __  \ \ ,_\ \ ,_\//\ \      __    "
	WRITE(*,*) "	 \ \ '__`\  /'__`\ \ \ \/\ \ \/ \ \ \   /'__`\  "
	WRITE(*,*) "	  \ \ \_\ \/\ \_\.\_\ \ \_\ \ \_ \_\ \_/\  __/  "
	WRITE(*,*) "	   \ \_,__/\ \__/.\_\\ \__\\ \__\/\____\ \____\ "
	WRITE(*,*) "           \/___/  \/__/\/_/ \/__/ \/__/\/____/\/____/ "
	WRITE(*,*) "													"
	WRITE(*,*) "        	              __                       "
	WRITE(*,*) "    		             /\ \      __              "
	WRITE(*,*) "   			  ___\ \ \___ /\_\  _____      "
   	WRITE(*,*) "			/',__\\ \  _ `\/\ \/\ '__`\   " 
	WRITE(*,*) "			\__, `\\ \ \ \ \ \ \ \ \_\ \  "
	WRITE(*,*) "			/\____/ \ \_\ \_\ \_\ \ ,__/  "
	WRITE(*,*) "			\/___/   \/_/\/_/\/_/\ \ \/   "
	WRITE(*,*) "				               \ \_\   "
	WRITE(*,*) "				                \/_/   "
	
	
	
	
	WRITE(*,*) '	<==============================================>'
	WRITE(*,*) '     		Select An Option And Press Enter'
	WRITE(*,*) ' ' 
	WRITE(*,*) '           1--One Player Game (not available)'
	WRITE(*,*) '                  2--Two Player Game'
	WRITE(*,*) '                   3--Instructions'
	WRITE(*,*) '                     4--Exit Game'
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
 
    READ(*,*) display_menu

END FUNCTION display_menu


!///////////////////////////////////// Show Messages /////////////////////////////////////
SUBROUTINE showMessage(n,mes)
IMPLICIT NONE

	INTEGER, INTENT(IN) :: n, mes

	CALL clear_screen()
	 
	IF (n == 1) THEN
		WRITE(*,*) '    ____  __                          ___'
		WRITE(*,*) '   / __ \/ /____ ___  _____  _____   <  /'
		WRITE(*,*) '  / /_/ / // __ `/ / / / _ \/ ___/   / / '
		WRITE(*,*) ' / ____/ // /_/ / /_/ /  __/ /      / /  '
		WRITE(*,*) '/_/   /_/ \__,_/\__, /\___/_/      /_/'
		WRITE(*,*) '               /____/                 '
		WRITE(*,*) '<==============================================>'
	ELSE IF (n == 2) THEN
	    WRITE(*,*) '    ____  __                          ___ '
		WRITE(*,*) '   / __ \/ /____ ___  _____  _____   |__ \'
		WRITE(*,*) '  / /_/ / // __ `/ / / / _ \/ ___/   __/ /'
		WRITE(*,*) ' / ____/ // /_/ / /_/ /  __/ /      / __/ '
		WRITE(*,*) '/_/   /_/ \__,_/\__, /\___/_/      /____/ '
		WRITE(*,*) '               /____/                     '
		WRITE(*,*) '<==============================================>'
	ELSE IF (n == 3) THEN
		WRITE(*,*) '    ____        __  __  __    '
		WRITE(*,*) '   / __ )____ _/ /_/ /_/ /___ '
		WRITE(*,*) '  / __  / __ `/ __/ __/ // _ \'
		WRITE(*,*) ' / /_/ / /_/ / /_/ /_/ //  __/'
		WRITE(*,*) '/_____/\__,_/\__/\__/_/ \___/  '                             
		WRITE(*,*) ' '
		WRITE(*,*) '       _____ __        __  _                  '
		WRITE(*,*) '      / ___// /_____ _/ /_(_)____  ____  _____'
		WRITE(*,*) '      \__ \/ __/ __ `/ __/ // __ \/ __ \/ ___/'
		WRITE(*,*) '     ___/ / /_/ /_/ / /_/ // /_/ / / / (__  ) '
		WRITE(*,*) '    /____/\__/\__,_/\__/_/ \____/_/ /_/____/  '
	END IF
	IF (mes == 1) THEN
		WRITE(*,*) '              Place Your Ships!'
		WRITE(*,*) '           [Hit Enter To Continue]'
	ELSE IF (mes == 2) THEN
		WRITE(*,*) '                 Get Ready!'
		WRITE(*,*) '           [Hit Enter To Continue]'
	ELSE IF (mes == 3) THEN
		WRITE(*,*) '                  YOU WIN!'
		WRITE(*,*) '           [Hit Enter To Continue]'
	END IF
	
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	 
	READ(*,*)
	
	RETURN

END SUBROUTINE showMessage


!///////////////////////////////////// Show The Rules //////////////////////////////////////////////
SUBROUTINE showRules()
IMPLICIT NONE

	CALL clear_screen()
	 
	WRITE(*,*) '****************** RULES *********************'
	WRITE(*,*) '1. Place your ships in the grid'
	WRITE(*,*) '2. Guess location of enemy ships and fire'
	WRITE(*,*) '3. First player to sink opponents ships wins'
	WRITE(*,*) ' '
	WRITE(*,*) 'You can hit the same place twice, but it will only count once'
	WRITE(*,*) 'You can only aim on the grid, (10 10) will be read as aim at (1 0)'
	
	WRITE(*,*) '              PRESS ENTER TO GO BACK...'
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	WRITE(*,*) ' '
	 
	READ(*,*)
	
	RETURN

END SUBROUTINE showRules


!///////////////////////////////////// See if a winner has been decided //////////////////////////////
INTEGER FUNCTION check_for_win(p1_hits, p2_hits)
  IMPLICIT NONE
  
  INTEGER, INTENT(IN) :: p1_hits, p2_hits
  
  IF(p1_hits >= 17) THEN 
  	check_for_win = 1 ! Player 1 Wins
  ELSE IF(p2_hits >= 17) THEN
  	check_for_win = 2 ! Player 2 Wins
  ELSE
  	check_for_win = 0 ! Still Playing
  END IF

END FUNCTION check_for_win


!///////////////////////////////////// Random Number Generator /////////////////////////////////////
INTEGER FUNCTION getRand(n)
  IMPLICIT NONE
  
  INTEGER, INTENT(IN) :: n
  INTEGER :: i
  REAL :: rand
  CALL random_seed()
  CALL random_number(rand)

  getRand = (rand * n + 1)

END FUNCTION getRand


!///////////////////////////////////// Get X & Y from player ///////////////////////////////////////
SUBROUTINE getInput(x,y)
IMPLICIT NONE

  INTEGER, INTENT(OUT) :: x ,y

  101 FORMAT (1I1,1X,1I1)
  READ(*,101) x, y

RETURN
END SUBROUTINE getInput


!///////////////////////////////////// Get Player Ship X Y H ///////////////////////////////////////
SUBROUTINE getShip(x, y, dir)
IMPLICIT NONE

  INTEGER, INTENT(OUT) :: x ,y
  CHARACTER(Len=1), INTENT(OUT) :: dir

  101 FORMAT (1I1,1X,1I1,1X,1A1)
  READ(*,101) x, y, dir

RETURN
END SUBROUTINE getShip


!///////////////////////////////////// When Fired check results ////////////////////////////////////
INTEGER FUNCTION check_for_choice(x,y,shots,locations,hits)
IMPLICIT NONE

  INTEGER, INTENT(OUT), DIMENSION(0:9,0:9) :: shots
  INTEGER, INTENT(IN), DIMENSION(0:9,0:9) :: locations
  INTEGER, INTENT(IN) :: x, y
  INTEGER, INTENT(OUT) :: hits
	
  IF(x > 9 .OR. x < 0 .OR. y > 9 .OR. y < 0) THEN 	
	check_for_choice = -1
  ELSE IF(shots(x,y) /= 0) THEN 
  	check_for_choice = -1
  ELSE IF(locations(x,y) == 1) THEN 
  	shots(x,y) = 1 ! Gi_verticale Hit
  	hits = hits + 1
  	check_for_choice = 1
  ELSE 
  	shots(x,y) = 2 ! Nothing
  	check_for_choice = 0
  END IF    

END FUNCTION check_for_choice


!///////////////////////////////////// Place Ships on Grid /////////////////////////////////////////
SUBROUTINE get_locations(locations)
IMPLICIT NONE

   INTEGER :: check_placement
   INTEGER, INTENT(OUT), DIMENSION(0:9,0:9) :: locations
   INTEGER :: x = 0 ,y = 0, i = 0
   CHARACTER(Len=1) ::  dir = ' '
   
   locations = 0
   CALL clear_screen()
   WRITE(*,*) 'Place Your Carrier (Size 5)'
   WRITE(*,*) 'X Y Direction [(H)orizontal or (V)ertical]'
   CALL draw_field(locations);
   DO 
   	   IF(check_placement(5,locations) == 0) THEN
   	   		EXIT
   	   END IF
       WRITE(*,*) 'Place Your Carrier (Size 5) IN THE GRID!'
       WRITE(*,*) 'X Y Direction [(H)orizontal or (V)ertical]'
       CALL draw_field(locations);
   END DO
   CALL clear_screen()
   WRITE(*,*) 'Place Your BattleShip (Size 4)'
   WRITE(*,*) 'X Y Direction [(H)orizontal or (V)ertical]'
   CALL draw_field(locations);
   DO WHILE(check_placement(4,locations) == 1)
       WRITE(*,*) 'Place Your BattleShip (Size 4) IN THE GRID!'
   	   WRITE(*,*) 'X Y Direction [(H)orizontal or (V)ertical]'
       CALL draw_field(locations);
   END DO
   CALL clear_screen()
   WRITE(*,*) 'Place Your Cruiser (Size 3)'
   WRITE(*,*) 'X Y Direction [(H)orizontal or (V)ertical]'
   CALL draw_field(locations);
   DO WHILE(check_placement(3,locations) == 1)
       WRITE(*,*) 'Place Your Cruiser (Size 3) IN THE GRID!'
  	   WRITE(*,*) 'X Y Direction [(H)orizontal or (V)ertical]'
       CALL draw_field(locations);
   END DO
   CALL clear_screen()
   WRITE(*,*) 'Place Your UBoat (Size 3)'
   WRITE(*,*) 'X Y Direction [(H)orizontal or (V)ertical]'
   CALL draw_field(locations);
   DO WHILE(check_placement(3,locations) == 1)
       WRITE(*,*) 'Place Your UBoat (Size 3) IN THE GRID!'
  	   WRITE(*,*) 'X Y Direction [(H)orizontal or (V)ertical]'
       CALL draw_field(locations);
   END DO
   CALL clear_screen()
   WRITE(*,*) 'Place Your Patrol Boat (Size 2)'
   WRITE(*,*) 'X Y Direction [(H)orizontal or (V)ertical]'
   CALL draw_field(locations);
   DO WHILE(check_placement(2,locations) == 1)
       WRITE(*,*) 'Place Your Patrol Boat (Size 2) IN THE GRID!'
       WRITE(*,*) 'X Y Direction [(H)orizontal or (V)ertical]'
       CALL draw_field(locations);
   END DO

RETURN
END SUBROUTINE get_locations


!///////////////////////////////////// When Ship Placed Check Results //////////////////////////////
INTEGER FUNCTION check_placement(size,locations)
IMPLICIT NONE

  INTEGER, INTENT(OUT), DIMENSION(0:9,0:9) :: locations
  INTEGER, INTENT(IN) :: size
  INTEGER :: i = 0, x = 0, y = 0;
  CHARACTER :: dir
  check_placement = 0;
  
  CALL getShip(x,y,dir)
  
  IF(dir == 'H' .OR. dir == 'h') THEN
     DO i=0,(size-1)
     	IF(x+i > 9 .OR. x < 0) THEN
     		check_placement = 1;
     	ELSE IF(y > 9 .OR. y < 0) THEN
     		check_placement = 1;
     	ELSE IF(locations(x+i,y) == 1) THEN
     		check_placement = 1;
     	END IF
     END DO
   ELSE IF(dir == 'V' .OR. dir == 'v') THEN
     DO i=0,(size-1)
     	IF(y+i > 9 .OR. y < 0) THEN
     		check_placement = 1;
     	ELSE IF(x > 9 .OR. x < 0) THEN
     		check_placement = 1;
     	ELSE IF(locations(x,y+i) == 1) THEN
     		check_placement = 1;
     	END IF
     END DO
  ELSE
  	 check_placement = 1;
  END IF
  
  IF(check_placement == 0) THEN
	  IF(dir == 'H' .OR. dir == 'h') THEN
		  DO i=0,(size-1)
			locations(x+i,y) = 1
		  END DO
	   ELSE IF(dir == 'V' .OR. dir == 'v') THEN
		  DO i=0,(size-1)
			locations(x,y+i) = 1
		  END DO
	   END IF
   END IF

END FUNCTION check_placement

!*********************************** draw the field ****************************************************
SUBROUTINE draw_field(shot) ! prints out the field with shots 
	IMPLICIT NONE

	INTEGER, INTENT(IN), DIMENSION(0:9,0:9) :: shot
	CHARACTER, DIMENSION(0:9) :: grid = ' '
	INTEGER :: i_vertical=0, i_horizontal=0, i=0

	  99 FORMAT (4X,I2,2X,I2,2X,I2,2X,I2,2X,I2,2X,I2,2X,I2,2X,I2,2X,I2,2X,I2)
	  WRITE(*,99)0,1,2,3,4,5,6,7,8,9
	  WRITE(*,*) '  +---+---+---+---+---+---+---+---+---+---+'
	  DO i_vertical=0,9  
	  
		DO i_horizontal=0,9
		  IF(shot(i_horizontal,i_vertical) == 0) THEN 
			grid(i_horizontal) = ' ' ! nothing
		  ELSE IF(shot(i_horizontal,i_vertical) == 1) THEN 
			grid(i_horizontal) = '*' ! confirmed hit
		  ELSE IF(shot(i_horizontal,i_vertical) == 2) THEN 
			grid(i_horizontal) = 'O' ! confirmed miss
		  END IF    
		END DO
		! way to format multiple things on one line with one WRITE statement, very weird
		100 FORMAT (I2,1X,A,1X,A,1X,A,1X,A,1X,A,1X,A,1X,A,1X,A,1X,A,1X,A,1X,A,1X,A,1X,A,1X, & 
		            A,1X,A,1X,A,1X,A,1X,A,1X,A,1X,A,1X,A)
		WRITE(*,100)i_vertical,'|',grid(0),'|',grid(1),'|',grid(2),'|',grid(3),'|',grid(4) & 
		            ,'|',grid(5),'|',grid(6),'|',grid(7),'|',grid(8),'|',grid(9),'|'
		WRITE(*,*) '  +---+---+---+---+---+---+---+---+---+---+'
		
	  END DO

	RETURN
END SUBROUTINE draw_field


!************************************* Clear the screen *******************************************
SUBROUTINE clear_screen() ! prints out the field
	IMPLICIT NONE

	INTEGER :: i=0
	  
	DO i=1,100
	   WRITE(*,*) ' '    
	END DO

	RETURN
END SUBROUTINE clear_screen

!*********************************** END SUB & FUNCTIONS ******************************************

