#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#pragma once

double degToRad(
    double degree
);

std::vector<double> angle_to_mat3(
    double pitch,
    double yaw,
    double roll
);

std::string animReverser(
    std::string animString
);

std::string monsterPathTruncater(
    std::string monsterPath
);

int getAnimIndex(
    int monsterIndex
);

std::vector<std::string> textFileToVector(
    std::string filePath
);

std::vector<double> stringToVector(
    std::string inputStr
);

void replaceThisInString(
    std::string& stringThing,
    std::string replaceThis,
    std::string replacement
);

void writeThisThing(
    std::vector<std::string> thingToWrite,
    std::string filePath
);

std::string zeroPadded(
    std::string padThis
);

bool areCoordsValid(
    const std::string& coordsStr,
    int vectorSize = 3
);

void deSpacer(
    std::string &inputStr
);

void renderThis(
    std::vector<std::string>& givenTemplate,
    std::vector<std::pair<std::string, std::string>> arguments
);

#endif // GENERALFUNCTIONS_H
