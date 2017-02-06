#include "Player.h"

Player::Player() // creates new hand, set stake to 0
{
    hand = new BlackJackHand;
    stake = 0;
}

Player::Player(int newStake) //overloaded constructor, takes argument to set stake
{
    hand = new BlackJackHand;
    stake = newStake;
}

Player::~Player() //destructor deletes hand
{
    delete hand;
    hand = NULL;
}

bool Player::takeCard(PlayingCard *c) //add card to hand
{
    if (hand->canTakeCard())
    {
        hand->addCard(c);
        return true;
    }

    else
        return false;
}

std::string Player::showHand() //returns contents of player hand
{
    return hand->getAllCardCodes();
}

int Player::getLowScore() //return low score
{
    return hand->getLowScore();
}

int Player::getHighScore() //returns high score
{
    return hand->getHighScore();
}

int Player::getScore() //return high score if under 21, else returns low score
{
    if (hand->getHighScore() <= 21)
        return hand->getHighScore();

    else
        return hand->getLowScore();
}

bool Player::busted() //returns true if player busts(lowscore over 21)
{
    return hand->isBust();
}

bool Player::wantCard() //return true if player wants a card(score<16)
{
    if (hand->getHighScore() < 16)
        return true;

    else
        return false;
}

void Player::clearHand() //clear cards from hand
{
    hand->clearHand();
}

void Player::setStake(int newStake) //setter for stake
{
    stake = newStake;
}

int Player::getStake() //returns current stake
{
    return stake;
}

bool Player::makeBet(int newBet) //sets bet if less than stake and return true, otherwise false and does nothing
{
    if (newBet <= stake)
    {
        bet = newBet;
        return true;
    }

    else
        return false;
}

void Player::won() //add bet to stake
{
    stake += bet;
}

void Player::lost() //subtract bet from stake
{
    stake -= bet;
}
