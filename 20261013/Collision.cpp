#include "Collision.h"
#include <cmath>

bool CheckSphereTriangle(Vector3 sphereCenter, float sphereRadius, const Polygon& polygon)
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
	//return IsPointsideTriangle(projectedPoint, polygon);
}
