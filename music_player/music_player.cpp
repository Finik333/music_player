#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

void menu(RenderWindow& window) {
    Texture menuBackground;
    if (!menuBackground.loadFromFile("bg.png"))
    {
        return;
    }
    Sprite menuBg(menuBackground);
    bool isMenu = true;
    menuBg.setPosition(345, 0);
    while (isMenu)
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
                isMenu = false;
            }
        }
        window.clear(Color(129, 181, 221));
        window.draw(menuBg);
        window.display();
    }
}

int main() {
    RenderWindow window(VideoMode(1376, 768), L"Мой плеер");
    SoundBuffer buffer1, buffer2;
    if (!buffer1.loadFromFile("sound1.wav") || !buffer2.loadFromFile("sound2.wav")) {
        return 1;
    }
    Sound sound;
    sound.setBuffer(buffer1);

    bool playSound = false;

    while (window.isOpen())
    {
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
                }
                else if (event.key.code == Keyboard::B) {
                    sound.stop();
                    sound.setBuffer(buffer2);
                    sound.play();
                }
            }
        }
        if (!playSound) {
            sound.play();
            playSound = false;
        }

        window.clear(Color::Blue);
        window.display();
        menu(window);
    }
}