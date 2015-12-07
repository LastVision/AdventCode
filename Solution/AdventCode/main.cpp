#include "stdafx.h"
#include "FileReader.h"
#include "CommonHelper.h"

struct HouseData
{
	HouseData() { myPosition.x = 0; myPosition.y = 0; numberOfPresents = 0; };
	Vector2<int> myPosition;
	int numberOfPresents;
};

void GetRoomNumber(const std::string& aInputString, int& aRoomNumber, int& aFirstCharacterToBasement);
int GetAmountOfPaper(const Vector3<float>& aVector);
int GetAmountOfRibbon(const Vector3<float>& aVector);
void Visit(HouseData aHouse);

std::vector<HouseData> locHouses;


void main()
{
	FileReader reader("Data/AdventCodeDayThree.txt");
	CommonHelper helper;

	std::string path = reader.ReadAll();

	HouseData currentHouse;
	currentHouse.myPosition.x = 0;
	currentHouse.myPosition.y = 0;
	currentHouse.numberOfPresents = 0;
	Visit(currentHouse);
	for (unsigned int i = 0; i < path.length(); ++i)
	{
		if (path[i] == '<')
		{
			currentHouse.myPosition.x--;
		}
		else if (path[i] == '>')
		{
			currentHouse.myPosition.x++;
		}
		else if (path[i] == '^')
		{
			currentHouse.myPosition.y++;
		}
		else if (path[i] == 'v')
		{
			currentHouse.myPosition.y--;
		}
		Visit(currentHouse);
	}

	std::cout << "Houses visited: " << locHouses.size() << std::endl;

	system("pause");
}

void Visit(HouseData aHouse)
{
	for (unsigned int i = 0; i < locHouses.size(); ++i)
	{
		if (aHouse.myPosition.x == locHouses[i].myPosition.x && 
			aHouse.myPosition.y == locHouses[i].myPosition.y)
		{
			locHouses[i].numberOfPresents++;
			return;
		}
	}
	aHouse.numberOfPresents += 1;
	locHouses.push_back(aHouse);
}

void GetRoomNumber(const std::string& aInputString, int& aRoomNumber, int& aFirstCharacterToBasement)
{
	bool hasBeenInBasement = false;
	for (unsigned int i = 0; i < aInputString.length(); ++i)
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

int GetAmountOfPaper(const Vector3<float>& aVector)
{
	int firstSurfaceArea = static_cast<int>(aVector.x * aVector.y);
	int secondSurfaceArea = static_cast<int>(aVector.y * aVector.z);
	int thirdSurfaceArea = static_cast<int>(aVector.x * aVector.z);
	int extraPaper = 0;
	if (firstSurfaceArea <= secondSurfaceArea && firstSurfaceArea <= thirdSurfaceArea) extraPaper = firstSurfaceArea;
	if (secondSurfaceArea <= firstSurfaceArea && secondSurfaceArea <= thirdSurfaceArea) extraPaper = secondSurfaceArea;
	if (thirdSurfaceArea <= firstSurfaceArea && thirdSurfaceArea <= secondSurfaceArea) extraPaper = thirdSurfaceArea;

	return ((2 * firstSurfaceArea) + (2 * secondSurfaceArea) + (2 * thirdSurfaceArea)) + extraPaper;
}

int GetAmountOfRibbon(const Vector3<float>& aVector)
{
	float firstFace = 0;
	float secondFace = 0;
	int extraRibbon = static_cast<int>(aVector.x * aVector.y * aVector.z);

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

	return static_cast<int>(firstFace + firstFace + secondFace + secondFace) + extraRibbon;
}