#include <ncurses.h>
#include <string>
#include <iostream>

#include "interface.hpp"

int main()
{
    Menu *m = new Menu(2, 10, 20);
    while(m->getInput() != 'x'){
        m->display();
    }
    m->~Menu();
    return 0;
}
