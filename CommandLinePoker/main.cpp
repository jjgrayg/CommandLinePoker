#include "deck.hpp"

int main() {

	String name;

	std::cout << "Welcome to command-line poker! (Enter 0 at any time to exit)" << std::endl;
	std::cout << "Please enter your name: ";
	std::cin >> name;

	player human(name);
	player bot("Alfred");
	table theTable;
	String decision;

	//While loop goes here
	while (human.money != 0) {
		human.resetHand();
		bot.resetHand();
		deck theDeck;
		human.draw(theDeck);
		bot.draw(theDeck);
		human.draw(theDeck);
		bot.draw(theDeck);
		human.draw(theDeck);
		bot.draw(theDeck);

		std::cout << "You currently have $" << human.money << "." << std::endl;
		std::cout << "Your current hand: " << std::endl;
		std::cout << human << std::endl;

		std::cout << "What would you like to do (bet or fold)? ";
		std::cin >> decision;

		if (decision == "bet" || decision == "Bet") {
			int amount = 0;
			std::cout << "How much would you like to bet? ";
			std::cin >> amount;
			theTable.bet(human, amount);
		}
		else if (decision == "fold" || decision == "Fold") {
			std::cout << "You have folded for this round";
			human.fold();
		}

		theTable.call(bot);

		std::cout << "The current pot is: $" << theTable.pot << std::endl;
		human.draw(theDeck);
		bot.draw(theDeck);

		std::cout << "You currently have $" << human.money << "." << std::endl;
		std::cout << "Your current hand: " << std::endl;
		std::cout << human << std::endl;

		std::cout << "What would you like to do (bet, call, or fold)? ";
		std::cin >> decision;

		if (decision == "bet" || decision == "Bet") {
			int amount = 0;
			std::cout << "How much would you like to bet? ";
			std::cin >> amount;
			theTable.bet(human, amount);
		}
		else if (decision == "call" || decision == "Call") {
			std::cout << "You called" << std::endl;
			theTable.call(human);
		}
		else if (decision == "fold" || decision == "Fold") {
			std::cout << "You have folded for this round";
			human.fold();
		}

		theTable.call(bot);

		std::cout << "The current pot is: $" << theTable.pot << std::endl;
		human.draw(theDeck);
		bot.draw(theDeck);

		std::cout << "You currently have $" << human.money << "." << std::endl;
		std::cout << "Your current hand: " << std::endl;
		std::cout << human << std::endl;

		std::cout << "What would you like to do (bet, call, or fold)? ";
		std::cin >> decision;

		if (decision == "bet" || decision == "Bet") {
			int amount = 0;
			std::cout << "How much would you like to bet? ";
			std::cin >> amount;
			theTable.bet(human, amount);
		}
		else if (decision == "call" || decision == "Call") {
			std::cout << "You called" << std::endl;
			theTable.call(human);
		}
		else if (decision == "fold" || decision == "Fold") {
			std::cout << "You have folded for this round";
			human.fold();
		}

		player winner = determineWinner(human, bot);

		std::cout << winner.id << " won the pot of $" << theTable.pot << " with a " << winner.handRank << "." << std::endl;
		if (winner.id == human.id) {
			theTable.awardWinnings(human);
		}
		else if (winner.id == bot.id) {
			theTable.awardWinnings(bot);
		}

		std::cout << "Your current hand: " << std::endl;
		std::cout << human << std::endl;

		std::cout << "Their current hand: " << std::endl;
		std::cout << bot << std::endl << std::endl;
	}
}