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
	std::cout << testPlayer.id << "'s Four card hand: " << testPlayer << std::endl;
}