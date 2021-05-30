#include <SFML/Graphics.hpp>
#include <iostream>

#include "Eigen/Dense"
#include "inverted_pendulum.h"

double to_radians(double degrees) { return (degrees * (M_PI / 180.0F)); }

double to_degrees(double radians) { return (radians * (180.0F / M_PI)); }

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "Inverted Pendulum");

  // Initial conditions
  const double theta_0 = -30.0F;
  
  sf::RectangleShape base(sf::Vector2f(100.0F, 100.0F));
  base.setOrigin(50.0F, 50.0F);
  base.setPosition(320.0F, 240.0F);
  base.setFillColor(sf::Color::Blue);

  sf::RectangleShape pole(sf::Vector2f(20.0F, 200.0F));
  pole.setOrigin(10.0F, 200.0F);
  pole.setPosition(320.0F, 240.0F);
  pole.setRotation(-theta_0);
  pole.setFillColor(sf::Color::Green);

  sf::Clock clock;
  Eigen::VectorXd x_0(4);
  x_0 << 0, to_radians(theta_0), 0, 0;
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
    pole.setPosition(320.0F + 100 * x(0), 240.0F);
    pole.setRotation(to_degrees(-x(1)));
    window.clear(sf::Color::White);
    window.draw(base);
    window.draw(pole);
    window.display();
  }
  return 0;
}
