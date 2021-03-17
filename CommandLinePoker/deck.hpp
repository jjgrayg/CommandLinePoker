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

	card() : isCard(false), suit("0"), face('0'), value(0) {};
	card(const String&, const char&);

	card& operator=(card);

	bool operator==(const card&);
	friend std::ostream& operator<<(std::ostream&, const card&);

	// Member vars
	bool isCard;
	String suit;
	char face;
	int value;
};

// Class definition of deck

const int DECK_SIZE = 52;

class deck {
public:

	deck();

	friend std::ostream& operator<<(std::ostream&, deck&); //DEBUGGING

	stack<card> cards;

private:
	card cardArray[DECK_SIZE];
};

// Class definition for player

const int HAND_SIZE = 5;

class player {
public:
	player();
	player(String);

	void draw(deck&);
	void assignHighest();
	void evaluate();
	void fold();

	void resetHand();

	player& operator=(player);
	friend std::ostream& operator<<(std::ostream&, player);

	String id;
	card hand[HAND_SIZE];

	int score;
	int highVal;
	int highestCardIndex;
	String handRank;
	int onTheLine;

	bool folded;
	int money;
	int currentIndex;

private:
};

// Class for storing information returned from the max function
class maxInfo {
public:
	int maxVal;
	int maxIndex;
};

// Class defintion for the table
class table {
public:

	table() : pot(0), lastBet(0) {};

	void bet(player&, int);
	void call(player&);
	void awardWinnings(player&);

	int pot;
	int lastBet;
};

// The AI
class bot : public player {
public:
	bot() : wAmountBet(0), wCurrentScore(0), wAmountRemainingCash(0) {};
	bot(int, int, int, String);

	void makeDecision(table&);

	String lastDecision;
	bool justBet;

private:
	// Decision making weights
	int wAmountBet;
	int wCurrentScore;
	int wAmountRemainingCash;
};

// Free function
maxInfo max(int[], int);
player determineWinner(player, player);
player determineWinner(player, player, player);
player determineWinner(player, player, player, player);
player determineWinner(player, player, player, player, player);
player determineWinner(player, player, player, player, player, player);

#endif
