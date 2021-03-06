#pragma once
#include "Vector2.h"
#include "Matrix3.h"
#include <vector>

//Different shapes of varying utility.

// note that this isn't guaranteed to be a convex hull- needs an algorithm to test it.
struct ConvexHull { std::vector<Vector2> verts;                  };
struct Ray        { Vector2 position, direction; float length;   };
struct Plane      { Vector2 position, normal;                    };
struct Circle     { Vector2 position; float radius;              };
struct AABB       { Vector2 position, halfextents,  min() const, max() const; };

//Useful for taking a gameobject's transform and applying it to a shape for collision detection
AABB        operator*(const Matrix3 &m, const AABB       &a);
Circle      operator*(const Matrix3 &m, const Circle     &a);
Ray         operator*(const Matrix3 &m, const Ray        &a);
Plane       operator*(const Matrix3 &m, const Plane      &a);
ConvexHull  operator*(const Matrix3 &m, const ConvexHull &a);