#include "deck.hpp"

int main() {

	String name;

	std::cout << "Welcome to command-line poker! (Enter 0 at any time to exit)" << std::endl;
	std::cout << "Please enter your name: ";
	std::cin >> name;

	player human(name);
	bot Bot(.7,1,1,"Alfred");
	Bot.money = 1000;
	table theTable;
	String decision;

	//While loop goes here
	while (human.money != 0 && Bot.money != 0) {

		human.folded = false;
		Bot.folded = false;

		bool running = true;
		while (running) {
			human.resetHand();
			Bot.resetHand();
			deck theDeck;
			human.draw(theDeck);
			Bot.draw(theDeck);
			human.draw(theDeck);
			Bot.draw(theDeck);
			human.draw(theDeck);
			Bot.draw(theDeck);

			std::cout << "You currently have $" << human.money << "." << std::endl;
			std::cout << "Your current hand: " << std::endl;
			std::cout << human << std::endl;

			std::cout << "What would you like to do (bet or fold)? ";
			std::cin >> decision;

			bool decisionMaking = true;
			while (decisionMaking) {
				if (decision == "0") return 1;
				if (decision == "bet" || decision == "Bet") {
					int amount = 0;
					std::cout << "How much would you like to bet? ";
					std::cin >> amount;
					theTable.bet(human, amount);
					human.onTheLine = human.onTheLine + amount;
				}
				else if (decision == "fold" || decision == "Fold") {
					std::cout << "You have folded for this round" << std::endl;
					human.fold();
					break;
				}
				Bot.makeDecision(theTable);
				if (Bot.lastDecision == "call" || Bot.lastDecision == "fold") break;
				std::cout << "What would you like to do (bet, call, or fold)? ";
				std::cin >> decision;
			}

			system("CLS");
			if (Bot.lastDecision == "call" || Bot.lastDecision == "fold") std::cout << Bot.id << " " << Bot.lastDecision << "ed." << std::endl;
			if (human.folded) break;
			if (Bot.folded) break;

			std::cout << "The current pot is: $" << theTable.pot << std::endl;
			human.draw(theDeck);
			Bot.draw(theDeck);

			std::cout << "You currently have $" << human.money << "." << std::endl;
			std::cout << "Your current hand: " << std::endl;
			std::cout << human << std::endl;

			decisionMaking = true;
			while (decisionMaking) {

				std::cout << "What would you like to do (bet, call, or fold)? ";
				std::cin >> decision;
				if (decision == "0") return 1;

				if (decision == "bet" || decision == "Bet") {
					int amount = 0;
					std::cout << "How much would you like to bet? ";
					std::cin >> amount;
					theTable.bet(human, amount);
					human.onTheLine = human.onTheLine + amount;
				}
				else if (decision == "call" || decision == "Call") {
					std::cout << "You called" << std::endl;
					theTable.call(human);
					human.onTheLine = human.onTheLine + theTable.lastBet;
					break;
				}
				else if (decision == "fold" || decision == "Fold") {
					std::cout << "You have folded for this round" << std::endl;
					human.fold();
					break;
				}
				Bot.makeDecision(theTable);
				if (Bot.lastDecision == "call" || Bot.lastDecision == "fold") break;
			}

			system("CLS");
			if (Bot.lastDecision == "call" || Bot.lastDecision == "fold") std::cout << Bot.id << " " << Bot.lastDecision << "ed." << std::endl;
			if (human.folded) break;
			if (Bot.folded) break;

			std::cout << "The current pot is: $" << theTable.pot << std::endl;
			human.draw(theDeck);
			Bot.draw(theDeck);

			std::cout << "You currently have $" << human.money << "." << std::endl;
			std::cout << "Your current hand: " << std::endl;
			std::cout << human << std::endl;

			decisionMaking = true;
			while (decisionMaking) {

				std::cout << "What would you like to do (bet, call, or fold)? ";
				std::cin >> decision;
				if (decision == "0") return 1;

				if (decision == "bet" || decision == "Bet") {
					int amount = 0;
					std::cout << "How much would you like to bet? ";
					std::cin >> amount;
					theTable.bet(human, amount);
					human.onTheLine = human.onTheLine + amount;
				}
				else if (decision == "call" || decision == "Call") {
					std::cout << "You called" << std::endl;
					theTable.call(human);
					human.onTheLine = human.onTheLine + theTable.lastBet;
					break;
				}
				else if (decision == "fold" || decision == "Fold") {
					std::cout << "You have folded for this round" << std::endl;
					human.fold();
					break;
				}
				Bot.makeDecision(theTable);
				if (Bot.lastDecision == "call" || Bot.lastDecision == "fold") break;
			}
			break;
		}

		system("CLS");
		if (Bot.lastDecision == "call" || Bot.lastDecision == "fold") std::cout << Bot.id << " " << Bot.lastDecision << "ed." << std::endl;
		player winner = determineWinner(human, Bot);

		if (winner.id != "TIE") {
			std::cout << winner.id << " won the pot of $" << theTable.pot << " with a " << winner.handRank << "." << std::endl;
			if (winner.id == human.id) {
				theTable.awardWinnings(human);
			}
			else if (winner.id == Bot.id) {
				theTable.awardWinnings(Bot);
			}
		}
		else {
			std::cout << "It was a tie, bets return to the players." << std::endl;
			human.money = human.money + human.onTheLine;
			Bot.money = Bot.money + Bot.onTheLine;
		}

		std::cout << "Your current hand: " << std::endl;
		std::cout << human << std::endl;

		std::cout << "Their current hand: " << std::endl;
		std::cout << Bot << std::endl << std::endl;

		system("pause");
		system("CLS");
	}
}