#include "stdafx.h"
#include "FileReader.h"
#include "CommonHelper.h"
#include "md5.h"



struct HouseData
{
	HouseData() { myPosition.x = 0; myPosition.y = 0; numberOfPresents = 0; };
	Vector2<int> myPosition;
	int numberOfPresents;
};

void GetRoomNumber(const std::string& aInputString, int& aRoomNumber, int& aFirstCharacterToBasement);
int GetAmountOfPaper(const Vector3<float>& aVector);
int GetAmountOfRibbon(const Vector3<float>& aVector);
void Visit(HouseData aHouse, bool aPlayerOne);

std::vector<HouseData> locHouses;
std::vector<HouseData> locPlayerOneHouses;
std::vector<HouseData> locPlayerTwoHouses;

bool IsGood(std::string aCode, unsigned int numberOfZeroes);

void main()
{
	CommonHelper helper;
	FileReader fileReader("Data/AdventCodeDayFive.txt");
	std::vector<std::string> listOfStrings = fileReader.ReadLines();
	
	int numberOfBadStrings = 0;
	int numberOfNiceStrings = 0;
	
	std::string test = "aabaa";
	std::cout << helper.HasRepeatablePair(test) << std::endl;

	for (unsigned int i = 0; i < listOfStrings.size(); ++i)
	{
		if (helper.HasRepeatablePair(listOfStrings[i]) == true &&
			helper.HasRepeatingLettersWithOneBetween(listOfStrings[i]) == true)
		{
			numberOfNiceStrings++;
		}
		else 
		{
			numberOfBadStrings++;
		}
	}

	std::cout << "There was " << numberOfNiceStrings << " nice strings out of " << listOfStrings.size() << std::endl;
	std::cout << "There was " << numberOfBadStrings << " bad strings." << std::endl;

	system("pause");
}

bool IsGood(std::string aCode, unsigned int numberOfZeroes)
{
	if (aCode.size() > numberOfZeroes)
	{
		for (int i = 0; i < numberOfZeroes; ++i)
		{
			if (aCode[i] != '0')
			{
				return false;
			}
		}
	}
	return true;
}

void Visit(HouseData aHouse, bool)
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