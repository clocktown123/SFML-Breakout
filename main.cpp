#include <SFML/Graphics.hpp>
//#include "Brick.h"
using namespace sf;


class Brick {

private:
	int xpos;
	int ypos;
	int width;
	int height;
	bool Dead;
	RectangleShape shape;

public:
	Brick(float x, float y, float w, float h) {
		xpos = x;
		ypos = y;
		width = w;
		height = h;
		Dead = false;

		// set up the shape
		shape.setSize(Vector2f(width, height));
		shape.setPosition(xpos, ypos);
		shape.setFillColor(Color::Red);


	}

	//draws the brick on the window
	void draw(RenderWindow& window) {
		if (!Dead) {
			window.draw(shape);
		}
	}

	//sets the brick to dead
	bool killBrick() {
		Dead = true;
		shape.setFillColor(Color::Transparent); // make the brick invisible
	}

	// checks collision with the ball using class variables
	bool checkCollision(float ballX, float ballY, float ballRadius) {
		if (!Dead &&
			ballX + ballRadius > xpos && ballX - ballRadius < xpos + width &&
			ballY + ballRadius > ypos && ballY - ballRadius < ypos + height) {
			killBrick();
			return true;
		}
		return false;
	}// end collision function

	float getX() {
		return xpos;
	}

	float getY() {
		return ypos;
	}

	float getW() {
		return width;
	}

	float getH() {
		return height;
	}


};// end of class brick!


class Ball {
private:
	int BX;
	int BY;
	int xvel;
	int yvel;
	int radius;
	CircleShape shape;

public:
	Ball(float bx, float by, float xv, float yv, float r) {
		BX = bx;
		BY = by;
		xvel = xv;
		yvel = yv;
		radius = r;

		//set up shape
		shape.setRadius(radius);
		shape.setPosition(BX, BY);
		shape.setFillColor(Color::White);

	}

	//moves the ball and handles boundary collision
	void move(float windowWidth, float windowHeight) {
		BX += xvel;
		BY += yvel;
		shape.setPosition(BX, BY);
		//check for collision with the left and right side of the window
		if (BX <= 0 || BX + radius * 2 >= windowWidth) {
			xvel = -xvel;
		}
		if (BY <= 0 || BY + radius * 2 >= windowHeight) {
			yvel = -yvel;
		}
	}

	bool brickCollision(Brick& brick) {
		if (!brick.killBrick() && //ensure the brick is not dead
			BX + radius > brick.getX() &&
			BX - radius < brick.getX() + brick.getW() &&
			BY + radius > brick.getY() &&
			BY - radius < brick.getY() + brick.getH()) {
			brick.killBrick();
			reflect(); //reflect the ball vertically
			return true;
		}
		return false;
	}

	void draw(RenderWindow& window) {
		window.draw(shape);
	}
};

class Paddle {
private:
	int PX;
	int PY;
	int PW;
	int PH;
	int Speed;
	RectangleShape shape;

public:
	Paddle(float px, float py, float pw, float ph, float sp) {
		PX = px;
		PY = py;
		PW = pw;
		PH = ph;
		Speed = sp;

		//set up shape
		shape.setSize(Vector2f(PW, PH));
		shape.setPosition(PX, PY);
		shape.setFillColor(Color::White);
	}

	void draw(RenderWindow& window) {
		window.draw(shape);
	}

	//move the paddle left
	void moveLeft() {
		PX -= Speed;
		if (PX < 0) PX = 0; //keep paddle within bounds
		shape.setPosition(PX, PY);
	}

	void moveRight() {
		PX += Speed;
		if (PX+100 > 800) PX = 700; //keep paddle within bounds
		shape.setPosition(PX, PY);
	}

};



int main() {
	RenderWindow window(VideoMode(800, 800), "Breakout");

	//instiantate game objects

	Ball ball1( 400, 400, 1, 1, 10);

	Paddle paddle1(350, 700, 100, 20, 1);

	Brick brick1(100, 100, 50, 20);
	Brick brick2(160, 100, 50, 20);
	Brick brick3(220, 100, 50, 20);
	Brick brick4(280, 100, 50, 20);
	Brick brick5(340, 100, 50, 20);
	Brick brick6(400, 100, 50, 20);
	Brick brick7(460, 100, 50, 20);
	Brick brick8(520, 100, 50, 20);
	Brick brick9(580, 100, 50, 20);
	Brick brick10(640, 100, 50, 20);

	//second row
	Brick brick11(100, 150, 50, 20);
	Brick brick12(160, 150, 50, 20);
	Brick brick13(220, 150, 50, 20);
	Brick brick14(280, 150, 50, 20);
	Brick brick15(340, 150, 50, 20);
	Brick brick16(400, 150, 50, 20);
	Brick brick17(460, 150, 50, 20);
	Brick brick18(520, 150, 50, 20);
	Brick brick19(580, 150, 50, 20);
	Brick brick20(640, 150, 50, 20);

	//third row
	Brick brick21(100, 200, 50, 20);
	Brick brick22(160, 200, 50, 20);
	Brick brick23(220, 200, 50, 20);
	Brick brick24(280, 200, 50, 20);
	Brick brick25(340, 200, 50, 20);
	Brick brick26(400, 200, 50, 20);
	Brick brick27(460, 200, 50, 20);
	Brick brick28(520, 200, 50, 20);
	Brick brick29(580, 200, 50, 20);
	Brick brick30(640, 200, 50, 20);
	
	

	//Game Loop#############################################################
	while (window.isOpen()) {
		//EVENT (input) section---------------------------
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		//handle paddle movement
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			paddle1.moveLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			paddle1.moveRight();
		}

		ball1.move(800, 800);

		window.clear(); //clrear screen

		

		brick1.draw(window);
		brick2.draw(window);
		brick3.draw(window);
		brick4.draw(window);
		brick5.draw(window);
		brick6.draw(window);
		brick7.draw(window);
		brick8.draw(window);
		brick9.draw(window);
		brick10.draw(window);

		//second row
		brick11.draw(window);
		brick12.draw(window);
		brick13.draw(window);
		brick14.draw(window);
		brick15.draw(window);
		brick16.draw(window);
		brick17.draw(window);
		brick18.draw(window);
		brick19.draw(window);
		brick20.draw(window);

		//third row
		brick21.draw(window);
		brick22.draw(window);
		brick23.draw(window);
		brick24.draw(window);
		brick25.draw(window);
		brick26.draw(window);
		brick27.draw(window);
		brick28.draw(window);
		brick29.draw(window);
		brick30.draw(window);

		ball1.draw(window);

		paddle1.draw(window);
		

		// update the window (its like display.flip)
		window.display();
		


	}// end of game loop
}
