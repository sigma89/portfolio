#ifndef BLACKJACKHAND_H
#define BLACKJACKHAND_H


#include "PlayingCard.h"


class BlackJackHand
{
    public:
        BlackJackHand();
        BlackJackHand(PlayingCard *c1, PlayingCard *c2);
        bool addCard(PlayingCard *card);
        int getCardCount();
        int getHighScore();
        int getLowScore();
        void clearHand();
        bool isBust();
        bool isFull();
        bool canTakeCard();
        std::string getAllCardCodes();

    private:
        PlayingCard *hand[5];
        int cardCount;
        int getScore(bool acesHigh);
};

#endif // BLACKJACKHAND_H
