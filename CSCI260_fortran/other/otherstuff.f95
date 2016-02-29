! FINAL PROJECT: BATTLESHIP
! AUTHORS:     Adam Longoria
!            Becca Ferguson
!            Jalen Champagne
! CLASS: CSCI 260A
! DATE WRITTEN: 04/02/2014
! LAST REVISION: 04/28/2014
! VARIABLES USED:
!         NAME:                            TYPE:            COMMENT:
!        ROWS                            INTEGER            number of rows in a standard battleship game (10)
!        COLUMNS                            INTEGER            number of columns in a standard battleship game (10)
!        Player_board/Board                INTEGER            General 2D arrays that are used in manipulation of the 4 2D arrays listed below
!        Player1_grid                    INTEGER            2D array. Keeps track of the first player's battleship positions
!        Player2_grid                     INTEGER            2D array. Keeps track of the second player's battleship positions
!        Player1_guess                    INTEGER            2D array. Keeps track of the guesses the 1st player has made
!        Player2_guess                    INTEGER            2D array. Keeps track of the guesses the 2nd player has made
!        Player1_boats/Boat_Count        INTEGER            Keeps track of the number of P1 boats still unguessed
!        Player2_boats/Boat_Count        INTEGER            Keeps track of the number of P2 boats still unguessed
!        loc_row                            INTEGER            Row player has decided to place their boat in
!        loc_column                        INTEGER            Column player has decided to place their boat in
!        shiptype                        INTEGER            Size of the boat being placed
!        direction_possibilities            INTEGER            Array tracking what directions are possible so only the correct ones are displayed
!        direc                            INTEGER            Chosen direction to move in
!        i, j                            INTEGER            Used for loops
!*****************************************************************
 
