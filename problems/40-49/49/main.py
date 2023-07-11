from typing import List
from math import sqrt
from itertools import permutations

""" TODO: Update this into C++ code"""

def isprime(primes: List, x: int) -> bool:
    for prime in primes:
        if (x % prime == 0): return False
        elif (prime > sqrt(x)): return True
    return True


def build_primes():
    primes = [2, 3, 5, 7]
    for i in range(10000):
        if i < 11: continue
        if isprime(primes, i): 
            primes.append(i)
    return primes

primes = build_primes()
for prime in primes:
    if prime < 1000: continue
    for increment in [3330]:
        secondprime = prime + increment
        thirdprime = secondprime + increment
        p_permutations = [int("".join(p)) for p in permutations(str(prime))]

        if secondprime in p_permutations and thirdprime in p_permutations:
            if secondprime in primes and thirdprime in primes:
                print(prime, secondprime, thirdprime, sep="")

