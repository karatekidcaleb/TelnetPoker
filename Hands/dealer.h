#pragma once

struct Player {
    //std::string name;
    int table_pos;
    int stack;
    char* hand; //current hand dealt
};

void shuffle(char** deck)
{
    char temp[2];
    for (int j = 0; j < 52; j++)
        for (int k = 0; k < 4; k++)
        {
            temp[0] = deck[j][0];
            temp[1] = deck[j][1];
            int replacement = (int)rand() % 52;
            deck[j][0] = deck[replacement][0]; //shuffle one card ata time into random new position
            deck[j][1] = deck[replacement][1];
            deck[replacement][0] = temp[0];
            deck[replacement][1] = temp[1];
        }

}

char** populateDeck()
{
    char** deck = new char*[52]; //buffer of card id information in groups of hole cards (100 hole card combos)
    char suit;
    char value;
    for (int i = 0; i < 52; i++)
    {
        deck[i] = new char[2];
        switch (i / 13) {
        case(0):
            suit = 's';
            break;
        case(1):
            suit = 'c';
            break;
        case(2):
            suit = 'h';
            break;
        case(3):
            suit = 'd';
            break;
        };
        if (i % 13 > 9)
        {

        }
        value = (i % 13) + 2;
        switch (value) {
        case(10):
            value = 'T';
            break;
        case(11):
            value = 'J';
            break;
        case(12):
            value = 'Q';
            break;
        case(13):
            value = 'K';
            break;
        case(14):
            value = 'A';
            break;
        default:
            value += 48;
            break;
        };
        deck[i][0] = value;
        deck[i][1] = suit;
    }

    return deck;
}

/**
class play
{
	void Deal(char ** deck, Player *)
	{

	}
};

**/

