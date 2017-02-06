#include "BlackJackHand.h"

BlackJackHand::BlackJackHand()
{
    cardCount = 0;
}

BlackJackHand::BlackJackHand(PlayingCard *c1, PlayingCard *c2)
{
    hand[0] = c1;
    hand[1] = c2;
    cardCount = 2;
}

bool BlackJackHand::addCard(PlayingCard *card)
{
   if (canTakeCard())
   {
       hand[cardCount] = card;
       cardCount++;
       return true;
   }
   return false;
}

int BlackJackHand::getCardCount()
{
    return cardCount;
}

int BlackJackHand::getHighScore()
{
    return getScore(true);
}

int BlackJackHand::getLowScore()
{
    return getScore(false);
}

int BlackJackHand::getScore(bool acesHigh)
{
    int score = 0;
    for (int i = 0; i < cardCount; i++)
    {
        char val = hand[i]->getValue();
        if (val >= '2' && val <= '9')
        {
            score += val - '0';
        }
        else if (val == 'T' || val == 'J' || val == 'Q' || val == 'K')
        {
            score += 10;
        }
        else if (val == 'A')
        {
            score += (acesHigh ? 11 : 1);
        }
    }
    return score;
}

void BlackJackHand::clearHand()
{
    for (int i = 0; i < cardCount; i++)
    {
        delete hand[i];
    }
    cardCount = 0;
}

bool BlackJackHand::isBust()
{
    return (getLowScore() > 21);
}

bool BlackJackHand::isFull()
{
    return (cardCount >= 5);
}

bool BlackJackHand::canTakeCard()
{
    return (getLowScore() < 21 && !isFull());
}

std::string BlackJackHand::getAllCardCodes()
{
    std::string result = "";
    for (int i = 0; i < cardCount; i++)
    {
        result += hand[i]->getCardCode();
        result += " ";
    }
    return result;
}
