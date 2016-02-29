##
# CSCI 101 Palindrome assignment
#
# Complete the functions isPalindrome and maxPalindrome
# according to the comments above the functions.  Run this script
# in IDLE to test your results.
##



# isPalindrome should return True if theSubList is a palindrome,
# False otherwise
def isPalindrome( theSubList ) :
	# students need to put some logic here
	return False



# maxPalindrome Returns the length of the largest palindrome 
# in the list, as well as its location.  If theList is
#   [ 0, 1, 2, 10, 11, 12, 13, 12, 11, ]
# the return value will be ( 5, 4 ) --- meaning a length of 5, 
# initial index of 4 (the first 11).
# 
# If theList doesn't contain a palindrome of length > 1, 
#   (0,0)
# is returned.
# 
def maxPalindrome( theSubList ) :
	# students need to put some logic here
	
	# this is how you return two values from a Python function
	return (0,0)




# test
candidatePs = [ 
		[1,], 
		range(8), 
		range(4)+range(3,-1,-1), 
		range(4)+[0]+range(3,-1,-1),
		range(3)+range(4)+[0]+range(3,-1,-1),
		]

for p in candidatePs :
	print p, isPalindrome( p )
	print p, "max", maxPalindrome( p )


