#include "set.h"

//class functions
card::card(){
    color = "null";
    num = 0;
    shape = "null";
    fill = "null";
}

card::card(std::string c, int n, std::string s, std::string f) {
	color = c;
	num = n;
	shape = s;
	fill = f;
}

std::string card::getColor() {
	return color;
}

int card::getNum() {
	return num;
}

std::string card::getShape() {
	return shape;
}

std::string card::getFill() {
	return fill;
}

bool card::compare(card * a, card * b) {
    int count = 0;
    //ensures
    if (color.compare("null") == 0 || a->color.compare("null")==0||b->color.compare("null")==0){
        //std::cout << "one of these cards is null" << std::endl;
        return false;
    }
    //checks for color, gives one point if either conditions are met
	if ((color.compare(a->color) == 0) && (color.compare(b->color) == 0) &&
        (a->color.compare(b->color) == 0)) {
        //std::cout << "All colors are same" << std::endl;
        count++;
	}
    else if ((color.compare(a->color) != 0) && (color.compare(b->color) != 0) &&
        (a->color.compare(b->color) != 0)) {
        //std::cout << "All colors are different" << std::endl;
        count++;
    }
    else {
        return false;
    }
    //checks for num
    if (num == a->num && num == b->num && a->num == b->num){
        //std::cout << "All nums are the same" << std::endl;
        count++;
    }
    else if (num != a->num && num != b->num && a->num != b->num){
        //std::cout << "All nums are different" << std::endl;
        count++;
    }
    else {
        return false;
    }
    //checks for shape
    if ((shape.compare(a->shape) == 0) && (shape.compare(b->shape) == 0) &&
        (a->shape.compare(b->shape) == 0)) {
        //std::cout << "All shapes are the same " << std::endl;
        count++;
    }
    else if ((shape.compare(a->shape) != 0) && (shape.compare(b->shape) != 0) &&
        (a->shape.compare(b->shape) != 0)) {
        //std::cout << "All shapes are different " << std::endl;
        count++;
    }
    else {
        return false;
    }
    //checks for fill
    if ((fill.compare(a->fill) == 0) && (fill.compare(b->fill) == 0) &&
        (a->fill.compare(b->fill) == 0)) {
        //std::cout << "All fills are the same " << std::endl;
        count++;
    }
    else if ((fill.compare(a->fill) != 0) && (fill.compare(b->fill) != 0) &&
        (a->fill.compare(b->fill) != 0)) {
        //std::cout << "All fills are different " << std::endl;
        count++;
    }
    else {
        return false;
    }
    
    //std::cout << "It's a match!" << std::endl;
    return count == 4;
}

std::string card::toString() {

    std::string temp = "[" + color + "," + std::to_string(num) + "," + shape + "," + fill + "]";
    return temp;
}

//main/game functions

//the array that holds the deck of cards
card cardList[81];
static bool isThree = false;
static int extra = 0;

//prints the array in a grid
void printGrid(){
    for (int i = 0; i < 12; i+=3){
        std::cout << cardList[i].toString() << " \t" << cardList[i+1].toString() << " \t" << cardList[i+2].toString() << std::endl;
    }
}

//sets up initial deck
void makeDeck(){
    //set up for array with every possible card
    std::string colors[3] = {"green", " red ", "blue "};
    int nums[3] = {1,2,3};
    std::string shapes[3] = {"diamond ", "squiggle", "  oval  "};
    std::string fills[3] = {"striped", " solid ", " empty "};
    //iterates through all possible combos, adds to array
    int array = 0;
    for(int i = 0; i< 3; i++){
        for (int j = 0; j< 3; j++){
            for (int k = 0; k< 3; k++){
                for (int l = 0; l < 3; l++){
                    card temp(colors[i], nums[j], shapes[k], fills[l]);
                    cardList[array] = temp;
                    //std::cout << cardList[array].toString() << std::endl;
                    array++;
                }
            }
        }
    }
    //randomizes the deck of cards
    std::random_device rd;
    std::mt19937 r (rd());
    std::shuffle(cardList, cardList + 81, r);
}

bool checkMatch(int a, int b, int c){
    
    card aa = cardList[a];
    card bb = cardList[b];
    card cc = cardList[c];
    
    return aa.compare(&bb, &cc);
}

