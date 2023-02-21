#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdio>
#include <string>
#include "queue.cpp"
int main()
{
    Queue musicQueue(3);
    musicQueue.add("music/song1.wav");
    musicQueue.add("music/song2.wav");
    musicQueue.add("music/song3.wav");

    sf::Music music;
    music.openFromFile(musicQueue.remove());
    music.play();

    bool isPaused = false;
    bool isStopped = false;

    while (!isStopped)
    {
        if (music.getStatus() == sf::Music::Stopped)
        {
            if (musicQueue.size() > 0) {
                music.openFromFile(musicQueue.remove());
                music.play();
                isPaused = false;
                isStopped = false;
            }
            else {
                isStopped = true;
                break;
            }
        }

        std::cout << "Press 'p' to pause/unpause the music, 's' to stop the music, 'n' to play the next song, 'l' to list the songs in the queue: ";
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
        else if (c == 'n')
        {
            if (musicQueue.size() > 0)
            {
                music.stop();
                music.openFromFile(musicQueue.remove());
                music.play();
                isPaused = false;
                isStopped = false;
            }
            else
            {
                std::cout << "No more songs in the queue" << std::endl;
            }
        }
        else if (c == 'l') // List current songs
        {
            std::cout << "Current songs in queue:" << std::endl;
            int front = musicQueue.getFront();
            int back = musicQueue.getBack();
            std::string* array = musicQueue.getArray();
            for (int i = front + 1; i <= back; i++)
            {
                std::cout << array[i] << std::endl;
            }
        }

    }

    return 0;
}