#include <iostream>
#include <algorithm>


#include <string>
#include<map>
#include <list>

using namespace std;

/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, 
then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in 
words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and 
forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 
letters. The use of "and" when writing out numbers is in compliance with 
British usage.
*/

string first2digits(int num, map<int, string> name_map){
  string first2digits_str;
  int first2digits_int = num % 100;
  if (first2digits_int <= 20) {
    first2digits_str = name_map[first2digits_int];
  } else {
    int tens_digit = int(first2digits_int / 10);
    int ones_digit = first2digits_int % 10;
    if (ones_digit == 0) {
      first2digits_str = name_map[tens_digit * 10];
    } else {
      first2digits_str = name_map[tens_digit * 10] + "-" + name_map[ones_digit];
    }
  }
  return first2digits_str;
}


string thirddigit(int num, map<int, string> name_map){
  int third_digit = int((num % 1000) / 100);
  if (third_digit == 0) return "";
  return name_map[third_digit] + "-hundred";
}


string num2name(int num, map<int, string> name_map){
  // get first two digits
  string first2digits_str = first2digits(num, name_map);
  string third_digit_str = thirddigit(num, name_map);
  if (num == 1000) return "one-thousand";
  if (third_digit_str == "") return first2digits_str;
  if (first2digits_str == "zero") return third_digit_str;
  return third_digit_str + " and " + first2digits_str;
}


int main() {
  map<int, string>num2name_map;

  //Adding the elements
  num2name_map[0] = "zero";
  num2name_map[1] = "one";
  num2name_map[2] = "two";
  num2name_map[3] = "three";
  num2name_map[4] = "four";
  num2name_map[5] = "five";
  num2name_map[6] = "six";
  num2name_map[7] = "seven";
  num2name_map[8] = "eight";
  num2name_map[9] = "nine";
  num2name_map[10] = "ten";
  num2name_map[11] = "eleven";
  num2name_map[12] = "twelve";
  num2name_map[13] = "thirteen";
  num2name_map[14] = "fourteen";
  num2name_map[15] = "fifteen";
  num2name_map[16] = "sixteen";
  num2name_map[17] = "seventeen";
  num2name_map[18] = "eighteen";
  num2name_map[19] = "nineteen";
  num2name_map[20] = "twenty";
  num2name_map[30] = "thirty";
  num2name_map[40] = "forty";
  num2name_map[50] = "fifty";
  num2name_map[60] = "sixty";
  num2name_map[70] = "seventy";
  num2name_map[80] = "eighty";
  num2name_map[90] = "ninety";
  num2name_map[100] = "hundred";
  num2name_map[1000] = "thousand";

  int len_sum = 0;

  for (int i = 1; i <= 1000; i++){
    std::string numname = num2name(i, num2name_map);
    std::string::difference_type s = std::count(numname.begin(), numname.end(), ' ');
    std::string::difference_type h = std::count(numname.begin(), numname.end(), '-');
    // cout << numname << "---" << numname.size() - s - h << endl;
    len_sum += numname.size() - s - h;
  }
  cout << len_sum << endl; // 21124
  return 0;
}