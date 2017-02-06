#ifndef DEALER_H
#define DEALER_H
#include "Player.h"
#include "PlayingCardDeck.h"


class Dealer : public Player
{
    public:
        Dealer(); //create deck
        Dealer(int numshuffle); //creates deck and shuffles it
        ~Dealer(); //delete deck
        std::string showHand(); //first card is shown as XX to indicate a face down card
        std::string fullHand(); //shows dealer's full hand after player is done taking cards
        PlayingCard* dealCard(); //return next card from deck
        int cardsLeft(); //return how many cards are left
        void shuffle(); //resets and shuffles deck

    protected:
    private:
        PlayingCardDeck *deck;
};

#endif // DEALER_H
