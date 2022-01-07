/* 
 * Header file for hangman game. Contains all of the ASCII visual elements. 
 */

#include <list>

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
