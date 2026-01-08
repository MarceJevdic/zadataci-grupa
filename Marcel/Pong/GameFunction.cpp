#include "GameFunction.hpp"
#include <iostream>
#include <ctime>

int showMenu(RenderWindow& window, Font& font) {
    vector<string> options = { "Player vs Player", "Player vs Bot" };
    vector<Text> texts;

    Text title("PONG", font, 70);
    title.setFillColor(Color::Cyan);
    title.setPosition(300, 80);

    for (int i = 0; i < options.size(); i++) {
        Text t(options[i], font, 40);
        t.setPosition(250, 250 + i * 100);
        texts.push_back(t);
    }

    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed)
                window.close();

            if (e.type == Event::MouseButtonPressed) {
                for (int i = 0; i < texts.size(); i++) {
                    if (texts[i].getGlobalBounds().contains(
                        (float)Mouse::getPosition(window).x,
                        (float)Mouse::getPosition(window).y))
                        return i + 1;
                }
            }
        }

        window.clear();
        window.draw(title);
        for (auto& t : texts) window.draw(t);
        window.display();
    }
    return -1;
}

// ================= GAME =================
void startGame(int mode) {
    RenderWindow window(VideoMode(800, 600), "Pong");
    window.setFramerateLimit(60);

    Font font;
    font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");

    Ball ball;
    PlayerPaddle left(30, Keyboard::W, Keyboard::S);
    PlayerPaddle rightPlayer(760, Keyboard::Up, Keyboard::Down);
    BotPaddle bot(760, &ball.shape);

    Paddle* right = (mode == 1)
        ? (Paddle*)&rightPlayer
        : (Paddle*)&bot;

    vector<PowerUp> powerUps;
    vector<string> effects;
    Clock spawnClock;
    Clock effectTimer;

    int scoreL = 0, scoreR = 0;
    Text score("", font, 40);
    score.setPosition(360, 20);

    bool gameOver = false;
    Text winnerText("", font, 50);
    winnerText.setFillColor(Color::Yellow);
    winnerText.setPosition(180, 260);

    Clock gameOverClock;


    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e))
            if (e.type == Event::Closed)
                window.close();

        
        if (!gameOver) {

            
            if (spawnClock.getElapsedTime().asSeconds() > 3.f) {
                vector<string> types = { "SpeedUp", "BigPaddle", "SmallPaddle" };
                string t = types[rand() % types.size()];
                powerUps.emplace_back(
                    t,
                    Vector2f(rand() % 600 + 100, rand() % 400 + 100)
                );
                spawnClock.restart();
            }

            left.update();
            right->update();
            ball.update();

            if (ball.getBounds().intersects(left.getBounds()))
                ball.velocity.x *= -1;

            if (ball.getBounds().intersects(right->getBounds()))
                ball.velocity.x *= -1;

            for (int i = 0; i < powerUps.size(); i++) {
                powerUps[i].updateVisual();

                if (powerUps[i].expired()) {
                    powerUps.erase(powerUps.begin() + i);
                    i--;
                    continue;
                }

                if (powerUps[i].getBounds().intersects(ball.getBounds())) {
                    string t = powerUps[i].type;
                    effects.push_back(t);
                    effectTimer.restart();

                    if (t == "SpeedUp")
                        ball.velocity *= 1.3f;

                    if (t == "BigPaddle") {
                        left.shape.setSize({ 10, 150 });
                        right->shape.setSize({ 10, 150 });
                    }

                    if (t == "SmallPaddle") {
                        left.shape.setSize({ 10, 60 });
                        right->shape.setSize({ 10, 60 });
                    }

                    powerUps.erase(powerUps.begin() + i);
                    i--;
                }
            }

            
            if (!effects.empty() &&
                effectTimer.getElapsedTime().asSeconds() > 5.f) {

                ball.velocity.x = (ball.velocity.x > 0) ? 5.f : -5.f;
                ball.velocity.y = (ball.velocity.y > 0) ? 5.f : -5.f;

                left.shape.setSize({ 10, 100 });
                right->shape.setSize({ 10, 100 });

                effects.clear();
            }

            if (ball.shape.getPosition().x < 0) {
                scoreR++;
                ball.reset();
            }

            if (ball.shape.getPosition().x > 800) {
                scoreL++;
                ball.reset();
            }

            score.setString(to_string(scoreL) + " : " + to_string(scoreR));

            if (scoreL == 3 || scoreR == 3) {
                gameOver = true;

                if (scoreL == 3)
                    winnerText.setString("Player 1 je pobijedio!");
                else {
                    if (mode == 1)
                        winnerText.setString("Player 2 je pobijedio!");
                    else
                        winnerText.setString("     Bot je pobijedio!");
                }

                gameOverClock.restart();
            }
        }
        
        else {
            if (gameOverClock.getElapsedTime().asSeconds() > 3.f)
                window.close();
        }

        
        window.clear(Color::Black);
        window.draw(score);

        if (gameOver)
            window.draw(winnerText);

        left.draw(window);
        right->draw(window);
        ball.draw(window);
        for (auto& p : powerUps) p.draw(window);

        window.display();
    }

}
