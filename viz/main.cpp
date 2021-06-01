#include <SFML/Graphics.hpp>
#include <iostream>

#include "Eigen/Dense"
#include "inverted_pendulum.h"
#include "tools.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "Inverted Pendulum");

  // Set initial conditions
  const double p_0 = 0;
  const double theta_0 = -30;
  Eigen::VectorXd x_0(4);
  x_0 << p_0, to_radians(theta_0), 0, 0;

  // Create a model with default parameters
  InvertedPendulum *ptr = new InvertedPendulum(x_0);

  // Create a track for the cart
  sf::RectangleShape track(sf::Vector2f(640.0F, 2.0F));
  track.setOrigin(320.0F, 1.0F);
  track.setPosition(320.0F, 240.0F);
  track.setFillColor(sf::Color::Black);

  // Create the cart of the inverted pendulum
  sf::RectangleShape cart(sf::Vector2f(100.0F, 100.0F));
  cart.setOrigin(50.0F, 50.0F);
  cart.setPosition(320.0F, 240.0F);
  cart.setFillColor(sf::Color::Black);

  // Create the pole of the inverted pendulum
  sf::RectangleShape pole(sf::Vector2f(20.0F, 200.0F));
  pole.setOrigin(10.0F, 200.0F);
  pole.setPosition(320.0F, 240.0F);
  pole.setRotation(-theta_0);
  const sf::Color Brown = sf::Color(0xCC, 0x99, 0x66);
  pole.setFillColor(Brown);

  // Create a clock to run the simulation
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

    // Update the simulation
    sf::Time elapsed = clock.getElapsedTime();
    const float time = elapsed.asSeconds();
    std::cout << time << '\n';
    if (time < 15) {
      ptr->Update(time, 0);
    } else {
      delete ptr;
      ptr = new InvertedPendulum(x_0);
      clock.restart();
    }

    Eigen::VectorXd x = ptr->GetState();

    // Update SFML drawings
    cart.setPosition(320.0F + 100 * x(0), 240.0F);
    pole.setPosition(320.0F + 100 * x(0), 240.0F);
    pole.setRotation(to_degrees(-x(1)));

    window.clear(sf::Color::White);
    window.draw(track);
    window.draw(cart);
    window.draw(pole);
    window.display();
  }
  return 0;
}
