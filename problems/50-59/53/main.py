
'''
There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, ( 5 C 3) = 10 .

In general, ( n C r) = n !  / (r !  ( n − r)) !  , where 
r ≤ n , n !  = n × ( n − 1) × .  .  .  × 3 × 2 × 1 , and 0 !  = 1 .

It is not until n = 23 , that a value exceeds one-million: ( 23 10) = 1144066 .

How many, not necessarily distinct, values of (n C r) for 1 ≤ n ≤ 100 , are 
greater than one-million?
'''

def factorial(x):
    out = 1
    for i in range(2, x + 1):
        out = out * i
    return out


def choose(n, r): 
    return factorial(n) / (factorial(r) * factorial(n - r))


count = 0
for n in range(1, 101):
    for r in range(1, n):
        val = choose(n, r)
        print(val, end="")
        if  val > 1000000:
            print(" over 1m")
            count += 1
        else:
            print("")
print(count)