#include "deck.hpp"
#include <cstdlib>
/////////////////////////////
// CARD DEFS ////////////////
/////////////////////////////

// Constructor for card
card::card(const String& suitin, const char& facein) {
	suit = suitin;
	face = facein;
	switch (face) {
	case 'A': value = 14; break;
	case 'K': value = 13; break;
	case 'Q': value = 12; break;
	case 'J': value = 11; break;
	case '0': value = 10; break;
	case '9': value = 9; break;
	case '8': value = 8; break;
	case '7': value = 7; break;
	case '6': value = 6; break;
	case '5': value = 5; break;
	case '4': value = 4; break;
	case '3': value = 3; break;
	case '2': value = 2; break;
	default:  value = 0; break;
	}
}

// Assignment operator overload
card& card::operator=(card lhs) {
	this->suit = lhs.suit;
	this->face = lhs.face;
	this->value = lhs.value;

	return *this;
}

// Equals operator overload
bool card::operator==(const card& lhs) {
	if ((suit == lhs.suit) && (face == lhs.face)) return true;
	else return false;
}

// Output operator overload
std::ostream& operator<<(std::ostream& out, const card& lhs) {
	if (lhs.face != '0') {
		out << lhs.face << " of " << lhs.suit;
	}
	else {
		out << '1' << lhs.face << " of " << lhs.suit;
	}
	return out;
}

/////////////////////////////
// DECK DEFS ////////////////
/////////////////////////////

// Constructor for deck
deck::deck() {

	int randSuit;
	int randFace;

	String decidedSuit;
	char decidedFace;

	card addCard;

	for (int i = 0; i < DECK_SIZE; i++) {
		bool inDeck = true;
		while (inDeck) {
			randSuit = rand() % 4;
			randFace = rand() % 13;
			// Determine the suit
			switch (randSuit) {
			case 0: decidedSuit = "Hearts"; break;
			case 1: decidedSuit = "Diamonds"; break;
			case 2: decidedSuit = "Spades"; break;
			case 3: decidedSuit = "Clubs"; break;
			}

			// Determine the face
			switch (randFace) {
			case 0: decidedFace = '2'; break;
			case 1: decidedFace = '3'; break;
			case 2: decidedFace = '4'; break;
			case 3: decidedFace = '5'; break;
			case 4: decidedFace = '6'; break;
			case 5: decidedFace = '7'; break;
			case 6: decidedFace = '8'; break;
			case 7: decidedFace = '9'; break;
			case 8: decidedFace = '0'; break;
			case 9: decidedFace = 'J'; break;
			case 10: decidedFace = 'Q'; break;
			case 11: decidedFace = 'K'; break;
			case 12: decidedFace = 'A'; break;
			}

			addCard = card(decidedSuit, decidedFace);
			for (int j = 0; j < DECK_SIZE; j++) {
				if (addCard == cardArray[j]) break;
				else if (!(addCard == cardArray[j]) && (j == (DECK_SIZE - 1))) inDeck = false;
			}
		}
		cardArray[i] = addCard;
		cards.push(addCard);
	}
}

// Output operator for deck
std::ostream& operator<<(std::ostream& out, deck& deck) {
	for (int i = 0; i < DECK_SIZE; i++) out << deck.cardArray[i] << std::endl;
	return out;
}