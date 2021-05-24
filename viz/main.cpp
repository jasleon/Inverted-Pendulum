#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "Inverted Pendulum");

  sf::RectangleShape base(sf::Vector2f(100.0F, 100.0F));
  base.setOrigin(50.0F, 50.0F);
  base.setPosition(320.0F, 240.0F);
  base.setFillColor(sf::Color::Green);

  sf::Clock clock;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
          break;
      }
    }
    sf::Time elapsed = clock.getElapsedTime();
    std::cout << elapsed.asSeconds() << '\n';
    window.clear();
    window.draw(base);
    window.display();
  }
  return 0;
}
