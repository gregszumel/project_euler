'''
A googol ( 10^100) is a massive number: one followed by one-hundred zeros; 
100^100 is almost unimaginably large: one followed by two-hundred zeros. 
Despite their size, the sum of the digits in each number is only 1 .

Considering natural numbers of the form, a^b , where a , b < 100 , what is the 
maximum digital sum?
'''

# get the sum of the digits
def digit_sum(x: int) -> int:
    curr_sum = 0
    while x > 0:
        curr_sum += x % 10
        x = x // 10
    return curr_sum


def main ():
    # init max sum
    max_sum = 0
    # loop through all a^b (100 * 100 options)
    for a in range(100):
        for b in range(100):
            # get the sum of the digits
            ab_digit_sum = digit_sum(a**b)
            # update max found if larger
            if ab_digit_sum > max_sum: max_sum = ab_digit_sum

    # return max found
    return max_sum


if __name__ == "__main__":
    print(main())
