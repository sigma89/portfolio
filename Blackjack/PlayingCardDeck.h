#ifndef PLAYINGCARDDECK_H
#define PLAYINGCARDDECK_H

#include "PlayingCard.h"

class PlayingCardDeck
{
    public:
        PlayingCardDeck();
        PlayingCardDeck(int numShuffles);
        ~PlayingCardDeck();
        PlayingCard* dealCard();
        bool shuffle(int numShuffles);
        void reset();
        std::string getAllCardCodes();
        int getCountUsed();
        int getCountRemain();

    private:
        PlayingCard **deck;
        int cardsDealt;
        void makeDeck();
        void deleteDeck();
};

#endif // PLAYINGCARDDECK_H
