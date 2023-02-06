#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdio>

int main()
{
    std::cout << "Press 'p' to pause/unpause the music, 's' to stop the music: ";
 
    sf::Music music;
    if (!music.openFromFile("C:\\Users\\Rodrigo\\source\\repos\\MusicPlayer\\x64\\Debug\\music.wav"))
        return -1;

    music.play();

    bool isPaused = false;
    bool isStopped = false;
    
    
    while (!isStopped)
    {
        if (music.getStatus() == sf::Music::Stopped)
        {
            isStopped = true;
            break;
        }

        char c = getchar();
        if (c == '\n')
            continue;
        if (c == 's')
        {
            music.stop();
            std::cout << "Music is no longer playing";
            isStopped = true;
        }
        else if (c == 'p')
        {
            if (!isPaused)
                music.pause(), std::cout << "Song is paused ";


            else
                music.play();
            isPaused = !isPaused;
        }
    }

    return 0;
}
