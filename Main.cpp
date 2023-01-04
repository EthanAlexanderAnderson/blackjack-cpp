#include <stdlib.h>
#include <iostream>

class Card {
    public:
        char name;
        int value;
};

class Owner {
    public:
        int id; // 0 is dealer, 1 is player
        Card hand[11]; // 11 is maximum possible hand size
        int size = 0; // size of hand for appending reasons
        int value = 0;
};

int main() {
    // Initialize variables
    const char names[14] = { "A23456789TJQK" }; // to keep each as one char, ten = T
	const int values[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
    Owner dealer;
    dealer.id = 0;
    Owner player; 
    player.id = 1;
    int bal = 1000;
    int bet = 0;

    // Startup and welcome
    std::cout << "Hello welcome to text based blackjack.\n";
    std::cout << "Your balance is: $" << bal << "\nEnter bet (0 to quit): ";
    std::cin >> bet;

    while (bet > 0) {
        std::cout << "Your bet is: $" << bet << "\n";

        // Begin game (draw cards)
        // TODO make function for this, drawCards(dealer, 2)
        // Dealer
        for (int i = 0; i < 2; i++) {
            int draw = rand()%13;
            Card drawn;
            drawn.name = names[draw];
            drawn.value = values[draw];
            dealer.hand[dealer.size] = drawn;
            dealer.size++;
        }
        std::cout << "Dealers card: " << dealer.hand[0].name << "\n";
        // Player
        std::cout << "Your cards: ";
        for (int i = 0; i < 2; i++) {
            int draw = rand()%13;
            Card drawn;
            drawn.name = names[draw];
            drawn.value = values[draw];
            player.hand[player.size] = drawn;
            player.size++;
        }
        std::cout << player.hand[0].name << " & ";
        std::cout << player.hand[1].name << "\n";

    }

    std::cout << "Thanks for playing!";
    return 0;
}