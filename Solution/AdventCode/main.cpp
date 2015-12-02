#include "stdafx.h"
#include "FileReader.h"
#include "CommonHelper.h"

void GetRoomNumber(const std::string& aInputString, int& aRoomNumber, int& aFirstCharacterToBasement);
int GetAmountOfPaper(const Vector3f& aVector);
int GetAmountOfRibbon(const Vector3f& aVector);

void main()
{
	FileReader reader("Data/AdventCodeDayTwo.txt");
	CommonHelper helper;

	std::vector<Vector3f> vectorContainer = helper.ConvertStringVectorToVector3f(reader.ReadLines());

	int totalAmountOfPaper = 0;
	int totalAmountOfRibbon = 0;
	for (int i = 0; i < vectorContainer.size(); ++i)
	{
		totalAmountOfPaper += GetAmountOfPaper(vectorContainer[i]);
		totalAmountOfRibbon += GetAmountOfRibbon(vectorContainer[i]);
	}

	std::cout << "Amount of paper needed " << totalAmountOfPaper << std::endl;
	std::cout << "Amount of ribbon needed " << totalAmountOfRibbon << std::endl;

	system("pause");
}

void GetRoomNumber(const std::string& aInputString, int& aRoomNumber, int& aFirstCharacterToBasement)
{
	bool hasBeenInBasement = false;
	for (int i = 0; i < aInputString.length(); ++i)
	{
		if (hasBeenInBasement == false && aRoomNumber < 0)
		{
			aFirstCharacterToBasement = i;
			hasBeenInBasement = true;
		}
		if (aInputString[i] == '(')
		{
			aRoomNumber++;
		}
		else if (aInputString[i] == ')')
		{
			aRoomNumber--;
		}
	}
}

int GetAmountOfPaper(const Vector3f& aVector)
{
	int firstSurfaceArea = aVector.x * aVector.y;
	int secondSurfaceArea = aVector.y * aVector.z;
	int thirdSurfaceArea = aVector.x * aVector.z;
	int extraPaper = 0;
	if (firstSurfaceArea <= secondSurfaceArea && firstSurfaceArea <= thirdSurfaceArea) extraPaper = firstSurfaceArea;
	if (secondSurfaceArea <= firstSurfaceArea && secondSurfaceArea <= thirdSurfaceArea) extraPaper = secondSurfaceArea;
	if (thirdSurfaceArea <= firstSurfaceArea && thirdSurfaceArea <= secondSurfaceArea) extraPaper = thirdSurfaceArea;

	return ((2 * firstSurfaceArea) + (2 * secondSurfaceArea) + (2 * thirdSurfaceArea)) + extraPaper;
}

int GetAmountOfRibbon(const Vector3f& aVector)
{
	int firstFace = 0;
	int secondFace = 0;
	int extraRibbon = aVector.x * aVector.y * aVector.z;

	if (aVector.x <= aVector.y && aVector.x <= aVector.z)
	{
		firstFace = aVector.x;
		if (aVector.y <= aVector.z) secondFace = aVector.y;
		else secondFace = aVector.z;
	}
	else if (aVector.y <= aVector.x && aVector.y <= aVector.z)
	{
		firstFace = aVector.y;
		if (aVector.x <= aVector.z) secondFace = aVector.x;
		else secondFace = aVector.z;
	}
	else if (aVector.z <= aVector.x && aVector.z <= aVector.y)
	{
		firstFace = aVector.z;
		if (aVector.x <= aVector.y) secondFace = aVector.x;
		else secondFace = aVector.y;
	}

	return (firstFace + firstFace + secondFace + secondFace) + extraRibbon;
}