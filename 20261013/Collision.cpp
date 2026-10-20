#include "Collision.h"
#include <cmath>

bool Collision::CheckSphereTriangle(Vector3 sphereCenter, float sphereRadius, const Polygon3D& polygon)const
{
	Vector3 a = polygon.GetA();
	Vector3 normal = polygon.GetNormal();

	//頂点Aから球の中心へのベクトル
	Vector3 ap = Subtract(sphereCenter, a);

	//内積で平面から球の中心までの符号付距離を求める
	float distance = Dot(ap, normal);
	//球が平面から離れすぎている
	if (std::fabs(distance) > sphereRadius) 
	{
		return false;
	}

	Vector3 projectedPoint = {
		sphereCenter.x - normal.x * distance,
		sphereCenter.y - normal.y * distance,
		sphereCenter.z - normal.z * distance
	};
	return IsPointsideTriangle(projectedPoint, polygon);
}

bool Collision::IsPointsideTriangle(Vector3 point, const Polygon3D& polygon)const 
{
	Vector3 a = polygon.GetA();
	Vector3 b = polygon.GetB();
	Vector3 c = polygon.GetC();
	Vector3 normal = polygon.GetNormal();

	Vector3 ab = Subtract(b, a);
	Vector3 ap = Subtract(point, a);

	Vector3 bc = Subtract(c, b);
	Vector3 bp = Subtract(point, b);

	Vector3 ca = Subtract(a, c);
	Vector3 cp = Subtract(point, c);

	float d1 = Dot(Cross(ab, ap), normal);
	float d2 = Dot(Cross(bc, bp), normal);
	float d3 = Dot(Cross(ca, cp), normal);

	const float epsilon = 0.0001f;

	return d1 >= -epsilon
		&& d2 >= -epsilon
		&& d3 >= -epsilon;

}
