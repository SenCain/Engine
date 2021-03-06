#pragma once
#include "Shapes.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

struct CollisionData // Wrapper for Minimum Translation Vector
{
	bool     collide;         // Did we collide?
	static float    depth;			 // Penetration depth
	Vector2  normal;   // CollisionNormal * PenetrationDepth = Minimum Translation Vector, also called the impulse vector, very important! 
};

CollisionData DSAT(float amin, float amax, float bmin, float bmax, Vector2 axis);

//Some distance formula
float point_plane_dist  (const Vector2 &a, const Plane &b);
float ray_plane_dist    (const Ray     &a, const Plane &b);
//All of the basic tests
CollisionData iTest(const AABB   &a, const AABB   &b);
CollisionData iTest(const AABB   &a, const Circle &b);
CollisionData iTest(const AABB   &a, const Ray    &b);
CollisionData iTest(const AABB   &a, const Plane  &b);

CollisionData iTest(const Circle &a, const Circle &b);
CollisionData iTest(const Circle &a, const Plane  &b);
CollisionData iTest(const Circle &a, const Ray    &b);

CollisionData iTest(const Ray    &a, const Plane  &b);

// Convex Hull vs remaining shapes
CollisionData iTest(const ConvexHull &A, const ConvexHull &B);
CollisionData iTest(const ConvexHull &A, const Circle     &b);
CollisionData iTest(const ConvexHull &A, const Ray        &b);
CollisionData iTest(const ConvexHull &A, const Plane      &b);
CollisionData iTest(const ConvexHull &A, const AABB       &b);

// Flip overloads for lhs/rhs
CollisionData iTest(const Circle &b, const AABB   &a) { return iTest(a, b); }
CollisionData iTest(const Plane  &b, const AABB   &a) { return iTest(a, b); }
CollisionData iTest(const Ray    &b, const AABB   &a) { return iTest(a, b); }

CollisionData iTest(const Plane  &b, const Circle &a) { return iTest(a, b); }
CollisionData iTest(const Ray    &b, const Circle &a) { return iTest(a, b); }

CollisionData iTest(const Plane  &b, const Ray    &a) { return iTest(a, b); }

CollisionData iTest(const Circle &b, const ConvexHull &A) { return iTest(A, b); }
CollisionData iTest(const Ray    &b, const ConvexHull &A) { return iTest(A, b); }
CollisionData iTest(const Plane  &b, const ConvexHull &A) { return iTest(A, b); }
CollisionData iTest(const AABB   &b, const ConvexHull &A) { return iTest(A, b); }