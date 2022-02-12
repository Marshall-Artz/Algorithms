/*  PROGRAM DESCRIPTION:
 *  Program receives a randomized string of numerical values (0-9 only)
 *  spelled out such as "oneonetwofourfive", and randomized, as an example,
 *  as "enfouoeornewtivof". The program will then identify which and how
 *  many numerical words are in the randomized string.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function used to remove instances of a word in a string
string removeLetters(string word, int wordTotal, string totalLetters)
{
    // Line for testing that shows whats being removed and the string being updated
    cout << "removeCall:\t" << word << '\t' << wordTotal << '\t' << totalLetters << endl;
    string removedTotalLetters = totalLetters;
    string removeWord = word;

    // Adds extra instances of the word to be removed as indicated by the user (wordTotal)
    for (int i = 0; i < (wordTotal - 1); i++) {
        removeWord += removeWord;
    }

    // I was/am working on making it a bit faster
    if (wordTotal > 0) {
        for (int i = 0; i < removedTotalLetters.size(); i++) {
            for (int j = 0; j < removeWord.size(); j++) {
                if (removedTotalLetters[i] == removeWord[j]) {
                    removedTotalLetters.erase(i, 1);
                    break;
                }
            }
        }
    }

    // // Big O(n^2) ... could be optimized
    // if (wordTotal > 0) {
    //     for (int i = 0; i < removeWord.size(); i++) {
    //         for (int j = 0; j < removedTotalLetters.size(); j++) {
    //             if (removedTotalLetters[j] == removeWord[i]) {
    //                 removedTotalLetters.erase(j, 1);
    //                 break;
    //             }
    //         }
    //     }
    // }

    return removedTotalLetters;
}

int main()
{
    // Answer:       zerooneoneonetwotwothreethreefourfivesixseveneightnineninenine
    string jumble = "ieizixnnvronenoeuenoeiohferrtsietohngenenwftnohetieeoerwtseven";

    // Values for counting unique letters
    int zeroCount = 0, oneCount = 0, twoCount   = 0, threeCount = 0, fourCount = 0;
    int fiveCount = 0, sixCount = 0, sevenCount = 0, eightCount = 0, nineCount = 0;

    //Count unique characters in randomized string
    for (int i = 0; i < jumble.size(); i++) {
        switch (jumble[i])
        {
        case 'z': // zero
            zeroCount++;
            break;
        case 'w': // two
            twoCount++;
            break;
        case 'u': // four
            fourCount++;
            break;
        case 'x': // six
            sixCount++;
            break;
        case 'g': // eight
            eightCount++;
            break;
        default:  // other
            break;
        }
    }

    // Remove those instances of the words in the string
    jumble = removeLetters("zero", zeroCount, jumble);
    jumble = removeLetters("two", twoCount, jumble);
    jumble = removeLetters("four", fourCount, jumble);
    jumble = removeLetters("six", sixCount, jumble);
    jumble = removeLetters("eight", eightCount, jumble);

    // Repeat count of unique characters in randomized string
    // (There are now new unique characters since other words have been removed)
    for (int i = 0; i < jumble.size(); i++) {
        switch (jumble[i])
        {
        case 'o':  // one
            oneCount++;
            break;
        case 't':  // three
            threeCount++;
            break;
        case 'f':  // five
            fiveCount++;
            break;
        case 's':  // seven
            sevenCount++;
            break;
        default:   // other
            break;
        }
    }

    // Remove those instances of the words in the string
    jumble = removeLetters("one", oneCount, jumble);
    jumble = removeLetters("three", threeCount, jumble);
    jumble = removeLetters("five", fiveCount, jumble);
    jumble = removeLetters("seven", sevenCount, jumble);

    // Repeat count of unique characters (for nine only) in randomized string
    for (int i = 0; i < jumble.size(); i++) {
        if (jumble[i] == 'i') {
            nineCount++;
        }
    }

    // Remove those instances of the words (for nine only) in the string
    jumble = removeLetters("nine", nineCount, jumble);

    // OUTPUT
    // Line 1
    cout << "\nzero:\t" << zeroCount << "\tone:\t" << oneCount << "\ttwo:\t" << twoCount << "\tthree:\t" << threeCount;
    cout << "\tfour:\t" << fourCount << endl;
    // Line 2
    cout << "five:\t" << fiveCount << "\tsix:\t" << sixCount << "\tseven:\t" << sevenCount << "\teight:\t" << eightCount;
    cout << "\tnine:\t" << nineCount << endl << endl;

}

// Order of unique characters for word removal by each loop/step

/*  zero    -> z
 *  one     -> NONE
 *  two     -> w
 *  three   -> NONE
 *  four    -> u
 *  five    -> NONE
 *  six     -> x
 *  seven   -> NONE
 *  eight   -> g
 *  nine    -> NONE
 */

/*  one     -> o
 *  three   -> t
 *  five    -> f
 *  seven   -> s
 *  nine    -> NONE
 */

/*  nine    -> n
 */