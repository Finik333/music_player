#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(1376, 768), L"Мой плеер", Style::Default);
    SoundBuffer buffer1, buffer2;
    if (!buffer1.loadFromFile("sound1.wav") || !buffer2.loadFromFile("sound2.wav")) {
        return -1;
    }
    Texture menuBackground;
    menuBackground.loadFromFile("bg.png");
    Sprite menuBg(menuBackground);
    menuBg.setPosition(345, 0);
    Sound sound;

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

        window.clear(Color(129, 181, 221));
        window.draw(menuBg);
        window.display();
    }
}