void updateDeck(int a, int b, int c, int &count){
    if (count >= 69){
        std::cout << "That's a match!" << std::endl;
        std::cout << "No more cards left!" << std::endl;
        card temp;
        cardList[a] = temp;
        count++;
        cardList[b] = temp;
        count++;
        cardList[c] = temp;
        count++;
    }
    else {
        std::cout << "That's a match!" << std::endl;
        //checks for potential repeats due to ading three
        if (a== 12+count || b == 12+count || c == 12+count){
            count++;
        }
        cardList[a] = cardList[12+count];
        count++;
        if (a== 12+count || b == 12+count || c == 12+count){
            count++;
        }
        cardList[b] = cardList[12+count];
        count++;
        if (a== 12+count || b == 12+count || c == 12+count){
            count++;
        }
        cardList[c] = cardList[12+count];
        count++;
    }
}

//displays three extra cards
void addThree(){
    isThree = true;
    extra += 3;
    for (int i = 0; i < (12 + extra); i+=3){
        std::cout << cardList[i].toString() << " \t" << cardList[i+1].toString() << " \t" << cardList[i+2].toString() << std::endl;
    }
}

int checkGrid(){
    int matches = 0;
    int max = 12;
    //changes count if addThree is in play
    if (isThree){
        max = 12+extra;
        
    }
    //through every card in deck, on board
    for(int i = 0; i < max; i++){
        //checks against second card
        for(int k = i; k < max; k++){
            if (i == k){
                continue;
            }
                //checks for third card
            for(int l = k; l < max; l++){
                if (i == l || k == l || l < k){
                    continue;
                }
                if (cardList[i].compare(&cardList[k], &cardList[l])){
                    matches++;
                }
            }
            
        }
    }
    return matches;
}

bool playerChoice(int &count){
    std::cout << "Select 3 choices:\n" << std::endl;
    int a;
    std::cin >> a;
    int b;
    std::cin >> b;
    int c;
    std::cin >> c;
    
    //checks for repeats
    if(a==b||b==c||a==c){
        
    }
    
    //sets limits on cards
    if (isThree){
        if (!(a<12+extra)||!(b<12+extra)||!(c<12+extra)){
            std::cout << "Invalid selection!\n" << std::endl;
            return false;
        }
    }
    else{
        if (!(a<12)||!(b<12)||!(c<12)){
            std::cout << "Invalid selection!\n" << std::endl;
            return false;
        }
    }
    
    
    //if match, replace those cards, uses count variable to get through list
    
    if (checkMatch(a,b,c)){
        updateDeck(a,b,c,count);
        return true;
    }
    else {
        std::cout << "That's not a match! Try again!\n" << std::endl;
        return false;
    }
}

void userPlay(){
    int count = 0;
    while (true) {
        printGrid();
        
        if(checkGrid() == 0){
            //if there are no cards left and no matches left, exit program
            if(count >=69){
                std::cout << "No more matches available, no more cards available" << std::endl;
                break;
            }
            std::cout << "No matches available on board, adding cards:" << std::endl;
            addThree();
        }
        
       
        //if there are extra cards in deck
        while(isThree){
            //if a choice is valid
            if(playerChoice(count)){
                //resets special values
                isThree = false;
                extra = 0;
            }
            else{
                addThree();
            }
        }
        
        playerChoice(count);
    }
}

bool autoFindMatch(int &count){
    int max = 12;
    //if isThree, changes max to 15
    if(isThree){
        max = 12 + extra;
    }
    
    //through every card in deck, on board
    for(int i = 0; i < max; i++){
        //checks against second card
        for(int k = i; k < max; k++){
            if (i == k){
                continue;
            }
            //checks for third card
            for(int l = k; l < max; l++){
                if (i == l || k == l || l < k){
                    continue;
                }
                
                if (cardList[i].compare(&cardList[k], &cardList[l])){
                    std::cout << "Match found at " << i << " " << k << " " << l << std::endl;
                    updateDeck(i,k,l, count);
                    return true;
                }
            }
            
        }
    }
    return false;
}

void solve(){
    int c = 0;
    while (true) {
        printGrid();
        
        //int cg = checkGrid();
        if(checkGrid() == 0){
            //if there are no cards left and no matches left, exit program
            if(c >=69){
                std::cout << "No more matches available, no more cards available" << std::endl;
                break;
            }
            std::cout << "No matches available on board, adding cards:" << std::endl;
            addThree();
        }
        
        //while loop for isThree
        while(isThree){
            //if a match is found
            if(autoFindMatch(c)){
                //resets special values
                isThree = false;
                extra = 0;
            }
            else{
                addThree();
            }
        }

        autoFindMatch(c);
        std::cout << "COUNT: " << c << std::endl;
    }
    std::cout << "All matches have been found" << std::endl;
}

int main() {
    makeDeck();
    //printGrid();
    userPlay();
    //solve();
}


