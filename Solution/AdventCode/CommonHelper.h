#pragma once
#include <vector>

template <typename T>
struct Vector2
{
	Vector2() : x(0), y(0) {};
	Vector2(T aX, T aY)
		: x(aX), y(aY) {};
	T x;
	T y;
};

template <typename T>
struct Vector3
{
	Vector3() : x(0), y(0), z(0) {};
	Vector3(T aX, T aY, T aZ)
		: x(aX), y(aY), z(aZ) {}
	T x;
	T y;
	T z;
};

template <typename T>
struct Vector4
{
	Vector4() : x(0), y(0), z(0), w(0) {};
	Vector4(T aX, T aY, T aZ, T aW)
		: x(aX), y(aY), z(aZ), w(aW) {}
	T x;
	T y;
	T z;
	T w;
};

class CommonHelper
{
public:
	CommonHelper();
	~CommonHelper();

	std::vector<Vector3<float>> ConvertStringVectorToVector3f(const std::vector<std::string>& aStringVector);
	int GetNumberOfVowelsFromString(const std::string& aString);
	bool HasDoubleLettersInRow(const std::string& aString);
	bool HasBannedWords(const std::string& aString, const std::vector<std::string>& someBannedWords);
};

