#include "deck.hpp"
#include <cstdlib>
#include <time.h>
/////////////////////////////
// CARD DEFS ////////////////
/////////////////////////////

// Constructor for card
card::card(const String& suitin, const char& facein) {
	isCard = true;
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
	this->isCard = lhs.isCard;
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
	if (lhs.isCard) {
		if (lhs.face != '0') {
			out << lhs.face << " of " << lhs.suit;
		}
		else {
			out << '1' << lhs.face << " of " << lhs.suit;
		}
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
		//Define random seed
		// srand(time(NULL));

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
	for (int i = (DECK_SIZE - 1); i >= 0; i--) out << deck.cardArray[i] << std::endl;
	return out;
}

/////////////////////////////
// PLAYER DEFS //////////////
/////////////////////////////

// Default constructor for player
player::player() {
	currentIndex = 0;
	id = "/0";
	highVal = 0;
	score = 0;
	highestCardIndex = 0;
	for (int i = 0; i < HAND_SIZE; i++) {
		hand[i] = card();
	}
}

// ID constructor for player
player::player(String s) : player() {
	id = s;
}

// Draw member function
void player::draw(deck& deck) {
	hand[currentIndex] = deck.cards.pop();
	currentIndex++;
	if (currentIndex > 4) currentIndex = 4;
}

// Gets the highest value card and assigns it to highVal
void player::assignHighest() {
	int temp = 0;
	for (int i = 0; i < HAND_SIZE; i++) {
		temp = hand[i].value;
		if (temp > highVal) { 
			highVal = temp; 
			highestCardIndex = i; 
		}
	}
}

// Generate a score for the player and assign to score
void player::evaluate() {

	// Check for "-of-a-kind" hands
	int faceMatches[HAND_SIZE];
	for (int i = 0; i < HAND_SIZE; i++) faceMatches[i] = 0;
	int matches = 0;
	for (int i = 0; i < HAND_SIZE; i++) {
		for (int j = 0; i < HAND_SIZE; i++) {
			if (hand[i].face == hand[j].face) {
				faceMatches[i] = faceMatches[i] + 1;
			}
		}
	}

	score = max(faceMatches, HAND_SIZE);
}

// Prints the current hand held by the player
std::ostream& operator<<(std::ostream& out, player player) {
	for (int i = 0; i <= player.currentIndex; i++) {
		out << player.hand[i] << std::endl;
	}
	return out;
}

/////////////////////////////
// FREE FUNCS ///////////////
/////////////////////////////

// Get the max of an int array
int max(int x[], int size) {
	int max = 0;
	int temp = 0;
	for (int i = 0; i < size; i++) {
		temp = x[i];
		if (temp > max) max = temp;
	}
	return max;
}