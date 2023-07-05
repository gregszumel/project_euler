#include <iostream>
#include <fstream>
#include <list>
using namespace std;


/* The nth term of the sequence of triangle numbers is given by, 
 t_n = 1/2 n (n + 1) ; so the first ten triangle numbers are:
1 , 3 , 6 , 10 , 15 , 21 , 28 , 36 , 45 , 55 , …

By converting each letter in a word to a number corresponding to its 
alphabetical position and adding these values we form a word value. For example,
the word value for SKY is 19 + 11 + 25 = 55 = t_10 . If the word value is a 
triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file 
containing nearly two-thousand common English words, how many are triangle 
words?
*/

int letter_num(char letter) {
    switch (letter) {
        case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        case 'D': return 4;
        case 'E': return 5;
        case 'F': return 6;
        case 'G': return 7;
        case 'H': return 8;
        case 'I': return 9;
        case 'J': return 10;
        case 'K': return 11;
        case 'L': return 12;
        case 'M': return 13;
        case 'N': return 14;
        case 'O': return 15;
        case 'P': return 16;
        case 'Q': return 17;
        case 'R': return 18;
        case 'S': return 19;
        case 'T': return 20;
        case 'U': return 21;
        case 'V': return 22;
        case 'W': return 23;
        case 'X': return 24;
        case 'Y': return 25;
        case 'Z': return 26;
        default: return -1;
    }
}

int wordvalue(string word) {
    int wordsum = 0;
    for (char letter: word) {
        wordsum += letter_num(letter);
    }
    return wordsum;
}

list<int> build_triangle_numbers(int maxvalue) {
    list<int> triangle_numbers;
    float n = 1;
    while (true) {
        int triangle = n / 2 * (n + 1);
        triangle_numbers.push_back(triangle);
        if (triangle > maxvalue) break;
        n++;
    }
    return triangle_numbers;
}

bool contains(list<int> triangles, int val) {
    for (int triangle: triangles) {
        if (triangle == val) return true;
    }
    return false;
}


int main() {
    int triangle_counter = 0;
    int maxvalue = wordvalue("ZZZZZZZZZZZZ");
    list<int> triangle_numbers = build_triangle_numbers(maxvalue);

    ifstream f;
    f.open("0042_words.txt", ios::in); //open a file to perform read operation using file object

    if (f.is_open()){ //checking whether the file is open
        string word;
        int value;
        while(getline(f, word, ',')){ //read data from file object and put it into string.
            word = word.substr(1, word.size()- 2);
            value = wordvalue(word);
            cout << word << ": " << value;
            if (contains(triangle_numbers, value)) {
                cout << " and is triangle!";
                triangle_counter++;
            }
            cout << endl;
        }
        f.close(); //close the file object.
    }
    cout << triangle_counter << endl;
}
