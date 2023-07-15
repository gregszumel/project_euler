'''
If we take 47, reverse and add, 47 + 74 = 121 , which is palindromic.

Not all numbers produce palindromes so quickly. For example,

 
349+943	    =1292	
1292+2921	=4213	
4213+3124	=7337 

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, 
never produce a palindrome. A number that never forms a palindrome through the 
reverse and add process is called a Lychrel number. Due to the theoretical 
nature of these numbers, and for the purpose of this problem, we shall assume 
that a number is Lychrel until proven otherwise. In addition you are given that
for every number below ten-thousand, it will either (i) become a palindrome in 
less than fifty iterations, or, (ii) no one, with all the computing power that 
exists, has managed so far to map it to a palindrome. In fact, 10677 is the 
first number to be shown to require over fifty iterations before producing a 
palindrome: 

4668731596684224866951378664 ( 53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel 
numbers; the first example is 4994 .

How many Lychrel numbers are there below ten-thousand?

NOTE: Wording was modified slightly on 24 April 2007 to emphasise the 
theoretical nature of Lychrel numbers.
'''


def ispalindrome(inp: str) -> bool: 
    """typical recursive palindrome finder"""
    assert len(inp) > 0, "zero input length"

    if len(inp) == 1:
        return True
    elif len(inp) == 2:
        return inp[0] == inp[1]
    elif inp[0] == inp[-1]:
        return ispalindrome(inp[1:-1])
    else:
        return False


def mirrored_number(x: int) -> int: 
    """mirror finder, could probably be optimized without strings"""
    mirror = ""
    for digit in reversed(str(x)):
        mirror += digit
    return int(mirror)


def islychrel(x: int) -> bool:
    """iterates through 50 iterations of lychrel"""
    for _  in range(50):
        x = x + mirrored_number(x)
        if ispalindrome(str(x)): return False

    return True


def main():
    # counter of lychrel numbers
    counter = 0

    # loop through every number less than 10000, seeing if its lychrel
    for potential_lychrel in range(1, 10_000):
        if islychrel(potential_lychrel):
            counter += 1

    print(counter)

if __name__ == "__main__":
    main()



