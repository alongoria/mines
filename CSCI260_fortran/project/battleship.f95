!------------------------------------------------------------
!	TITLE: BATTLESHIP
!	AUTHORS: Adam Longoria, Becca Ferguson, Jalen Champagne
!	CLASS: CSCI260A
!	DATE WRITTEN: 04/02/14
!	LAST REVISION: 04/02/14
!	DESCRIPTION: 
!
!	PATH=C:\sw\g95\bin;PATH
!------------------------------------------------------------

PROGRAM Battleship
	
	IMPLICIT NONE
	INTEGER :: i, j
	CHARACTER (len = 1), DIMENSION (11,11) :: board 
	
	
	
	DO i = 1 , 11
		DO j = 1, 11
			board(i,j) = '-'
			!WRITE(*,*) board(i,j)
		END DO
	END DO
	
	WRITE(*,*) board(1,1),board(1,2),board(1,3),board(1,4),board(1,5), & 
	board(1,6),board(1,7),board(1,8),board(1,9),board(1,10),board(1,11)
	
	WRITE(*,*) board(2,1),board(2,2),board(2,3),board(2,4),board(2,5), & 
	board(2,6),board(2,7),board(2,8),board(2,9),board(2,10),board(2,11)
	
	WRITE(*,*) board(3,1),board(3,2),board(3,3),board(3,4),board(3,5), & 
	board(3,6),board(3,7),board(3,8),board(3,9),board(3,10),board(3,11)
	
	WRITE(*,*) board(4,1),board(4,2),board(4,3),board(4,4),board(4,5), & 
	board(4,6),board(4,7),board(4,8),board(4,9),board(4,10),board(4,11)
	
	WRITE(*,*) board(5,1),board(5,2),board(5,3),board(5,4),board(5,5), & 
	board(5,6),board(5,7),board(5,8),board(5,9),board(5,10),board(5,11)
	
	
END PROGRAM
