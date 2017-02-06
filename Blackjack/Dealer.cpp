#include "Dealer.h"

Dealer::Dealer() //create deck
{
    deck = new PlayingCardDeck;
}

Dealer::Dealer(int numshuffle) //creates deck and shuffles it
{
    deck = new PlayingCardDeck(numshuffle);
}

Dealer::~Dealer() //delete deck
{
    delete deck;
    deck = NULL;
}

std::string Dealer::showHand() //first card is shown as XX to indicate a face down card
{
    std::string handCode = hand->getAllCardCodes();
    handCode[0] = 'X';
    handCode[1] = 'X';
    return handCode;
}

std::string Dealer::fullHand() //shows dealer's full hand after player is done taking cards
{
    return hand->getAllCardCodes();
}

PlayingCard* Dealer::dealCard() //return next card from deck
{
    return deck->dealCard();
}

int Dealer::cardsLeft() //return how many cards are left
{
    return deck->getCountRemain();
}

void Dealer::shuffle() //resets and shuffles deck
{
    deck->reset();
    deck->shuffle(2);
}
