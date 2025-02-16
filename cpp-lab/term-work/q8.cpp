/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// 8. Digital Media Player
// • Objective: Create a base class MediaPlayer with a virtual function play(). Derive classes
// AudioPlayer and VideoPlayer from MediaPlayer, and implement play() for both audio and
// video playback.
// • Scenario:
// o You are developing a media player application that supports both audio and video files.
// o The base class MediaPlayer will have a virtual function play() that is overridden by the
// derived classes to handle audio and video playback differently.
// • Instructions:
// o Define a base class MediaPlayer with a virtual function play().
// o Create derived classes AudioPlayer and VideoPlayer. In AudioPlayer, implement
// play() to simulate audio playback, and in VideoPlayer, implement play() to simulate
// video playback.
// o In the main function, create pointers to MediaPlayer and use polymorphism to call the
// appropriate play() method based on the object type.

#include <iostream>
using namespace std;

class MediaPlayer {
public:
    virtual void play() = 0;
};

class AudioPlayer : public MediaPlayer {
public:
    void play() {
        cout << "Playing audio..." << endl;
    }
};

class VideoPlayer : public MediaPlayer {
public:
    void play() {
        cout << "Playing video..." << endl;
    }
};

int main() {
    MediaPlayer* player1 = new AudioPlayer();
    MediaPlayer* player2 = new VideoPlayer();

    player1->play();
    player2->play();

    delete player1;
    delete player2;

    return 0;
}
