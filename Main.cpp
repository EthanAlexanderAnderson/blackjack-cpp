#include <stdlib.h>
#include <iostream>

// Initialize variables
const char names[14] = { "A23456789TJQK" }; // to keep each as one char, ten = T
const int values[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

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

Card drawCard (Owner owner) {
    int draw = rand()%13;
    Card drawn;
    drawn.name = names[draw];
    drawn.value = values[draw];
    owner.hand[owner.size] = drawn;
    owner.size++;
    return drawn;
}

int main() {
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

        // Dealer
        std::cout << "Dealers card: " << drawCard(dealer).name << "\n";
        drawCard(dealer);

        // Player
        std::cout << "Your cards: ";
        std::cout << drawCard(player).name << " & ";
        std::cout << drawCard(player).name << "\n";

    }

    std::cout << "Thanks for playing!";
    return 0;
}