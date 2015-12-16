#include "stdafx.h"

#include "CommonHelper.h"
#include <string>

CommonHelper::CommonHelper()
{
}

CommonHelper::~CommonHelper()
{
}

std::vector<Vector3<float>> CommonHelper::ConvertStringVectorToVector3f(const std::vector<std::string>& aStringVector)
{
	std::vector<Vector3<float>> returnVector;
	Vector3<float> convertedInput(0,0,0);

	for (unsigned int i = 0; i < aStringVector.size(); ++i)
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

int CommonHelper::GetNumberOfVowelsFromString(const std::string& aString)
{
	int numberOfVowles = 0;
	for (int i = 0; i < aString.length(); ++i)
	{
		if (aString[i] == 'a' || aString[i] == 'e' || aString[i] == 'i' 
			|| aString[i] == 'o' || aString[i] == 'u')
		{
			numberOfVowles++;
		}
	}
	return numberOfVowles;
}

bool CommonHelper::HasDoubleLettersInRow(const std::string& aString)
{
	char previousLetter = -1;
	for (int i = 0; i < aString.length(); ++i)
	{
		if (aString[i] == previousLetter)
		{
			return true;
		}
		previousLetter = aString[i];
	}
	return false;
}

bool CommonHelper::HasBannedWords(const std::string& aString, const std::vector<std::string>& someBannedWords)
{
	for (unsigned int i = 0; i < someBannedWords.size(); ++i)
	{
		if (aString.find(someBannedWords[i]) != std::string::npos)
		{
			return true;
		}
	}
	return false;
}