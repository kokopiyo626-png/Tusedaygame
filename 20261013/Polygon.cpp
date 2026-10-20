#include "Polygon3D.h"
#include "DxLib.h"

//DxLibのVECTORに変換
static VECTOR ToDxVector(Vector3 v) 
{
	return VGet(v.x, v.y, v.z);
}

void Polygon3D::Init() 
{
	//Y=0の表面上に三角形を配置
	a = { -150.0f,0.0f,100.0f };
	b = { 0.0f,0.0f,-150.0f };
	c = { 150.0f,0.0f,100.0f };
}

void Polygon3D::Draw() const 
{
	VERTEX3D vertices[3] = {};

	vertices[0].pos = ToDxVector(a);
	vertices[1].pos = ToDxVector(b);
	vertices[2].pos = ToDxVector(c);

	//各頂点に同じ法線を設定
	VECTOR normal = ToDxVector(GetNormal());

	for (int i = 0; i < 3; i++) 
	{
		vertices[i].norm = normal;
		vertices[i].dif = GetColorU8(80, 180, 255, 255);;
		vertices[i].spc = GetColorU8(0, 0, 0, 0);
		vertices[i].u = 0.0f;
		vertices[i].v = 0.0f;
		vertices[i].su = 0.0f;
		vertices[i].sv = 0.0f;
	}

	//頂点３つで１枚の三角形ポリゴン描画
	DrawPolygon3D(vertices, 1, DX_NONE_GRAPH, FALSE);
	//頂点を確認できるように点も描画
	DrawSphere3D(ToDxVector(a), 5.0f, 8, GetColor(255, 255, 0), GetColor(255, 255, 0), TRUE);
	DrawSphere3D(ToDxVector(b), 5.0f, 8, GetColor(255, 255, 0), GetColor(255, 255, 0), TRUE);
	DrawSphere3D(ToDxVector(c), 5.0f, 8, GetColor(255, 255, 0), GetColor(255, 255, 0), TRUE);
}

//頂点取得
Vector3 Polygon3D::GetA() const { return a; }
Vector3 Polygon3D::GetB() const { return b; }
Vector3 Polygon3D::GetC() const { return c; }

Vector3 Polygon3D::GetNormal() const 
{
	//頂点AからB、頂点AからCへのベクトル
	Vector3 ab = Subtract(b, a);
	Vector3 ac = Subtract(c, a);

	return Normalize(Cross(ab, ac));
}
