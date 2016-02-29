!--------------------------------------------------------------------------
!  Header section:
!  TITLE: CSCI260A Lab 6 Lesson 2
!  AUTHOR: Adam Longoria	
!  CLASS:  CSCI260A
!  DATE WRITTEN: 02/16/14
!  LAST REVISION: 02/19/14
!  DESCRIPTION: This program demonstrates the Fortran's basic math operations.
!  VARIABLES USED:
!       NAME:           TYPE:           COMMENT:
!		mode			INTEGER			choice of encryption or decryption 
!		key				INTERGER		key to encrypt or decrypt with
!		ln				INTERGER		length of message
!		message			CHARACTER		input message from user
!		result			CHARACTER		result message after algorithm 
!---------------------------------------------------------------------------


PROGRAM decoderRing

!Implicit None  !Must explicitly declare all variables

! Declare the variables and initialize.

INTEGER :: mode, key, ln
CHARACTER(len=120) :: message, result
90 	FORMAT(A120)

! Code the Problem Here
result = ''

WRITE(*,*) "Enter a message to be encrypted or decrypted"
READ(*,90) message
WRITE(*,*) "Enter mode: [0]encrypted or [1]decrypted"
READ(*,*) mode
WRITE(*,*) "Enter the key to use"
READ(*,*) key
!mode = 1
!key = 15

!message = this is a message
!message = "PSP\"
ln = LEN_TRIM(message)
IF (mode == 0) THEN
	DO i = 1, ln
		result(i:i) = ACHAR(MOD(IACHAR(message(i:i))+key-32,94)+32)
	END DO
    WRITE(*,*) "Encrypted message is: ", result
ELSE
	DO i = 1, ln
		result(i:i) = ACHAR(MOD(IACHAR(message(i:i))+94-key-32,94)+32)
	END DO
    WRITE(*,*) "Decrypted message is: ", result
END IF




! Say Goodbye
   Write(*,*)
   Write(*,*) ' Have a Great Afternoon!!! '
   Write(*,*)

END PROGRAM
