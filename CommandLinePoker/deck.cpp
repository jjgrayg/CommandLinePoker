#include "deck.hpp"
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <vector>
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
		srand(time(NULL));

		//Define a set seed
		//srand(2);

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
	money = 0;
	folded = false;
	for (int i = 0; i < HAND_SIZE; i++) {
		hand[i] = card();
	}
}

// ID constructor for player
player::player(String s) : player() {
	id = s;
	money = 1000;
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

	bool twoPair = false;
	bool onePair = false;
	bool ofAKind3 = false;
	bool ofAKind4 = false;
	bool straight = false;
	bool flush = false;
	bool royal = false;

	// Sort from lowest to highest
	std::vector<int> sortedValues;
	for (int i = 0; i < HAND_SIZE; i++) sortedValues.push_back(hand[i].value);
	std::sort(sortedValues.begin(), sortedValues.begin() + 5);

	// Check for a straight
	int straightCount = 0;
	for (int i = 0; i < HAND_SIZE - 1; i++) {
		if (sortedValues[i] == sortedValues[i + 1] - 1) {
			straightCount++;
		}
	}
	if (straightCount == 4) straight = true;

	// Check for a royal
	if (sortedValues[0] == 10 && straight) royal = true;

	// Check for flush
	int suitCount = 0;
	for (int i = 0; i < HAND_SIZE - 1; i++) {
		if (hand[i].suit == hand[i + 1].suit) suitCount += 1;
	}
	if (suitCount == 4) flush = true;

	// Check for "-of-a-kind" hand
	int faceMatches[HAND_SIZE];
	for (int i = 0; i < HAND_SIZE; i++) faceMatches[i] = 0;
	for (int i = 0; i < HAND_SIZE; i++) {
		for (int j = i; j < HAND_SIZE; j++) {
			if (hand[i].face == hand[j].face) {
				faceMatches[i] = faceMatches[i] + 1;
			}
		}
	}

	// Check for full house
	for (int i = 0; i < HAND_SIZE; i++) {
		if (faceMatches[i] == 3) ofAKind3 = true;
	}

	// Count the number of pairs
	int pairCount = 0;
	for (int i = 0; i < HAND_SIZE; i++) {
		if (faceMatches[i] == 2) pairCount++;
	}

	maxInfo maxInfo = max(faceMatches, HAND_SIZE);
	assignHighest();

	if (pairCount == 2) twoPair = true;
	else if (maxInfo.maxVal == 2) onePair = true;
	else if (maxInfo.maxVal == 3) ofAKind3 = true;
	else if (maxInfo.maxVal == 4) ofAKind4 = true;

	if (straight && flush && royal) { score = (36608398 * highVal); handRank = "Royal Flush"; }
	else if (straight && flush) { score = (5229771 * highVal); handRank = "Straight Flush"; }
	else if (ofAKind4) { score = (747111 * hand[maxInfo.maxIndex].value); handRank = "4 of a Kind"; }
	else if (twoPair && ofAKind3) { score = (106730 * highVal); handRank = "Full House"; }
	else if (flush) { score = (15247 * highVal); handRank = "Flush"; }
	else if (straight) { score = (2178 * highVal); handRank = "Straight"; }
	else if (ofAKind3) { score = (311 * hand[maxInfo.maxIndex].value); handRank = "3 of a Kind"; }
	else if (twoPair) {
		int temp = 0;
		for (int i = 0; i < HAND_SIZE; i++) {
			if (faceMatches[i] == 2) temp += hand[i].value;
		}
		score = (23 * temp); 
		handRank = "Two Pair";
	}
	else if (onePair) { score = (8 * hand[maxInfo.maxIndex].value); handRank = "One Pair"; }
	else {
		score = highVal;
		handRank = "High Card";
	}
}

// Fold member function
void player::fold() {
	folded = true;
}

// Resets the hand of the player
void player::resetHand() {
	for (int i = 0; i < HAND_SIZE; i++) {
		hand[i] = card();
	}
	currentIndex = 0;
}

// Assignment operator overload for player
player& player::operator=(player lhs) {
	this->id = lhs.id;
	this->score = lhs.score;
	this->highVal = lhs.highVal;
	this->highestCardIndex = lhs.highestCardIndex;
	this->handRank = lhs.handRank;
	this->currentIndex = lhs.currentIndex;
	for (int i = 0; i < HAND_SIZE; i++) this->hand[i] = lhs.hand[i];
	return *this;
}

// Prints the current hand held by the player
std::ostream& operator<<(std::ostream& out, player player) {
	for (int i = 0; i <= player.currentIndex; i++) {
		out << player.hand[i] << std::endl;
	}
	return out;
}
/////////////////////////////
// TABLE DEFS ///////////////
/////////////////////////////

// Lets the argued player place a bet into the pot
void table::bet(player& lhs, int amount) {
	if (amount >= lastBet) {
		if (lhs.money >= amount) {
			lhs.money = lhs.money - amount;
			pot = pot + amount;
			lastBet = amount;
		}
		else {
			pot = pot + lhs.money;
			lastBet = lhs.money;
			lhs.money = 0;
		}
	}
	else {
		call(lhs);
	}
}

// Lets the player call on the previous bet
void table::call(player& lhs) {
	bet(lhs, lastBet);
}

// Award the winnings to the winner
void table::awardWinnings(player& lhs) {
	lhs.money = lhs.money + pot;
	pot = 0;
	lastBet = 0;
}
/////////////////////////////
// BOT DEFS /////////////////
/////////////////////////////
bot::bot(int inWeightAmountBet, int inWeightCurrentScore, int inWeightAmountRemainingCash, String ID) {
	wAmountBet = inWeightAmountBet;
	wCurrentScore = inWeightCurrentScore;
	wAmountRemainingCash = inWeightAmountRemainingCash;
	id = ID;
}

// Utilizes the weights and gives the bot's decision
//String bot::makeDecision(table Table) {
//	evaluate();
//}

/////////////////////////////
// FREE FUNCS ///////////////
/////////////////////////////

// Get the max of an int array and its location
maxInfo max(int x[], int size) {
	int max = 0;
	int temp = 0;
	int maxIndex = 0;
	maxInfo result;
	for (int i = 0; i < size; i++) {
		temp = x[i];
		if (temp > max) {
			max = temp;
			maxIndex = i;
		}
	}

	result.maxIndex = maxIndex;
	result.maxVal = max;
	return result;
}

/////////////////////////////
// DETERMINE WINNER /////////
/////////////////////////////

// 2-Player version
player determineWinner(player player1, player player2) {
	player1.evaluate();
	player2.evaluate();
	if (player1.score > player2.score) return player1;
	else if (player2.score > player1.score) return player2;
	else {
		player tie("TIE");
		return tie;
	}
}

// 3-Player version
player determineWinner(player player1, player player2, player player3) {
	player1.evaluate();
	player2.evaluate();
	player3.evaluate();

	player max;
	if (player1.score > player2.score) max = player1;
	else max = player2;

	if (player2.score > player3.score) max = player2;
	else max = player3;

	return max;
}