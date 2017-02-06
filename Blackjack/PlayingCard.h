#ifndef playingcard_h
#define playingcard_h

#include <string>

class PlayingCard {

    private:
        char suit;
        char value;
        bool isGood(char value, char suit);
    public:
        PlayingCard(char value = '0', char suit = '0');
        bool setCard (char value, char suit);
        char getValue();
        char getSuit();
        std::string getCardCode();
        bool isValid();
};

#endif // playingcard_h
