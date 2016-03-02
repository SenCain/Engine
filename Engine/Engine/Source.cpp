//#include "sfwdraw.h"
//#include "VMath.h"
//#include "Transform.h"
//
//// Replace with your mat4 potentially
//struct _mat4
//{
//	float m[16];
//};
//
//_mat4 mat3to4(float *m)
//{
//	return
//	{ m[0],m[1], 0, m[2],
//		m[3],m[4], 0, m[5],
//		0 ,  0 , 1 ,  0,
//		m[6],m[7], 0, m[8] };
//}
//
//int main()
//{
//	sfw::initContext();
//	int  handle = sfw::loadTextureMap("./player.png");
//
//	Transform transform1, transform2;
//	Transform orbitalSpinner;
//
//	float speed = 100;
//	float angularSpeed = 15;
//	float x = 400, y = 400, angle = 0;
//
//	while (sfw::stepContext())
//	{
//		if (sfw::getKey('W')) y += sfw::getDeltaTime()  * speed;
//		if (sfw::getKey('A')) x -= sfw::getDeltaTime()  * speed;
//		if (sfw::getKey('S')) y -= sfw::getDeltaTime()  * speed;
//		if (sfw::getKey('D')) x += sfw::getDeltaTime()  * speed;
//		if (sfw::getKey('Q')) angle += sfw::getDeltaTime() * angularSpeed;
//		if (sfw::getKey('E')) angle -= sfw::getDeltaTime() * angularSpeed;
//
//		transform1.setPosition({ x, y });
//		transform1.setAngle(angle);
//		transform1.setScale({ 500,300 });
//
//		orbitalSpinner.setParent(&transform1);
//		orbitalSpinner.setAngle(-sfw::getTime());
//
//		transform2.setParent(&orbitalSpinner);
//		transform2.setPosition({ .25f, .25f });
//		transform2.setScale({ .5f,.5f });
//
//		auto m1 = mat3to4(transform1.getGlobalTransform().v);
//		auto m2 = mat3to4(transform2.getGlobalTransform().v);
//
//		sfw::drawTextureMatrix(handle, 0, WHITE, m1.m);
//		sfw::drawTextureMatrix(handle, 0, MAGENTA, m2.m);
//	}
//	sfw::termContext();
//
//	return 0;
//}

#include "Window.h"
#include "Input.h"
#include "Time.h"
#include <iostream>
#include "Factory.h"
#include "DebugDraw.h"

void main()
{
	auto &window = Window::instance();
	auto &input = Input::instance();
	auto &time = Time::instance();

	window.init();
	input.init();
	time.init();

	Factory::makeBall({ 40,  40 }, { 10,10 }, 400, 40);
	Factory::makeBall({ 70,  70 }, { 40,40 }, 120, 12);
	Factory::makeBall({ 80, 200 }, { 0,100 }, 280, 200);

	DebugDraw debugDraw;

	while (window.step())
	{
		input.step();
		time.step();

		debugDraw.step();
	}

	time.term();
	input.term();
	window.term();
}