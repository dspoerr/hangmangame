/* 
 * Header file for hangman game. Contains all of the ASCII visual elements. 
 */

#include <list>

/* Functions */
void validateGuess(char, std::string);
void printLetters(std::string);
void printHangman(int);
void printGuesses(void);
void hangmanheader_init(void);
std::string gameReset(void);
std::string getWord(void);
std::string findInFile(int index);

/* Globals */
char prevGuesses[26];
int totalGuesses, correctGuesses;
int components;
int difficulty;
bool posOfCorrectGuesses[26];
float score;


struct hangmanASCII
{
	std::string hangman[8];
	void print() 
	{
		for (auto& line : hangman)
		{
			std::cout << line;
		}
	};
};


hangmanASCII hangman_one =
{
	"          \n",
	"          \n",
	"          \n",
	"          \n",
	"          \n",
	"          \n",
	"==========\n",
	"  |    |  \n"
};

hangmanASCII hangman_two =
{
	"       ++ \n",
	"       || \n",
	"       || \n",
	"       || \n",
	"       || \n",
	"       || \n",
	"==========\n",
	"  |    |  \n"
};

hangmanASCII hangman_three =
{
	"  -----++ \n",
	"       || \n",
	"       || \n",
	"       || \n",
	"       || \n",
	"       || \n",
	"==========\n",
	"  |    |  \n"
};

hangmanASCII hangman_four =
{
	"   +---++ \n",
	"   |   || \n",
	"       || \n",
	"       || \n",
	"       || \n",
	"       || \n",
	"==========\n",
	"  |    |  \n"
};

hangmanASCII hangman_five =
{
	"   +---++ \n",
	"   |   || \n",
	"   O   || \n",
	"       || \n",
	"       || \n",
	"       || \n",
	"==========\n",
	"  |    |  \n"
};

hangmanASCII hangman_six =
{
	"   +---++ \n",
	"   |   || \n",
	"   O   || \n",
	"   |   || \n",
	"       || \n",
	"       || \n",
	"==========\n",
	"  |    |  \n"
};

hangmanASCII hangman_seven =
{
	"   +---++ \n",
	"   |   || \n",
	"   O   || \n",
	"  /|   || \n",
	"       || \n",
	"       || \n",
	"==========\n",
	"  |    |  \n"
};

hangmanASCII hangman_eight =
{
	"   +---++ \n",
	"   |   || \n",
	"   O   || \n",
	"  /|\\  || \n",
	"       || \n",
	"       || \n",
	"==========\n",
	"  |    |  \n"
};

hangmanASCII hangman_nine =
{
	"   +---++ \n",
	"   |   || \n",
	"   O   || \n",
	"  /|\\  || \n",
	"  /    || \n",
	"       || \n",
	"==========\n",
	"  |    |  \n"
};

hangmanASCII hangman_ten =
{
	"   +---++ \n",
	"   |   || \n",
	"   O   || \n",
	"  /|\\  || \n",
	"  / \\  || \n",
	"       || \n",
	"==========\n",
	"  |    |  \n"
};

std::list<hangmanASCII> hangmanArt;

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
