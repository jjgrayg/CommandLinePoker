//////////////////////////////////////////
// Class definitions for card, deck, hand, and player

#ifndef DECK_OF_CARDS
#define DECK_OF_CARDS

#include <iostream>
#include "string.hpp"
#include "stack.hpp"

class card {
public:

	card() : suit("0"), color("0"), value(0) {};
	card(String suit, String color);

	bool operator==(const card);
	friend std::ostream& operator<<(std::ostream&, const card&);

	// Member vars
	String suit;
	String color;
	int value;
};

#endif
