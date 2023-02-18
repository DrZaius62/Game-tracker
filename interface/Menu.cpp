#include "Menu.hpp"
#include <curses.h>

// Makes a vector of the items in the xml, so it can be passed to the relevant
// functions to make a list and display it
std::vector<std::string> makeList(std::string category, 
        std::vector<Game*> &listGames)
{
    pugi::xml_node group = statusNode(root, category);
    std::vector<std::string> listNames;

    for(auto game : group)
    {
        listNames.push_back(game.attribute("name").value());
        listGames.push_back(makeGame(game));
    }
    return listNames;
}

// Constructor
Menu::Menu(int yFactor, int xFactor, int starty, int startx)
{
    // ncurses initialization
    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    width = xMax/xFactor;
    height = yMax/yFactor;

    win = newwin(height, width, starty, startx);
    keypad(win, true);
    setWin(win);


    setHighlight(0);
    setCategory(-1);
    setOldCategory(-1);

    setInfo(new Info(height, width));

    printMain();
    refresh();
    wrefresh(win);
}

// Destructor
Menu::~Menu()
{
    Info *curInfo = getInfo();
    if (curInfo != nullptr)
        curInfo->~Info();
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
        std::vector<std::string> listNames;
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

        std::vector<Game*> listGames;
        listNames = makeList(title, listGames);
        listNames.push_back(back);
        setSizeList(listNames.size());
        WINDOW *win = getWin();
        printTitle(win, title);
        setSizeList(listNames.size());
        printList(win, getHighlight(), listNames);
        

        Info *curInfo = getInfo();
        if (getHighlight() != (int)listNames.size()-1)
        {
            curInfo->display(listGames[getHighlight()]);
        }

        else{
            wclear(curInfo->getWin());
            wrefresh(curInfo->getWin());
        }

        box(win, 0, 0);
    }
    else {
        Info *curInfo = getInfo();
        wclear(curInfo->getWin());
        wrefresh(curInfo->getWin());

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


Info *Menu::getInfo(){
    return info;
}

void Menu::setInfo(Info *info)
{
    this->info= info;
}

int Menu::getCategory()
{
    return category;
}

void Menu::setCategory(int set)
{
    category = set;
}

int Menu::getOldCategory()
{
    return oldCategory;
}

void Menu::setOldCategory(int set)
{
    oldCategory = set;
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

int Menu::getHeight(){
    return height;
}

int Menu::getWidth(){
    return width;
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
                setOldCategory(getCategory());
                setCategory(-1);
                setHighlight(0);
            }
            // if choosing exit in main, quits program, exit is the last option
            // always
            else if (getHighlight() == (getSizeList() -1) and getCategory() == -1)
                ch = 'x';
            // if in main, change to any other category
            else if (getCategory() == -1)
            {
                setOldCategory(getCategory());
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

