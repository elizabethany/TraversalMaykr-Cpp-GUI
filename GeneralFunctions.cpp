#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include "GeneralFunctions.h"

// Converts degrees to radians
double degToRad(
    double degree
)
{
    return (degree * M_PI / 180);
}

// Turns the pitch, yaw, and roll that you input, into mat3 values
std::vector<double> angle_to_mat3(
    double pitch,
    double yaw,
    double roll
)
{
    double sy = sin(degToRad(yaw));
    double cy = cos(degToRad(yaw));
    double sp = sin(degToRad(pitch));
    double cp = cos(degToRad(pitch));
    double sr = sin(degToRad(roll));
    double cr = cos(degToRad(roll));

    double mat0X = cp * cy;
    double mat0Y = cp * sy;
    double mat0Z = -sp;
    double mat1X = sr * sp * cy + cr * -sy;
    double mat1Y = sr * sp * sy + cr * cy;
    double mat1Z = sr * cp;
    double mat2X = cr * sp * cy + -sr * sy;
    double mat2Y = cr * sp * sy + -sr * cy;
    double mat2Z = cr * cp;

    return std::vector<double>{mat0X, mat0Y, mat0Z, mat1X, mat1Y, mat1Z, mat2X, mat2Y, mat2Z};
}

// Reverses direction of given animation, if applicable
std::string animReverser(
    std::string animString
)
{
    if (animString.find("up") != std::string::npos)
    {
        size_t startPoint = animString.find("up");
        animString.replace(startPoint, 2, "down");
    }
    else if (animString.find("down") != std::string::npos)
    {
        size_t startPoint = animString.find("down");
        animString.replace(startPoint, 4, "up");
    }
    return animString;
}

// Removes /traversal or /traversals from the given string
std::string monsterPathTruncater(
    std::string monsterPath
)
{
    if (monsterPath.find("/traversals") != std::string::npos)
    {
        size_t startPoint = monsterPath.find("/traversals");
        monsterPath.replace(startPoint, 11, "");
    }
    else if (monsterPath.find("/traversal") != std::string::npos)
    {
        size_t startPoint = monsterPath.find("/traversal");
        monsterPath.replace(startPoint, 10, "");
    }
    return monsterPath;
}

// Get the animation index for the given monster (index). Animation index determines which set of animations in DEAnimationSets to use.
int getAnimIndex(
    int monsterIndex
)
{
    if (monsterIndex >= 0 && monsterIndex <= 12) // everything else
    {
       return 0;
    }
    else if (monsterIndex >= 16 && monsterIndex <= 21) // baron, hell knight, imp, mancubus, pinky, soldier
    {
        return 1;
    }
    else if (monsterIndex == 13) // arachnotron
    {
        return 2;
    }
    else if (monsterIndex == 14) // wolf
    {
        return 3;
    }
    else if (monsterIndex == 15) // zombie
    {
        return 4;
    }
    else // failsafe, but should not be needed as the UI shouldn't allow monsterIndex to be a value outside of the above bounds
    {
        return 0;
    }
}

// Takes the given text file and turns its contents to a vector
std::vector<std::string> textFileToVector(
    std::string filePath
)
{
    std::ifstream textTemplate(filePath);
    std::vector<std::string> makeVector;
    for (std::string currentLine; std::getline(textTemplate, currentLine);)
    {
        makeVector.push_back(currentLine);
    }
    textTemplate.close();
    return makeVector;
}

// Takes the numbers that were input as a string and turns them into a vector of doubles
std::vector<double> stringToVector(
    std::string inputStr
)
{
    std::vector<double> vectorized;
    std::stringstream tempStream(inputStr);

    double currentStreamItem;
    while (tempStream >> currentStreamItem)
    {
        vectorized.push_back(currentStreamItem);
    }

    return vectorized;
}

// Specify a string, the item to replace, and its replacement
void replaceThisInString(
    std::string& stringThing,
    std::string replaceThis,
    std::string replacement
)
{
    size_t startPoint = stringThing.find(replaceThis);
    size_t endPoint = replaceThis.length();
    stringThing.replace(startPoint, endPoint, replacement);
}

// Write the given thing to the given text file
void writeThisThing(
    std::vector<std::string> thingToWrite,
    std::string filePath
)
{
    std::fstream output(filePath, std::fstream::out | std::fstream::app);
    for (const auto& currentLine : thingToWrite)
    {
       output << "\n" << currentLine;
    }
    output.close();
}

// Returns the given string (number) with up to six zeroes padded at the front
std::string zeroPadded(
    std::string padThis
)
{
    int size = padThis.size();
    if (size < 6)
    {
        std::string tempStr;
        for (int i = 0; i < 6 - size; i++)
        {
            tempStr += "0";
        }
        tempStr += padThis;
        return tempStr;
    }
    else
    {
        return padThis;
    }
}

bool areCoordsValid(const std::string& coordsStr)
{
    std::vector<double> coordsDouble = stringToVector(coordsStr);
    return coordsStr != "" && coordsDouble.size() >= 3;
}
