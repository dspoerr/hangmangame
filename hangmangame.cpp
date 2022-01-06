/*
 * This is a short program to make a console version of hangman with a visual element.
 * Case sensitive. 
 */

#include <iostream>
#include <conio.h>
#include <string>
#include "hangmanheader.h"

void validateGuess(char, std::string);
void printLetters(std::string);
void printHangman(int);
void printGuesses(void);

char allGuesses[26];
int totalGuesses, correctGuesses;
int components;
bool lettersGuessed[26];

int main()
{
    std::string hangmanword;
    components = 10;
    char currentGuess;
    totalGuesses = 0;

    std::cout << "Please enter a word (max 26 letters): ";
    char l;
    /* TODO: add a catch for a user backspacing */
    while (l = _getch())
    {
        /* checking for user to hit enter (ASCII value 13) */
        if (l == 13)
        {
            break;
        }
        hangmanword = hangmanword + l;
        std::cout << "*";
    }
    std::cout << "\n";

    while (components > 0)
    {
        printHangman(components);
        printLetters(hangmanword);
        printGuesses();

        std::cout << "Please enter a letter: ";


        std::cin >> currentGuess;
        std::cout << "\n";

        validateGuess(currentGuess, hangmanword);

        if (correctGuesses == hangmanword.length())
        {
            std::cout << "Winner!\n";
            printLetters(hangmanword);
            return 0;
        }
    }

    std::cout << "You lost!\n";
    return 0;
}

/* validates whether the player guessed a correct or valid letter */
/* TODO: catch non-alphabet letters */
/* TODO: ignore case */
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
    /* if not, add to the list of guesses already made for future verification */
    allGuesses[totalGuesses] = currentGuess;
    totalGuesses++;

    /* verify if the guess is in the word */
    int j = 0;
    for (auto& letter : hangmanword)
    {
        if (currentGuess == letter)
        {
            lettersGuessed[j] = true; /* used for printLetters() */
            isCorrect = true; 
            correctGuesses++;
            std::cout << "Total correct guesses: " << correctGuesses << "\n";
        }
        j++;
    }

    /* player has one less chance to guess correctly */
    if (!isCorrect)
    {
        components--;
    }

}

/* prints all of the guessed letters of the hangman word. 
 * if not yet guessed, prints an 'X'
 */
void printLetters(std::string hangmanword)
{
    int j = 0;
    for (auto& ch : hangmanword)
    {
        if (lettersGuessed[j] == true)
        {
            std::cout << ch << "  ";
        }
        else
        {
            std::cout << "X" << "  ";
        }
        j++;
    }
    std::cout << "\n";

    for (int i = 0; i < hangmanword.length(); i++)
    {
        std::cout << "_" << "  ";
    }
    std::cout << "\n\n";
}


/* prints all of the letters the player has entered so far */
/* TODO: do not print , at the end */
void printGuesses()
{
    int i = 0;
    std::cout << "Letters guessed: ";

    for (int i = 0; i < totalGuesses; i++)
    {
        std::cout << allGuesses[i] << ", ";
    }
    std::cout << "\n";
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