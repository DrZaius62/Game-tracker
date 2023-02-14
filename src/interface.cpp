#include "interface.hpp"

int center(int width, std::string str){
    return (width - str.length())/2;
}

// Prints centered title for a menu
void printTitle(WINDOW *win, std::string title)
{
    int height, width;
    getmaxyx(win, height, width);
    mvwprintw(win, 1, center(width, title), title.c_str());
}

// Prints a list of items in a menu format, with highlights
void printList(WINDOW *win, int highlight, std::vector<std::string> list){
    int height, width;
    getmaxyx(win, height, width);

    for (int i = 0; i < list.size(); i++){
        if (i == highlight)
            wattron(win, A_REVERSE);
        mvwprintw(win, i+2, 1, list[i].c_str());
        wattroff(win, A_REVERSE);
    }
}

// Makes a vector of the items in the xml, so it can be passed to the relevant
// functions to make a list and display it
std::vector<std::string> makeList(std::string category)
{
    pugi::xml_node group = statusNode(root, category);
    std::vector<std::string> list;

    for(auto game : group)
    {
        list.push_back(game.attribute("name").value());
    }
    return list;
}

// Constructor
Menu::Menu(int factor, int starty, int startx)
{
    // ncurses initialization
    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    win = newwin(yMax/factor, xMax/factor, starty, startx);
    keypad(win, true);
    setWin(win);

    width = xMax/factor;
    height = yMax/factor;

    setHighlight(0);
    setCategory(-1);

    printMain();
    refresh();
    wrefresh(win);
}

// Destructor
Menu::~Menu()
{
    delwin(getWin());
    endwin();
}

// Displays the main menu
void Menu::printMain()
{
    WINDOW *win = getWin();
    printTitle(win, "Main");
    std::vector<std::string> categories = {"Wishlist", "Backlog", "Playing", "Beat", 
        "Quit", "Paused", "Press 'x' to close"};
    setSizeList(categories.size());
    box(win, 0, 0);
    printList(win, getHighlight(), categories);
}

// Displays the main menu
void Menu::printCurrentScreen()
{
    int option = getCategory();
    if (option != -1)
    {
        std::string title;
        std::vector<std::string> list;
        std::string back = "----Back to main menu-----";
        enum options {Wishlist, Backlog, Playing, Beat, Quit, Paused};
        switch (option) {
            case Wishlist:
                title = "Wishlist";
                break;
            case Backlog:
                title = "Backlog";
                break;
            case Playing:
                title = "Playing";
                break;
            case Beat:
                title = "Beat";
                break;
            case Quit:
                title = "Quit";
                break;
            case Paused:
                title = "Paused";
                break;
            default:
                break;
        }

        list = makeList(title);
        list.push_back(back);
        setSizeList(list.size());
        WINDOW *win = getWin();
        printTitle(win, title);
        setSizeList(list.size());
        // change list to an actual list, so i can append "back to main menu"
        // and previous and next page
        printList(win, getHighlight(), list);
        box(win, 0, 0);
    }
    else {
        printMain();
    }
}

WINDOW *Menu::getWin(){
    return win;
}

void Menu::setWin(WINDOW *win)
{
    this->win = win;
}

int Menu::getCategory()
{
    return category;
}

void Menu::setCategory(int set)
{
    category = set;
}
int Menu::getHighlight(){
    return highlight;
}

void Menu::setHighlight(int set)
{
    this->highlight = set;
}

int Menu::getSizeList()
{
    return sizeList;
}

void Menu::setSizeList(int size)
{
    sizeList = size;
}

int Menu::getInput(){
    int ch;
    ch = wgetch(getWin());
    switch (ch) {
        case KEY_UP:
            if (getHighlight() == 0)
                setHighlight(0);
            else
                setHighlight(getHighlight()-1);
            break;

        case KEY_DOWN:
            if (getHighlight() == getSizeList()-1) 
                setHighlight(getSizeList()-1);
            else 
                setHighlight(getHighlight()+1);
            break;

        case 10:
            // if choosing "back to menu" and in any category besides main
            // sends you to main
            if (getHighlight() == (getSizeList() - 1) and getCategory() != -1)
            {
                setCategory(-1);
                setHighlight(0);
            }
            // if choosing exit in main, quits program
            else if (getHighlight() == (getSizeList() -1) and getCategory() == -1)
                ch = 'x';
            // if in main, change to any other category
            else if (getCategory() == -1)
            {
                setCategory(getHighlight());
                setHighlight(0);
            }
            break;
        default:
            break;
    }
    return ch;
}

void Menu::display(){

    wclear(getWin());
    printCurrentScreen();
    wrefresh(getWin());
}

