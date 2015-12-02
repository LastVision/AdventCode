#pragma once
#include <vector>

struct Vector2f
{
	float x;
	float y;
};

struct Vector3f
{
	float x;
	float y;
	float z;
};

struct Vector4f
{
	float x;
	float y;
	float z;
	float w;
};

class CommonHelper
{
public:
	CommonHelper();
	~CommonHelper();

	std::vector<Vector3f> ConvertStringVectorToVector3f(const std::vector<std::string>& aStringVector);
};

