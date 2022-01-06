/*
 * This is a short program to make a console version of hangman with a visual element.
 */

#include <iostream>
#include <string>
#include "hangmanheader.h"

void validateGuess(char, std::string);
void printHangman(int);

char allGuesses[26];
int totalGuesses;

int main()
{
    std::string hangmanword;
    int components = 10;
    int wrongGuesses = 0;
    char currentGuess;
    totalGuesses = 0;

    std::cout << "Please enter a word: ";
    std::cin >> hangmanword;
    std::cout << "\n";

    while (components > 0)
    {
        printHangman(wrongGuesses);

        std::cout << "Please enter a letter: ";
        std::cin >> currentGuess;
        std::cout << "\n";


        validateGuess(currentGuess, hangmanword);
    }

    return 0;
}

void validateGuess(char currentGuess, std::string hangmanword)
{
    /* check if player has already guessed this letter */
    for (int i = 0; i < totalGuesses; i++)
    {
        std::cout << "IN LOOP!\n";
        if (currentGuess == allGuesses[i])
        {
            std::cout << "You already guessed this letter! Try again.\n";
            return;
        }
    }
    std::cout << "HERE!\n";
    allGuesses[totalGuesses] = currentGuess;
    totalGuesses++;

}

void printHangman(int wrongGuesses)
{
    switch (wrongGuesses)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    }
}