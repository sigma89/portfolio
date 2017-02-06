#ifndef PLAYER_H
#define PLAYER_H
#include "BlackJackHand.h"

class Player
{
    public:
        Player(); // creates new hand, set stake to 0
        Player(int newStake); //overloaded constructor, takes argument to set stake
        ~Player(); //destructor deletes hand
        bool takeCard(PlayingCard *c); //add card to hand
        std::string showHand(); //returns contents of player hand
        int getLowScore(); //return low score
        int getHighScore(); //returns high score
        int getScore(); //return high score if under 21, else returns low score
        bool busted(); //returns true if player busts(lowscore over 21)
        bool wantCard(); //return true if player wants a card(score<16)
        void clearHand(); //clear cards from hand
        void setStake(int newStake); //setter for stake
        int getStake(); //returns current stake
        bool makeBet(int newBet); //sets bet if less than stake and return true, otherwise false and does nothing
        void won(); //add bet to stake
        void lost(); //subtract bet from stake

    protected:
        BlackJackHand *hand;

    private:
        int stake, bet;
};

#endif // PLAYER_H
