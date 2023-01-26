#pragma once
#include "color.h"
#include <sstream>

int Menu()
{
	int screen; //0 = main menu, 1 = game, 2 = settings
	return 0;

}

void printCard(char ** deck, int id) {
    std::string suitColor = "blue";
    std::stringstream card;

    card.str(std::string());
    if (deck[id][1] == 's' || deck[id][1] == 'c')
        suitColor = "grey";
    else
        suitColor = "red";
    card << "[" << deck[id][0] << deck[id][1] << "]";
    color(suitColor, card.str(), true);
}