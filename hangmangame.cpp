/*
 * This is a short program to make a console version of hangman with a visual element.
 * Case sensitive. 
 */

#include <iostream>
#include <string>
#include "hangmanheader.h"

void validateGuess(char, std::string);
void printHangman(int);

char allGuesses[26];
int totalGuesses, correctGuesses;
int components;

int main()
{
    std::string hangmanword;
    int components = 10;
    char currentGuess;
    totalGuesses = 0;

    std::cout << "Please enter a word: ";
    std::cin >> hangmanword;
    std::cout << "\n";

    while (components > 0)
    {
        printHangman(components);

        std::cout << "Please enter a letter: ";
        std::cin >> currentGuess;
        std::cout << "\n";


        validateGuess(currentGuess, hangmanword);

        if (correctGuesses == hangmanword.length())
        {
            std::cout << "Winner!\n";
            return 0;
        }
    }

    return 0;
}

void validateGuess(char currentGuess, std::string hangmanword)
{
    bool isCorrect = false;
    /* check if player has already guessed this letter */
    for (int i = 0; i < totalGuesses; i++)
    {
        if (currentGuess == allGuesses[i])
        {
            std::cout << "You already guessed this letter! Try again.\n";
            return;
        }
    }
    allGuesses[totalGuesses] = currentGuess;
    totalGuesses++;

    for (auto& letter : hangmanword)
    {
        if (currentGuess == letter)
        {
            isCorrect = true;
            correctGuesses++;
            std::cout << "Total correct guesses: " << correctGuesses << "\n";
        }
    }

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