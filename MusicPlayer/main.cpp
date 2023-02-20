
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdio>

int main()
{
    sf::Music music;
    if (!music.openFromFile("music/song1.wav"))
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

        std::cout << "Press 'p' to pause/unpause the music, 's' to stop the music: ";
        char c = getchar();
        if (c == '\n')
            continue;
        if (c == 's')
        {
            music.stop();
            isStopped = true;
        }
        else if (c == 'p')
        {
            if (!isPaused)
                music.pause();
            else
                music.play();
            isPaused = !isPaused;
        }
    }

    return 0;
}