#pragma once
class Paddle
{
public:
	Paddle(float x_in, float y_in, float size_in);
	~Paddle();

	void update();
	void draw();
private:
	float x;
	float y;
	float size;
};

