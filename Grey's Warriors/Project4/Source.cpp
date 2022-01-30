#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;



int main() {
	string sub, year, peop, other;
	cout << "Sub: ";
	getline(cin, sub); 
	cout << "Year: ";
	cin >> year;
	cout << "People: ";
	cin >> peop;
	sf::RenderWindow window(sf::VideoMode(1460, 880), "DMLS");
	sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
	player.setPosition(206.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("linux.png");
	player.setTexture(&playerTexture);
	sf::Texture t, bg;
	bg.loadFromFile("bg.png");
	t.loadFromFile("book.png");
	sf::Sprite s(t), b(bg);

	s.setPosition(250, 100);
	b.setPosition(0, 30);
	float deltaTime = 0.0f;
	sf::Clock clock;
	sf::Font arial;
	arial.loadFromFile("Kalamian01.ttf");
	sf::Text n;
	n.setFillColor(sf::Color::Black);
	n.setFont(arial);
	std::string st = "Event: " + sub + "\n" + "Year: " +  year + "\n" + "People: " + peop + "\n" ;
	n.setString(st);
	n.setPosition(400, 200);
	

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:window.close(); break;
			}

		}
		window.clear(sf::Color::White); window.draw(b);
		window.draw(s); window.draw(n);


		window.display();
	}
}