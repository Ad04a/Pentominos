#include "../Public/Figure.h"

Figure::Figure(vector<vector<Coordinate>> posiblePlacements, char symbol)
{
    this->posiblePlacements = posiblePlacements;
    this->symbol = symbol;
}
