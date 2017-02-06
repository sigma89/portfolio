#include "PlayingCardDeck.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

PlayingCardDeck::PlayingCardDeck()
{
    makeDeck();
    srand(time(0));
    shuffle(5);
}

PlayingCardDeck::PlayingCardDeck(int numShuffles)
{
    makeDeck();
    srand(time(0));
    shuffle(numShuffles);
}

PlayingCardDeck::~PlayingCardDeck()
{
    deleteDeck();
}

PlayingCard* PlayingCardDeck::dealCard()
{
    if (cardsDealt < 52)
    {
        return deck[cardsDealt++];
    }
    else
    {
        std::cout << "Error: No cards left to deal" << std::endl;
        return NULL;
    }
}

bool PlayingCardDeck::shuffle(int numShuffles)
{
    int card1;
    int card2;
    if (cardsDealt != 0)
    {
        std::cout << "Error: Cards already dealt from deck" << std::endl;
        return false;
    }
    else
    {
        for (int i = 0; i < numShuffles; i++)
        {
            card1 = rand() % 52;
            while((card2 = rand() % 52) == card1);
            PlayingCard *temp = deck[card1];
            deck[card1] = deck[card2];
            deck[card2] = temp;
        }
        return true;
    }
}

void PlayingCardDeck::reset()
{
    deleteDeck();
    makeDeck();
}
std::string PlayingCardDeck::getAllCardCodes()
{
    std::string result = "";
    for (int i = cardsDealt; i < 52; i++)
    {
        result += deck[i]->getCardCode() + " ";
        if ((i+1) % 13 == 0)
        {
            result += '\n';
        }
    }
    return result;
}
int PlayingCardDeck::getCountUsed()
{
    return cardsDealt;
}

int PlayingCardDeck::getCountRemain()
{
    return 52 - cardsDealt;
}

void PlayingCardDeck::makeDeck()
{
    deck = new PlayingCard*[52];
    char *values = "A23456789TJQK";
    char *suits = "DCHS";
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            deck[i * 13 + j] = new PlayingCard(values[j], suits[i]);
        }
    }
    cardsDealt = 0;
}

void PlayingCardDeck::deleteDeck()
{
    for (int i = cardsDealt; i < 52; i++)
    {
        delete deck[i];
    }
    delete[] deck;
}
