/*
 * This is a short program to make a console version of hangman with a visual element.
 * Case sensitive. 
 * 
 * Text file words_alpha.txt sourced from https://github.com/dwyl/english-words
 */

#include <iostream>
#include <conio.h>
#include <string>
#include "hangmanheader.h"
#include <random>
#include <fstream>
#include <algorithm>

void validateGuess(char, std::string);
void printLetters(std::string);
void printHangman(int);
void printGuesses(void);
void hangmanheader_init(void);
std::string gameReset(void);
std::string getWord(void);
std::string findInFile(int index);

char allGuesses[26];
int totalGuesses, correctGuesses;
int components;
bool lettersGuessed[26];


int main()
{
    hangmanheader_init();

    std::string hangmanword;
    char currentGuess = ' ';
    
    hangmanword = gameReset();

    while (components > 1)
    {
        std::cout << "\n\n====================\n";
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

            currentGuess = ' ';
            while (currentGuess != 'y' && currentGuess != 'n')
            {
                std::cout << "Play again? (y/n): ";
                std::cin >> currentGuess;
                std::cout << "\n";
            }

            if (currentGuess == 'y')
            {
                hangmanword = gameReset();
            }
            else
            {
                return 0;
            }
        }
        std::cout << "====================\n";

        if (components == 1)
        {
            std::cout << "\n\n\nYou lost!\n";
            printHangman(components);
            std::cout << "Word was: " << hangmanword << "\n";

            currentGuess = ' ';
            while (currentGuess != 'y' && currentGuess != 'n')
            {
                std::cout << "Play again? (y/n): ";
                std::cin >> currentGuess;
                std::cout << "\n";
            }

            if (currentGuess == 'y')
            {
                hangmanword = gameReset();
            }
        }
    }

    
    return 0;
}

/* validates whether the player guessed a correct or valid letter */
void validateGuess(char currentGuess, std::string hangmanword)
{
    bool isCorrect = false;
    /* check if player has already guessed this letter */
    for (int i = 0; i < totalGuesses; i++)
    {
        if (currentGuess == allGuesses[i])
        {
            std::cout << "You already guessed this letter! Try again: ";
            std::cin >> currentGuess;
            validateGuess(currentGuess, hangmanword);
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
            correctGuesses++; /* determines whether the entire word has been guessed */
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
void printGuesses()
{
    int i = 0;
    std::cout << "Letters guessed: ";

    for (int i = 0; i < totalGuesses; i++)
    {
        std::cout << allGuesses[i];

        if (i < (totalGuesses - 1))
        {
            std::cout << ",";
        }
    }
    std::cout << "\n";
}


void printHangman(int wrongGuesses)
{
    /* TODO: clean up the logic here */
    int i = 1;
    std::cout << "Mistakes remaining: " << wrongGuesses - 1 << "\n";

    for (auto& art : hangmanArt)
    {
        /* without this, does not seem to print on loss */
        if (wrongGuesses == 0)
        {
            art.print();
            return;
        }
        if (i == wrongGuesses)
        {
            art.print();
            return;
        }
        i++;
    }


}


std::string findInFile(int index)
{
    int j = 0;
    std::string val;
    std::ifstream data;
    data.open("words_alpha.txt"); /* TODO: make constant */

    if (!data.good())
    {
        std::cout << "File cannot be opened.\n";
        return "";
    }

    while (j <= index && data.good())
    {
        data >> val;
        j++;
    }
    if (data.good())
    {
        return val;
    }
    else
    {
        return "";
    }
}

std::string gameReset()
{
    components = 10;
    char currentGuess = ' ';
    totalGuesses = 0;
    correctGuesses = 0;
    std::fill(allGuesses, allGuesses + 26, ' ');
    std::fill(lettersGuessed, lettersGuessed + 26, 0);

    return getWord();
}

std::string getWord()
{
    char input = ' ';
    std::string hangmanword;

    while (input != 'y' && input != 'n')
    {
        std::cout << "Play against randomly generated word? (y/n): ";
        std::cin >> input;
        std::cout << "\n";
    }

    /* randomly generated word */
    if (input == 'y')
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> distW(1, 370103);

        hangmanword = findInFile(distW(rng));

        if (hangmanword == "")
        {
            std::cout << "File error! Whoopsie.\n";
            return "";
        }
    }
    /* manually entering a word */
    else
    {
        std::cout << "Please enter a word (max 26 letters): ";
        char l;
        while (l = _getch())
        {
            /* checking for user to hit enter (ASCII value 13) */
            if (l == 13)
            {
                break;
            }

            /* checking for backspace */
            if (l == 8)
            {
                std::cout << "\nCannot undo! Please retype the full word: ";
                hangmanword = "";
                continue;
            }

            /* ensuring user has entered a lower case letter */
            if (l >= 97 && l <= 122)
            {
                hangmanword = hangmanword + l;
                std::cout << "*";
            }

        }
        std::cout << "\n";
    }

    return hangmanword;
}

/* puts all of the structs from hangmanheader.h into a list hangmanArt 
 * done in order to reduce the length of printHangman()
 */
void hangmanheader_init()
{
    hangmanArt.push_back(hangman_ten);
    hangmanArt.push_back(hangman_nine);
    hangmanArt.push_back(hangman_eight);
    hangmanArt.push_back(hangman_seven);
    hangmanArt.push_back(hangman_six);
    hangmanArt.push_back(hangman_five);
    hangmanArt.push_back(hangman_four);
    hangmanArt.push_back(hangman_three);
    hangmanArt.push_back(hangman_two);
    hangmanArt.push_back(hangman_one);
}