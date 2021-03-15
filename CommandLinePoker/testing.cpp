#include "deck.hpp"

int main() {
	card qOfClubs("Clubs", 'Q');
	card qOfHearts("Hearts", 'Q');
	deck testDeck;
	std::cout << "Printing deck: " << testDeck << std::endl;
	player testPlayer("Jarod");
	std::cout << testPlayer.id << "'s Inital hand: " << testPlayer << std::endl;
	testPlayer.draw(testDeck);
	testPlayer.draw(testDeck);
	testPlayer.draw(testDeck);
	std::cout << testPlayer.id << "'s Three card hand: " << testPlayer << std::endl;
	testPlayer.draw(testDeck);
	testPlayer.draw(testDeck);
	std::cout << testPlayer.id << "'s full hand: " << std::endl << testPlayer << std::endl;
	testPlayer.assignHighest();
	std::cout << "The highest value present is: " << testPlayer.highVal << ". The card is: " << testPlayer.hand[testPlayer.highestCardIndex] << std::endl;
	testPlayer.evaluate();
	std::cout << "The score is: " << testPlayer.score << std::endl;

	//Testing if straight works
	card card1("Clubs", '0');
	card card2("Hearts", 'J');
	card card3("Diamonds", '9');
	card card4("Spades", 'A');
	card card5("Clubs", '8');
	testDeck.cards.push(card1);
	testDeck.cards.push(card2);
	testDeck.cards.push(card3);
	testDeck.cards.push(card4);
	testDeck.cards.push(card5);

	player straightPlayer("GOD");
	straightPlayer.draw(testDeck);
	straightPlayer.draw(testDeck);
	straightPlayer.draw(testDeck);
	straightPlayer.draw(testDeck);
	straightPlayer.draw(testDeck);
	std::cout << straightPlayer.id << "'s full hand: " << std::endl << straightPlayer << std::endl;
	straightPlayer.evaluate();
	std::cout << "The score is: " << straightPlayer.score << " With a " << straightPlayer.handRank;
}