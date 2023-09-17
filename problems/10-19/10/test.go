package main

import ("fmt"
"math"
)

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

func isPrime(x int)bool {
    ceiling := int(math.Sqrt(float64(x)))
    for i:=2; i <= ceiling; i = i+1{
        if x%i == 0 { return false }
    }
    return true
}

func main() {
    sum := 5; // 2 + 3. Starting at 5
    for i:=5; i < 2000000; i++ {
        if isPrime(i) {
            sum += i
        }
    }
    fmt.Println(sum) // 142913828922
}
