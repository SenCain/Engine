#pragma once
#include <iostream>
#include "System.h"

struct Collision
{
	Handle<Entity> first, second;
	CollisionData collision;

	static std::vector<Collision> &getData()
	{
		static std::vector<Collision> data;
		return data;
	}
};

class CollisionSystem
{
	virtual bool condition(Collision a) = 0;
	virtual void update(Collision a) = 0;
	virtual void onStep() {}
public:
	void step()
	{
		onStep();
		for each(Collision c in Collision::getData())
			update(c);
	}
};

class CollisionDetection: public BinarySystem
{
	void onstep() { Collision::getData().clear(); }

	bool condition(Handle<Entity> i) { return i->transform > -1 && i->collider > -1; }

	void update(Handle<Entity> i, Handle<Entity> j) 
	{
		auto cd = EvaluateCollision(*i->transform, *i->collider, *j->transform, *j->collider);
		if (cd.collide)
		{
			Collision::getData().push_back(Collision{ i,j, cd });
		}
	}
};