PROGRAM BattleShip
 
    IMPLICIT NONE
 
    INTEGER, PARAMETER :: ROWS = 10, COLUMNS = 10
    INTEGER, DIMENSION(ROWS, COLUMNS) :: Player1_grid = 0, Player2_grid = 0, Player1_guess = 0, Player2_guess = 0
    INTEGER :: Player1_boats = 0, Player2_boats = 0
 
    !CALL Print_Board(Player1_grid, ROWS, COLUMNS)
    WRITE(*,55)
    55 FORMAT(///)
    WRITE(*,*) "WELCOME TO BATTLESHIP!"
    WRITE(*,54)  
    54 FORMAT(///)
    WRITE(*,*) "*************************************************"
    WRITE(*,*) "PLAYER 1 PLEASE INITIALIZE YOUR BOARD"
        WRITE(*,*) "*************************************************"
    CALL Initialize(Player1_grid, ROWS, COLUMNS)
    !CALL Print_Board(Player1_grid, ROWS, COLUMNS)
    WRITE(*,*) "*************************************************"
    WRITE(*,*) "PLAYER 2 PLEASE INITIALIZE YOUR BOARD"
    WRITE(*,*) "*************************************************"
    CALL Initialize(Player2_grid, ROWS, COLUMNS)
 
    CALL Number_Ships(Player1_grid, ROWS, COLUMNS, Player1_boats)
    CALL Number_Ships(Player2_grid, ROWS, COLUMNS, Player2_boats)
 
    CALL Play_Game(Player1_grid, Player2_grid, Player1_guess, Player2_guess, ROWS, COLUMNS, Player1_boats, Player2_boats)
    
END PROGRAM BattleShip
 
 
SUBROUTINE Initialize(Player_board, ROWS, COLUMNS)
    IMPLICIT NONE
 
    INTEGER, INTENT(IN) :: ROWS, COLUMNS
    INTEGER, DIMENSION(ROWS, COLUMNS), INTENT(INOUT) :: Player_board
 
    CALL Boat(Player_board, ROWS, COLUMNS, 2)
    CALL Boat(Player_board, ROWS, COLUMNS, 3)
    CALL Boat(Player_board, ROWS, COLUMNS, 3)
    CALL Boat(Player_board, ROWS, COLUMNS, 4)
    CALL Boat(Player_board, ROWS, COLUMNS, 5)
    WRITE(*,51)  
    51 FORMAT (/////////////////////////////////////)
 
END SUBROUTINE Initialize
 
 
SUBROUTINE direction_of_ship(P_Board, ROWS, COLUMNS, loc_row, loc_column, shiptype, direc)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: loc_row, loc_column, shiptype, ROWS, COLUMNS
    INTEGER, INTENT(INOUT) :: direc
    INTEGER, DIMENSION(ROWS, COLUMNS), INTENT(IN) :: P_Board
    INTEGER, DIMENSION(0:4) :: direction_possibilities = 0
 
    DO
        IF (direction_possibilities(direc) == 1) EXIT
        direction_possibilities = 0
 
        WRITE(*,*) "Choose the option you would like"
        
        IF (shiptype == 2) THEN  
            IF (loc_row + 1 <= ROWS .AND. (P_Board(loc_row + 1, loc_column) == 0)) THEN
                WRITE(*,11)  loc_row,loc_column,  loc_row + 1, loc_column
                11 FORMAT ("1. (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(1) = 1
            END IF  
            IF (loc_row - 1 >= 1 .AND. (P_Board(loc_row - 1, loc_column) == 0)) THEN
                WRITE(*,12)  loc_row, loc_column, loc_row - 1, loc_column
                12 FORMAT("2. (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(2) = 1
            END IF  
            IF (loc_column + 1 <= COLUMNS .AND. (P_Board(loc_row, loc_column + 1) == 0)) THEN
                WRITE(*,13) loc_row, loc_column, loc_row, loc_column + 1
                13 FORMAT ("3. (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(3) = 1
            END IF  
            IF (loc_column - 1 >= 1 .AND. (P_Board(loc_row, loc_column - 1) == 0)) THEN
                WRITE(*,14) loc_row, loc_column, loc_row, loc_column - 1
                14 FORMAT("4. (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(4) = 1
            END IF
        ELSE IF (shiptype == 3) THEN
            IF (loc_row + 2 <= ROWS .AND. (P_Board(loc_row + 1, loc_column) == 0 .AND. P_Board(loc_row + 2, loc_column) == 0)) THEN
                WRITE(*,21)  loc_row, loc_column, loc_row + 1, loc_column, loc_row + 2, loc_column
                21 FORMAT("1. (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(1) = 1
            END IF
            IF (loc_row - 2 >= 1 .AND. (P_Board(loc_row - 1, loc_column) == 0 .AND. P_Board(loc_row - 2, loc_column) == 0)) THEN
                WRITE(*,22) loc_row, loc_column, loc_row - 1, loc_column, loc_row - 2, loc_column
                22 FORMAT("2. (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(2) = 1
            END IF
            IF (loc_column + 2 <= ROWS .AND. (P_Board(loc_row, loc_column + 1) == 0 .AND. P_Board(loc_row, loc_column + 2) == 0)) THEN
                WRITE(*,23) loc_row, loc_column, loc_row, loc_column + 1, loc_row, loc_column + 2
                23 FORMAT("3. (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(3) = 1
            END IF
            IF (loc_column - 2 >= 1 .AND. (P_Board(loc_row, loc_column - 1) == 0 .AND. P_Board(loc_row, loc_column - 2) == 0)) THEN
                WRITE(*,24) loc_row, loc_column, loc_row, loc_column - 1, loc_row, loc_column - 2
                24 FORMAT("4. (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(4) = 1
            END IF
        ELSE IF (shiptype == 4) THEN
            IF (loc_row + 3 <= ROWS .AND. (P_Board(loc_row + 1, loc_column) == 0 .AND. P_Board(loc_row + 2, loc_column) == 0 .AND. &
            P_Board(loc_row + 3, loc_column) == 0)) THEN
                WRITE(*,31) loc_row, loc_column, loc_row + 1, loc_column, loc_row + 2, loc_column, loc_row + 3, loc_column
                31 FORMAT("1. (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(1) = 1
            END IF
            IF (loc_row - 3 >= 1.AND. (P_Board(loc_row - 1, loc_column) == 0 .AND. P_Board(loc_row - 2, loc_column) == 0 .AND. &
            P_Board(loc_row - 3, loc_column) == 0)) THEN
                WRITE(*,32) loc_row, loc_column, loc_row - 1, loc_column, loc_row - 2, loc_column, loc_row - 3,loc_column
                32 FORMAT("2. (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(2) = 1
            END IF
            IF (loc_column + 3 <= COLUMNS .AND. (P_Board(loc_row, loc_column + 1) == 0 .AND. P_Board(loc_row, loc_column + 2) == 0 .AND. &
            P_Board(loc_row, loc_column + 3) == 0)) THEN
                WRITE(*,33) loc_row, loc_column, loc_row, loc_column + 1, loc_row, loc_column + 2, loc_row, loc_column + 3
                33 FORMAT("3. (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(3) = 1
            END IF
            IF (loc_column - 3 >= 1 .AND. (P_Board(loc_row, loc_column - 1) == 0 .AND. P_Board(loc_row, loc_column - 2) == 0 .AND. &
            P_Board(loc_row, loc_column - 3) == 0)) THEN
                WRITE(*,34) loc_row, loc_column, loc_row, loc_column - 1, loc_row, loc_column - 2, loc_row , loc_column - 3
                34 FORMAT("4. (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(4) = 1
            END IF
        ELSE IF (shiptype == 5) THEN
            IF (loc_row + 4 <= ROWS .AND. (P_Board(loc_row + 1, loc_column) == 0 .AND. P_Board(loc_row + 2, loc_column) == 0 .AND. &
            P_Board(loc_row + 3, loc_column) == 0 .AND. P_Board(loc_row + 4, loc_column) == 0)) THEN
                WRITE(*,41) loc_row, loc_column, loc_row + 1, loc_column, loc_row + 2, loc_column, loc_row + 3, loc_column,&
                loc_row + 4, loc_column
                41 FORMAT("1. (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(1) = 1
            END IF
            IF (loc_row - 4 >= 1 .AND. (P_Board(loc_row - 1, loc_column) == 0 .AND. P_Board(loc_row - 2, loc_column) == 0 .AND. &
            P_Board(loc_row - 3, loc_column) == 0 .AND. P_Board(loc_row - 4, loc_column) == 0)) THEN
                WRITE(*,42) loc_row, loc_column, loc_row - 1, loc_column, loc_row - 2, loc_column, loc_row - 3, loc_column,&
                loc_row - 4, loc_column
                42 FORMAT("2. (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(2) = 1
            END IF
            IF (loc_column + 4 <= COLUMNS .AND. (P_Board(loc_row, loc_column + 1) == 0 .AND. P_Board(loc_row, loc_column + 2) == 0 .AND. &
            P_Board(loc_row, loc_column + 3) == 0 .AND. P_Board(loc_row, loc_column + 4) == 0)) THEN
                WRITE(*,43)  loc_row, loc_column, loc_row, loc_column + 1, loc_row, loc_column + 2, loc_row, loc_column + 3, &
                loc_row, loc_column + 4
                43 FORMAT("3. (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(3) = 1
            END IF
            IF (loc_column - 4 >= 1 .AND. (P_Board(loc_row, loc_column - 1) == 0 .AND. P_Board(loc_row, loc_column - 2) == 0 .AND. &
            P_Board(loc_row, loc_column - 3) == 0 .AND. P_Board(loc_row, loc_column - 4) == 0)) THEN
                WRITE(*,44) loc_row, loc_column, loc_row, loc_column - 1, loc_row, loc_column - 2, loc_row , loc_column - 3, &
                loc_row, loc_column - 4
                44 FORMAT("4. (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ") & (", I2, ", ", I2, ")")
                direction_possibilities(4) = 1
            END IF
        END IF
        READ(*,*) direc
    END DO
END SUBROUTINE
 
SUBROUTINE Assign_ships(ROWS, COLUMNS, loc_row, loc_column, shiptype, direc, Player_board)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: ROWS, COLUMNS, loc_row, loc_column, shiptype, direc
    INTEGER, DIMENSION(ROWS, COLUMNS), INTENT(INOUT) :: Player_board
 
    SELECT CASE (direc)
 
    CASE(1)
        IF(shiptype == 2) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row + 1, loc_column) = 1
        ELSE IF (shiptype == 3) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row + 1, loc_column) = 1
            Player_board(loc_row + 2, loc_column) = 1    
        ELSE IF (shiptype == 4) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row + 1, loc_column) = 1
            Player_board(loc_row + 2, loc_column) = 1
            Player_board(loc_row + 3, loc_column) = 1
        ELSE IF (shiptype == 5) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row + 1, loc_column) = 1
            Player_board(loc_row + 2, loc_column) = 1
            Player_board(loc_row + 3, loc_column) = 1
            Player_board(loc_row + 4, loc_column) = 1
        END IF
    CASE(2)
        IF(shiptype == 2) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row - 1, loc_column) = 1
        ELSE IF (shiptype == 3) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row - 1, loc_column) = 1
            Player_board(loc_row - 2, loc_column) = 1    
        ELSE IF (shiptype == 4) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row - 1, loc_column) = 1
            Player_board(loc_row - 2, loc_column) = 1
            Player_board(loc_row - 3, loc_column) = 1
        ELSE IF (shiptype == 5) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row - 1, loc_column) = 1
            Player_board(loc_row - 2, loc_column) = 1
            Player_board(loc_row - 3, loc_column) = 1
            Player_board(loc_row - 4, loc_column) = 1
        END IF
    CASE(3)
        IF(shiptype == 2) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row, loc_column + 1) = 1
        ELSE IF (shiptype == 3) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row, loc_column + 1) = 1
            Player_board(loc_row, loc_column + 2) = 1    
        ELSE IF (shiptype == 4) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row, loc_column + 1) = 1
            Player_board(loc_row, loc_column + 2) = 1
            Player_board(loc_row, loc_column + 3) = 1
        ELSE IF (shiptype == 5) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row, loc_column + 1) = 1
            Player_board(loc_row, loc_column + 2) = 1
            Player_board(loc_row, loc_column + 3) = 1
            Player_board(loc_row, loc_column + 4) = 1
        END IF
    CASE(4)
        IF(shiptype == 2) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row, loc_column - 1) = 1
        ELSE IF (shiptype == 3) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row, loc_column - 1) = 1
            Player_board(loc_row, loc_column - 2) = 1    
        ELSE IF (shiptype == 4) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row, loc_column - 1) = 1
            Player_board(loc_row, loc_column - 2) = 1
            Player_board(loc_row, loc_column - 3) = 1
        ELSE IF (shiptype == 5) THEN
            Player_board(loc_row, loc_column) = 1
            Player_board(loc_row, loc_column - 1) = 1
            Player_board(loc_row, loc_column - 2) = 1
            Player_board(loc_row, loc_column - 3) = 1
            Player_board(loc_row, loc_column - 4) = 1
        END IF
    END SELECT
 
END SUBROUTINE
 
SUBROUTINE Boat(Player_board, ROWS, COLUMNS, shiptype)
    IMPLICIT NONE
 
    INTEGER, INTENT(IN) :: ROWS, COLUMNS, shiptype
    INTEGER, DIMENSION(ROWS, COLUMNS), INTENT(INOUT) :: Player_board
    INTEGER :: loc_row = 0, loc_column = 0, direc = 0
    
    DO WHILE (loc_row < 1 .OR. loc_row > 10 .OR. loc_column < 1 .OR. loc_column > 10)
        WRITE(*,50) shiptype
        50 FORMAT ("Where would you like your Patrol Boat of size ", I1, " to begin?")
        WRITE(*,*) "Please enter row (1-10)"
        READ(*,*) loc_row
        WRITE(*,*) "Please enter column (1-10)"
        READ(*,*) loc_column
    END DO
    
    DO WHILE (Player_board(loc_row, loc_column) == 1)  
        WRITE(*,*) "This spot is already filled, please choose again"
        WRITE(*,*) "Please enter row (1-10)"
        READ(*,*) loc_row
        WRITE(*,*) "Please enter column (1-10)"
        READ(*,*) loc_column
    END DO
 
    CALL direction_of_ship(Player_board, ROWS, COLUMNS, loc_row, loc_column, shiptype, direc)
    CALL Assign_ships(ROWS, COLUMNS, loc_row, loc_column, shiptype, direc, Player_board)
    direc = 0
    WRITE(*,52) shiptype
    52 FORMAT("Your current board, with the boat of size ", I1, " is: ")
    CALL Print_Board(Player_board, ROWS, COLUMNS)
    loc_row = 0
    loc_column = 0
    direc = 0
END SUBROUTINE Boat
 
 
!Print out the values within the board passed into the SUBROUTINE
SUBROUTINE Print_Board(board, ROWS, COLUMNS)
    INTEGER, INTENT(IN) :: ROWS, COLUMNS
    INTEGER, DIMENSION(ROWS, COLUMNS), INTENT(IN) :: board
    INTEGER :: i, j
 
    WRITE(*,*) "*************************************************"
    WRITE(*,*) "LEGEND"
    WRITE(*,*) "0 = EMPTY SPACE"
    WRITE(*,*) "1 = SHIP LOCATION"
    WRITE(*,*) "2 = INCORRECTLY GUESSED LOCATION"
    WRITE(*,*) "3 = HIT SHIP"
    WRITE(*,*) "*************************************************"
 
    DO i = 1, ROWS
        WRITE(*,10) (board(i,j), j = 1,COLUMNS)
        10 FORMAT(1X, 10I5)
    END DO  
 
    WRITE(*,*) "*************************************************"
 
END SUBROUTINE Print_Board
 
SUBROUTINE Number_Ships(board, ROWS, COLUMNS, Boat_Count)
    IMPLICIT NONE
    INTEGER :: i, j
    INTEGER, INTENT(IN) :: ROWS, COLUMNS
    INTEGER, INTENT(INOUT) :: Boat_Count
    INTEGER, DIMENSION(ROWS, COLUMNS), INTENT(INOUT) :: board
    
    DO i = 1, ROWS
        DO j = 1, COLUMNS
            IF (board(i,j) == 1) THEN
                Boat_Count = Boat_Count + 1
            END IF
        END DO
    END DO
 
END SUBROUTINE
 
SUBROUTINE Play_Game(Player1_board, Player2_board, Player1_guess, Player2_guess, ROWS, COLUMNS, Player1_boats, Player2_boats)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: ROWS, COLUMNS
    INTEGER, INTENT(INOUT) :: Player1_boats, Player2_boats
    INTEGER, DIMENSION(ROWS, COLUMNS), INTENT(INOUT) :: Player1_board, Player2_board, Player1_guess, Player2_guess
    INTEGER :: r, c
    
    DO  
        WRITE(*,*) "*************************************************"
        WRITE(*,*) "PLAYER 1, YOUR TURN TO MAKE A GUESS"
        WRITE(*,*) "YOUR PRIOR GUESSES ARE: "
        CALL Print_Board(Player1_guess, ROWS, COLUMNS)
        WRITE(*,*) "Enter a row "  
        READ(*,*) r
        WRITE(*,*) "Enter a column "  
        READ(*,*) c
        WRITE(*,*) "*************************************************"
 
        IF(Player2_board(r,c) == 1 .AND. Player1_guess(r,c) /= 3) THEN
            Player1_guess(r,c) = 3
            WRITE(*,*) "You've hit a ship!"
            WRITE(*,*) "*************************************************"
            WRITE(*,*) "Guesses Player1 has made"
            WRITE(*,*) "*************************************************"
            CALL Print_Board(Player1_guess, ROWS, COLUMNS)
            Player2_boats = Player2_boats - 1
        ELSE IF  (Player2_board(r,c) == 0) THEN
            Player1_guess(r,c) = 2
            WRITE(*,*) "You've guessed incorrectly"
            WRITE(*,*) "*************************************************"
            WRITE(*,*) "Guesses Player1 has made"
            WRITE(*,*) "*************************************************"
            CALL Print_Board(Player1_guess, ROWS, COLUMNS)
        ELSE IF(Player2_board(r,c) == 1 .AND. Player1_guess(r,c) == 3) THEN
            WRITE(*,*) "You've wasted a turn, you already guessed that location!!"
        END IF
        WRITE(*,*) "Press enter to continue"
        READ(*,*)
        IF(Player2_boats == 0) EXIT
        
        WRITE(*,56)
        56 FORMAT(/////)
        WRITE(*,*) "PLAYER 2, YOUR TURN TO MAKE A GUESS"
        WRITE(*,*) "YOUR PRIOR GUESSES ARE: "
        CALL Print_Board(Player2_guess, ROWS, COLUMNS)
        WRITE(*,*) "Enter a row "  
        READ(*,*) r
        WRITE(*,*) "Enter a column "  
        READ(*,*) c
        WRITE(*,*) "*************************************************"
 
        IF(Player1_board(r,c) == 1 .AND. Player2_guess(r,c) /= 3) THEN
            Player2_guess(r,c) = 3
            WRITE(*,*) "You've hit a ship!"
            WRITE(*,*) "*************************************************"
            WRITE(*,*) "Guesses Player2 has made"
            WRITE(*,*) "*************************************************"
            CALL Print_Board(Player2_guess, ROWS, COLUMNS)
            Player1_boats = Player1_boats - 1
        ELSE IF  (Player1_board(r,c) == 0) THEN
            Player2_guess(r,c) = 2
            WRITE(*,*) "You've guessed incorrectly"
            WRITE(*,*) "*************************************************"
            WRITE(*,*) "Guesses Player2 has made"
            WRITE(*,*) "*************************************************"
            CALL Print_Board(Player2_guess, ROWS, COLUMNS)
        ELSE IF (Player1_board(r,c) == 1 .AND. Player2_guess(r,c) == 3) THEN
            WRITE(*,*) "You've wasted a turn, you already guessed that location!!"
        END IF
        
        IF(Player1_boats == 0) EXIT
        
        WRITE(*,*) "Press enter to continue"
        READ(*,*)
        
        WRITE(*, 57)
        57 FORMAT(/////)
    END DO
    
    WRITE(*,*) "*************************************************"
    IF (Player1_boats == 0) THEN
        WRITE(*,*) "PLAYER 2 WINS!!"
    ELSE IF (Player2_boats == 0) THEN  
        WRITE(*,*) "PLAYER 1 WINS!!"
    END IF
    
END SUBROUTINE Play_Game
