
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdio>
#include <vector>

int main()
{
    std::cout << "Press 'p' to pause/unpause the music, 's' to stop the music, 'n' to play the next song, 'b' to play the previous song: ";

    std::vector<std::string> songQueue = { "C:\\Users\\Rodrigo\\source\\repos\\MusicPlayer\\x64\\Debug\\music2.wav", "C:\\Users\\Rodrigo\\source\\repos\\MusicPlayer\\x64\\Debug\\music1.wav", "C:\\Users\\Rodrigo\\source\\repos\\MusicPlayer\\x64\\Debug\\music3.wav"};
    int currentSong = 0;

    sf::Music music;
    if (!music.openFromFile(songQueue[currentSong]))
        return -1;

    music.play();

    bool isPaused = false;
    bool isStopped = false;

    while (!isStopped)
    {
        if (music.getStatus() == sf::Music::Stopped)
        {
            currentSong = (currentSong + 1) % songQueue.size();
            if (!music.openFromFile(songQueue[currentSong]))
                return -1;
            music.play();
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
        else if (c == 'n')
        {
            currentSong = (currentSong + 1) % songQueue.size();
            if (!music.openFromFile(songQueue[currentSong]))
                return -1;
            music.play(), std::cout << "Playing next song ";
        }
        else if (c == 'b')
        {
            currentSong = (currentSong - 1 + songQueue.size()) % songQueue.size();
            if (!music.openFromFile(songQueue[currentSong]))
                return -1;
            music.play(),std::cout << "Playing previous song  ";
        }
    }

    return 0;
}

