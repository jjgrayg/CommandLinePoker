//#include "deck.hpp"
//
//int main() {
//	card qOfClubs("Clubs", 'Q');
//	card qOfHearts("Hearts", 'Q');
//	deck testDeck;
//	std::cout << "Printing deck: " << testDeck << std::endl;
//	player testPlayer("Jarod");
//	std::cout << testPlayer.id << "'s Inital hand: " << testPlayer << std::endl;
//	testPlayer.draw(testDeck);
//	testPlayer.draw(testDeck);
//	testPlayer.draw(testDeck);
//	std::cout << testPlayer.id << "'s Three card hand: " << testPlayer << std::endl;
//	testPlayer.draw(testDeck);
//	testPlayer.draw(testDeck);
//	std::cout << testPlayer.id << "'s full hand: " << std::endl << testPlayer << std::endl;
//	testPlayer.assignHighest();
//	std::cout << "The highest value present is: " << testPlayer.highVal << ". The card is: " << testPlayer.hand[testPlayer.highestCardIndex] << std::endl;
//	testPlayer.evaluate();
//	std::cout << "The score is: " << testPlayer.score << std::endl;
//
//	//Testing if straight works
//	card card1("Spades", '0');
//	card card2("Spades", 'J');
//	card card3("Spades", 'Q');
//	card card4("Spades", 'A');
//	card card5("Spades", 'K');
//	testDeck.cards.push(card1);
//	testDeck.cards.push(card2);
//	testDeck.cards.push(card3);
//	testDeck.cards.push(card4);
//	testDeck.cards.push(card5);
//
//	player straightPlayer("HighCard");
//	straightPlayer.draw(testDeck);
//	straightPlayer.draw(testDeck);
//	straightPlayer.draw(testDeck);
//	straightPlayer.draw(testDeck);
//	straightPlayer.draw(testDeck);
//	std::cout << straightPlayer.id << "'s full hand: " << std::endl << straightPlayer << std::endl;
//
//	player player3("Literal Jesus");
//	card card6("Clubs", '0');
//	card card7("Clubs", 'J');
//	card card8("Clubs", 'Q');
//	card card9("Clubs", 'A');
//	card card10("Clubs", 'K');
//	testDeck.cards.push(card6);
//	testDeck.cards.push(card7);
//	testDeck.cards.push(card8);
//	testDeck.cards.push(card9);
//	testDeck.cards.push(card10);
//	player3.draw(testDeck);
//	player3.draw(testDeck);
//	player3.draw(testDeck);
//	player3.draw(testDeck);
//	player3.draw(testDeck);
//	std::cout << player3.id << "'s full hand: " << std::endl << player3 << std::endl;
//
//	std::cout << "The score is: " << straightPlayer.score << " With a " << straightPlayer.handRank << std::endl << std::endl;
//
//	std::cout << "And the winner is " << determineWinner(straightPlayer, player3).id << " with a " << determineWinner(straightPlayer, player3).handRank << "!" << std::endl;
//
//
//	std::cout << "And the winner is " << determineWinner(straightPlayer, testPlayer, player3).id << " with a " << determineWinner(straightPlayer, testPlayer, player3).handRank << "!";
//
//}