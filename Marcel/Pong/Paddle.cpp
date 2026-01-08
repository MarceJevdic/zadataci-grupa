#include "Paddle.hpp"

// Paddle
Paddle::Paddle(float x) {
    shape.setSize({ 10.f, 100.f });
    shape.setPosition(x, 250.f);
    shape.setFillColor(Color::White);
}
void Paddle::move(float dy) {
    if (shape.getPosition().y + dy >= 0 &&
        shape.getPosition().y + dy <= 600 - shape.getSize().y)
        shape.move(0, dy);
}
void Paddle::draw(RenderWindow& window) { window.draw(shape); }
FloatRect Paddle::getBounds() const { return shape.getGlobalBounds(); }

// PlayerPaddle
PlayerPaddle::PlayerPaddle(float x, Keyboard::Key u, Keyboard::Key d)
    : Paddle(x), up(u), down(d) {
}
void PlayerPaddle::update() {
    if (Keyboard::isKeyPressed(up)) move(-speed);
    if (Keyboard::isKeyPressed(down)) move(speed);
}

// BotPaddle
BotPaddle::BotPaddle(float x, const CircleShape* b)
    : Paddle(x), ball(b) {
}
void BotPaddle::update() {
    float ballCenter = ball->getPosition().y + ball->getRadius();
    float paddleCenter = shape.getPosition().y + shape.getSize().y / 2;
    if (ballCenter < paddleCenter) move(-speed);
    else move(speed);
}
