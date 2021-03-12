//////////////////////////////////////////
// Class definitions for card, deck, hand, and player

#ifndef DECK_OF_CARDS
#define DECK_OF_CARDS

#include <iostream>
#include "string.hpp"
#include "stack.hpp"


// Class definition of card
class card {
public:

	card() : suit("0"), face('0'), value(0) {};
	card(const String&, const char&);

	card& operator=(card);

	bool operator==(const card&);
	friend std::ostream& operator<<(std::ostream&, const card&);

	// Member vars
	String suit;
	char face;
	int value;
};

// Class definition of deck

const int DECK_SIZE = 52;

class deck {
public:

	deck();

	friend std::ostream& operator<<(std::ostream&, deck&);

	stack<card> cards;

private:
	card cardArray[DECK_SIZE];
};

#endif
