#ifndef ENTITYGENERATINGFUNCTIONS_H
#define ENTITYGENERATINGFUNCTIONS_H
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include "EntityClasses.h"
#pragma once

void generateInfoTraversal(
    int entityNum,
    std::vector<double> startCoords,
    std::vector<double> endCoords,
    std::vector<int> monsterIndices,
    int animIndex,
    bool reciprocalTraversal
);

void generateHangout(
    std::vector<std::string> hangoutTemplate,
    std::vector<idInfo_TraversalChain_Hang> entityObjects,
    idInfo_TraversalPoint finalEntity
);

void generateTraversalChain(
    std::vector<idInfo_TraversalChain_General> entityObjects,
    idInfo_TraversalPoint finalEntity,
    std::vector<int> monsterIndices,
    bool reciprocalTraversal
);

void generateInfoPath(
    std::vector<idInfoPath> entityObjects
);

#endif // ENTITYGENERATINGFUNCTIONS_H
