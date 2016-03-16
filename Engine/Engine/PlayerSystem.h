#pragma once

#include "System.h"
#include "Input.h"
#include "Time.h"

class PlayerSystem : public System
{
	bool condition(Handle<Entity> i)
	{
		return i->rigidbody > -1 && i->transform > -1 && i->controller > -1;
	}

	void update(Handle<Entity> i)
	{
		auto &i = Input::instance();
		auto &c = *i->controller;
		auto &r = *i->rigidbody;
		float dt = Time::instance().getDeltaTime();

		if (input.getKey(c.LEFT))
		{
			r.addForce(-c.turnSpeed);
		}
		if (input.getKey(c.RIGHT))
		{
			r.addForce(c.turnSpeed);
		}
		if (input.getKey(c.UP))
		{
			r.addForce(i->transform->getUp() * c.speed * dt);
		}
	}
};