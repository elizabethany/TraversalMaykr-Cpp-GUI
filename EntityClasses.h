#ifndef ENTITYCLASSES_H
#define ENTITYCLASSES_H
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#pragma once

// Base entity class, with relevant common parameters
class idEntity{
public:
    std::string entityName;
    std::vector<double> coordinates;
};

class idInfoTraversal : public idEntity{
public:
    std::vector<double> endCoordinates;
    int animationIndex;
};

// idInfo_TraversalPoint, in case anything needs to be added in the future
class idInfo_TraversalPoint : public idEntity{
};

// idInfo_TraversalChain for demon specific traversal chains
class idInfo_TraversalChain_Hang : public idEntity{
public:
    std::string linkAnimation;
    std::string idleAnimation;
};

// idInfo_TraversalChain for general traversal chains
class idInfo_TraversalChain_General : public idEntity{
public:
    int animationIndex;
};

// idInfoPath
class idInfoPath : public idEntity{
public:
    std::string walkState;
    std::string navSize;
};

#endif // ENTITYCLASSES_H
