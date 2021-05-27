#include <SFML/Graphics.hpp>
#include <iostream>

#include "Eigen/Dense"
#include "inverted_pendulum.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "Inverted Pendulum");

  sf::RectangleShape base(sf::Vector2f(100.0F, 100.0F));
  base.setOrigin(50.0F, 50.0F);
  base.setPosition(320.0F, 240.0F);
  base.setFillColor(sf::Color::Green);
  base.setOutlineColor(sf::Color::Black);
  base.setOutlineThickness(2.5);

  sf::Clock clock;
  Eigen::VectorXd x_0(4);
  x_0 << 0, M_PI / 4, 0, 0;
  InvertedPendulum model(x_0);

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
    model.Update(elapsed.asSeconds(), 0);
    Eigen::VectorXd x = model.GetState();
    std::cout << "x: " << x(0) << '\n';
    base.setPosition(320.0F + 100 * x(0), 240.0F);
    window.clear(sf::Color::White);
    window.draw(base);
    window.display();
  }
  return 0;
}
