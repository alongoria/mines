PROGRAM decoderRing

!Implicit None  !Must explicitly declare all variables

! Declare the variables and initialize.

INTEGER :: mode, key
CHARACTER(len=120) :: message, result

! Code the Problem Here

WRITE(*,*) "Enter a message to be encrypted or decrypted"
READ(*,90) message
WRITE(*,*) "Enter mode: [0]encrypted or [1]decrypted"
READ(*,*) mode

!mode = 1
!key = 15

!message = this is a message
!message = "PSP\"

IF (mode == 0) THEN
    result(i:i) = ACHAR(MOD(IACHAR(message(i:i))+key-32,94)+32)
    WRITE(*,*) "Encrypted message is: ", result
ELSE
    result(i:i) = ACHAR(MOD(IACHAR(message(i:i))-key-32,94)+32)
    WRITE(*,*) "Decrypted message is: ", result
END IF




! Say Goodbye
   Write(*,*)
   Write(*,*) ' Have a Great Afternoon!!! '
   Write(*,*)

END PROGRAM
