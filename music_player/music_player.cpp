#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(1376, 768), L"Мой плеер", Style::Default);
    SoundBuffer buffer1, buffer2;
    if (!buffer1.loadFromFile("sound1.wav") || !buffer2.loadFromFile("sound2.wav")) {
        return -1;
    }


    Texture menuBackground,play,pause;
    menuBackground.loadFromFile("bg.png");
    play.loadFromFile("play.png");
    pause.loadFromFile("pause.png");
    Sprite menuBg(menuBackground);
    Sprite Play(play);
    Sprite Pause(pause);
    Pause.setPosition(0, 0);
    menuBg.setPosition(345, 0);
    Play.setPosition(100, 0);


    Sound sound;
    bool soundplay = false;
    while (window.isOpen())
    {
        window.draw(menuBg);
        window.draw(Play);
        window.draw(Pause);
        window.display();
        window.clear(Color::White);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::A) {
                    sound.stop();
                    sound.setBuffer(buffer1);
                    sound.play();
                    soundplay = true;
                }
                else if (event.key.code == Keyboard::B) {
                    sound.stop();
                    sound.setBuffer(buffer2);
                    sound.play();
                    soundplay = true;
                }
                else if (event.key.code == Keyboard::Space) {
                    sound.pause();
                    soundplay = false;
                }
                if (soundplay == false) {
                    if (event.key.code == Keyboard::S) {
                        sound.play();
                        soundplay = true;
                    }
                }
            }
            if (IntRect(100, 0, 80, 80).contains(Mouse::getPosition(window))) { soundplay=false; }
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    if (soundplay == false) { sound.setBuffer(buffer1);  sound.play(); soundplay = true;  window.draw(menuBg); window.display(); }
                }
                if (Mouse::isButtonPressed(Mouse::Right)) {
                    if (soundplay == true) { sound.pause(); soundplay = false; }
                }

            
        }
    }

        window.draw(menuBg);
        window.display();
}