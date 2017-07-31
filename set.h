#pragma once

#include <iostream>
#include <string>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

class card {
public:
    //functions
    card();
    card(std::string color, int num, std::string shape, std::string fill);
    std::string getColor();
	int getNum();
    std::string getShape();
    std::string getFill();
	bool compare(card * a, card * b);
    std::string toString();
    
    //attributes
    std::string color;
	int num;
    std::string shape;
    std::string fill;
};