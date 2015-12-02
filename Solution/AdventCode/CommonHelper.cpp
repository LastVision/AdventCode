#include "stdafx.h"

#include "CommonHelper.h"
#include <string>

CommonHelper::CommonHelper()
{
}

CommonHelper::~CommonHelper()
{
}

std::vector<Vector3f> CommonHelper::ConvertStringVectorToVector3f(const std::vector<std::string>& aStringVector)
{
	std::vector<Vector3f> returnVector;
	Vector3f convertedInput;

	for (int i = 0; i < aStringVector.size(); ++i)
	{
		int firstX = aStringVector[i].find_first_of("x");
		int secondX = aStringVector[i].find_first_of("x", firstX + 1);

		std::string numberText = aStringVector[i].substr(0, firstX);
		convertedInput.x = std::stof(numberText);

		numberText = aStringVector[i].substr(firstX + 1, secondX - firstX - 1);
		convertedInput.y = std::stof(numberText);

		numberText = aStringVector[i].substr(secondX + 1, aStringVector[i].length());
		convertedInput.z = std::stof(numberText);

		returnVector.push_back(convertedInput);
	}
	return returnVector;
}
