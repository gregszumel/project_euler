from typing import List

# It is possible to show that the square root of two can be expressed as an 
# infinite continued fraction.
# 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ...)))
# 
# By expanding this for the first four iterations, we get:
# 
# 1 + 1/2 = 3 2 = 1.5
# 
# 1 + 1/(2 + 1/2) = 7/5 = 1.4
# 
# 1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666 …
# 
# 1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379 …
# 
# The next three expansions are 99/70 , 239/169 , and 577/408 , but the eighth 
# expansion, 1393/985 , is the first example where the number of digits in the 
# numerator exceeds the number of digits in the denominator.
# 
# In the first one-thousand expansions, how many fractions contain a numerator 
# with more digits than the denominator?
# # 1 + 1/2 = 3 / 2
# # 1 + 1/(2 + 1/2) = 1 + 1/(5/2) = 1 + 2/5 = 7/5
# # 1 + 1/(2 + 1/(2 + 1/2)) = 1 + 1/(2 + 2/5) = 1 + 1/(12/5) = 1 + 5/12 = 17/12
# # 1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 1 + 1 /(2 + 5/12) = 1 + 1/(29/12) = 1 + 12/29 = 41/29


def get_next_frac(numerator: int, denominator: int) -> List[int]:
    numerator = numerator +  2 * denominator
    numerator, denominator =  denominator, numerator
    return [numerator, denominator]


def main(): 
    numerator, denominator = 1, 2
    nchecked = 0
    counter = 0
    while nchecked < 1000:
        numerator, denominator =  get_next_frac(numerator, denominator)
        output_numerator = numerator + denominator
        if len(str(output_numerator)) > len(str(denominator)): counter += 1
        nchecked += 1

    print(counter)


if __name__ == "__main__":
    main()
