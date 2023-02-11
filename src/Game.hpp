
#ifndef GAME_HPP
#define GAME_HPP

#include <chrono>
#include <ctime>
#include <string>


class Game{
    private:
        std::string name;
        time_t  d_start;
        time_t  d_beat;
        time_t  d_release;
        int     review;
        std::string status;
        std::string  platform;
        
    public:
        Game();
        ~Game();
        void    setName(std::string name);
        void    setStart(time_t d_start);
        void    setBeat(time_t d_beat);
        void    setRelease(time_t d_release);
        void    setReview(int review);
        void    setStatus(std::string status);
        void    setPlatform(std::string platform);

        std::string getName()       {return name;}
        time_t  getBeat()           {return d_beat;}
        time_t  getStart()          {return d_start;}
        time_t  getRelease()        {return d_release;}
        int     getReview()         {return review;}   
        std::string getStatus()     {return status;}
        std::string  getPlatform()  {return platform;}

        void    print();// Prints all the members of a Game
};

#endif /*GAME_HPP*/

