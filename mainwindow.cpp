#include "mainwindow.h"
#include "ui_mainwindow.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>

/*
    GLOBAL VARIABLES
*/

// pm_NormalViewHeight, using default value
static const double DEpmNormalViewHeight = 1.65735;

// Set 1 is for all monsters not listed below
static const std::vector<std::string> animationSet1 = { "ledge_up_100", "ledge_up_200", "ledge_up_300", "ledge_up_400", "ledge_up_500", "ledge_up_700", "ledge_up_1000", "ledge_down_100", "ledge_down_200", "ledge_down_300", "ledge_down_400", "ledge_down_500", "ledge_down_700", "ledge_down_1000", "rail_down_100", "rail_down_200", "rail_down_300", "rail_down_400", "rail_down_500", "rail_down_700", "rail_down_1000", "rail_up_100", "rail_up_200", "rail_up_300", "rail_up_400", "rail_up_500", "rail_up_700", "rail_up_1000", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_1000", "jump_forward_300_down_300", "jump_forward_300_down_500", "jump_forward_300_up_300", "jump_forward_300_up_500", "jump_forward_500_down_300", "jump_forward_500_down_500", "jump_forward_500_up_300", "jump_forward_500_up_500", "jump_forward_1000_down_1000", "jump_forward_1000_up_1000" };
// Set 2 is for the Baron, Hell Knight, Imp, Mancubus, Pinky, and Soldier
static const std::vector<std::string> animationSet2 = { "jump_ledge_up_100", "jump_ledge_up_200", "jump_ledge_up_300", "jump_ledge_up_400", "jump_ledge_up_500", "jump_ledge_up_700", "jump_ledge_up_1000", "jump_ledge_down_100", "jump_ledge_down_200", "jump_ledge_down_300", "jump_ledge_down_400", "jump_ledge_down_500", "jump_ledge_down_700", "jump_ledge_down_1000", "jump_rail_down_100", "jump_rail_down_200", "jump_rail_down_300", "jump_rail_down_400", "jump_rail_down_500", "jump_rail_down_700", "jump_rail_down_1000", "jump_rail_up_100", "jump_rail_up_200", "jump_rail_up_300", "jump_rail_up_400", "jump_rail_up_500", "jump_rail_up_700", "jump_rail_up_1000", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_1000", "jump_forward_300_down_300", "jump_forward_300_down_500", "jump_forward_300_up_300", "jump_forward_300_up_500", "jump_forward_500_down_300", "jump_forward_500_down_500", "jump_forward_500_up_300", "jump_forward_500_up_500", "jump_forward_1000_down_1000", "jump_forward_1000_up_1000" };
// Set 3 is for the Marauder Wolf
static const std::vector<std::string> animationSet3 = { "ledge_up_100", "ledge_up_200", "ledge_up_300", "ledge_up_400", "ledge_up_500", "ledge_up_700", "ledge_up_1000", "ledge_down_100", "ledge_down_200", "ledge_down_300", "ledge_down_400", "ledge_down_500", "ledge_down_700", "ledge_down_1000", "rail_down_100", "rail_down_200", "rail_down_300", "rail_down_400", "rail_down_500", "rail_down_700", "rail_down_1000", "rail_up_100", "rail_up_200", "rail_up_300", "rail_up_400", "rail_up_500", "rail_up_700", "rail_up_1000", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_1000", "ledge_forward_300_down_300", "ledge_forward_300_down_500", "ledge_forward_300_up_300", "ledge_forward_300_up_500", "ledge_forward_500_down_300", "ledge_forward_500_down_500", "ledge_forward_500_up_300", "ledge_forward_500_up_500", "ledge_forward_1000_down_1000", "ledge_forward_1000_up_1000" };
// Set 4 is for the Arachnotron
static const std::vector<std::string> animationSet4 = { "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "", "", "", "", "", "", "", "", "", "" };
// Set 5 is for the Zombie
static const std::vector<std::string> animationSet5 = { "ledge_up_100", "ledge_up_200", "ledge_up_300", "ledge_up_400", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_down_100", "ledge_down_200", "ledge_down_300", "ledge_down_400", "ledge_down_500", "ledge_down_700", "ledge_down_1000", "rail_down_100", "rail_down_200", "rail_down_300", "rail_down_400", "rail_down_500", "rail_down_700", "rail_down_1000", "rail_up_100", "rail_up_200", "rail_up_300", "rail_up_400", "rail_up_500", "rail_up_500", "rail_up_500", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_700", "jump_forward_300_down_300", "jump_forward_300_down_500", "jump_forward_300_up_300", "jump_forward_300_up_500", "jump_forward_500_down_300", "jump_forward_500_down_500", "jump_forward_500_up_300", "jump_forward_500_up_500", "jump_forward_1000_down_1000", "jump_forward_500_up_500" };
static const std::vector<std::vector<std::string>> DEAnimationSets = { animationSet1, animationSet2, animationSet3, animationSet4, animationSet5 };

// Various items to substitute in the templates, depending on the monster type you picked
static const std::vector<std::string> DEMonsterNames = { "archvile", "blood_maykr", "carcass", "doom_hunter", "dread_knight", "gargoyle", "marauder", "prowler", "revenant", "tyrant", "whiplash", "maykr_drone", "mecha_zombie", "arachnatron", "wolf", "zombie", "baron", "hell_knight", "imp", "mancubus", "pinky", "soldier" };
static const std::vector<std::string> DEMonsterTypes = { "TRAVERSALMONSTERTYPE_ARCHVILE", "TRAVERSALMONSTERTYPE_BLOOD_ANGEL", "TRAVERSALMONSTERTYPE_CARCASS", "TRAVERSALMONSTERTYPE_DOOM_HUNTER", "TRAVERSALMONSTERTYPE_DREADKNIGHT", "TRAVERSALMONSTERTYPE_GARGOYLE", "TRAVERSALMONSTERTYPE_MARAUDER", "TRAVERSALMONSTERTYPE_PROWLER", "TRAVERSALMONSTERTYPE_REVENANT", "TRAVERSALMONSTERTYPE_TYRANT", "TRAVERSALMONSTERTYPE_WHIPLASH", "TRAVERSALMONSTERTYPE_ZOMBIE_MAYKR", "TRAVERSALMONSTERTYPE_ZOMBIE_T3", "TRAVERSALMONSTERTYPE_ARACHNATRON", "TRAVERSALMONSTERTYPE_MARAUDER_WOLF", "TRAVERSALMONSTERTYPE_ZOMBIE", "TRAVERSALMONSTERTYPE_BARON", "TRAVERSALMONSTERTYPE_HELLKNIGHT", "TRAVERSALMONSTERTYPE_IMP", "TRAVERSALMONSTERTYPE_MANCUBUS", "TRAVERSALMONSTERTYPE_PINKY", "TRAVERSALMONSTERTYPE_HELLIFIED_SOLDIER" };
static const std::vector<std::string> DEMonsterPaths = { "archvile/traversal", "bloodangel/traversal", "carcass/traversal", "doomhunter/traversal", "dreadknight/traversal", "gargoyle/traversal", "marauder/traversals", "prowler/traversal", "revenant/traversals", "tyrant/traversal", "whiplash/traversal", "zombie_maykr/traversal", "zombie_tier_3/traversal", "arachnotron/traversal", "marauder_wolf/traversals", "zombie_tier_1/traversal", "baron/traversal", "hellknight/traversal", "imp/traversal",    "mancubus_fire/traversal", "pinky/traversal", "soldier_blaster/traversal" };

// Quick int to char (to string) conversion
static const std::vector<std::string> numToLetterStr = { "0", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };

// To populate drown down menus with available animations
static const QStringList dropDownAnimations = { "ledge_up_100", "ledge_up_200", "ledge_up_300", "ledge_up_400", "ledge_up_500", "ledge_up_700", "ledge_up_1000", "ledge_down_100", "ledge_down_200", "ledge_down_300", "ledge_down_400", "ledge_down_500", "ledge_down_700", "ledge_down_1000", "rail_down_100", "rail_down_200", "rail_down_300", "rail_down_400", "rail_down_500", "rail_down_700", "rail_down_1000", "rail_up_100", "rail_up_200", "rail_up_300", "rail_up_400", "rail_up_500", "rail_up_700", "rail_up_1000", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_1000", "jump_forward_300_down_300", "jump_forward_300_down_500", "jump_forward_300_up_300", "jump_forward_300_up_500", "jump_forward_500_down_300", "jump_forward_500_down_500", "jump_forward_500_up_300", "jump_forward_500_up_500", "jump_forward_1000_down_1000", "jump_forward_1000_up_1000" };

std::vector<int> tempAnimList;

// For Dedicated Traversal Chain tab
static const QStringList linkAnimationsArachnotron_Q = { "ceiling_hangout/floor_to_ceiling", "ceiling_hangout/ceiling_to_floor", "ceiling_hangout/ceiling_to_wall_center", "ceiling_hangout/ceiling_to_wall_left", "ceiling_hangout/ceiling_to_wall_right", "wall_hangout/floor_to_wall", "wall_hangout/wall_to_ceiling", "wall_hangout/wall_to_floor", "traversal/jump_forward_100", "traversal/jump_forward_1000", "traversal/jump_forward_200", "traversal/jump_forward_2000", "traversal/jump_forward_300", "traversal/jump_forward_400", "traversal/jump_forward_500", "traversal/jump_forward_700", "traversal/ledge_down_100", "traversal/ledge_down_1000", "traversal/ledge_down_200", "traversal/ledge_down_300", "traversal/ledge_down_400", "traversal/ledge_down_500", "traversal/ledge_down_700", "traversal/ledge_forward_1000_down_1000", "traversal/ledge_forward_1000_up_1000", "traversal/ledge_forward_300_down_300", "traversal/ledge_forward_300_down_500", "traversal/ledge_forward_300_up_300", "traversal/ledge_forward_300_up_500", "traversal/ledge_forward_500_down_300", "traversal/ledge_forward_500_down_500", "traversal/ledge_forward_500_up_300", "traversal/ledge_forward_500_up_500", "traversal/ledge_up_100", "traversal/ledge_up_1000", "traversal/ledge_up_200", "traversal/ledge_up_300", "traversal/ledge_up_400", "traversal/ledge_up_500", "traversal/ledge_up_700", "traversal/rail_down_100", "traversal/rail_down_1000", "traversal/rail_down_200", "traversal/rail_down_300", "traversal/rail_down_400", "traversal/rail_down_500", "traversal/rail_down_700", "traversal/rail_up_100", "traversal/rail_up_1000", "traversal/rail_up_200", "traversal/rail_up_300", "traversal/rail_up_400", "traversal/rail_up_500", "traversal/rail_up_700", "traversal/window_forward_700_up_200", "traversal/window_forward_700_up_300", "traversal/window_forward_700_up_500", "traversal/window_forward_800_up_500" };
static const QStringList idleAnimationsArachnotron_Q = { "NONE", "ceiling_hangout/ceiling_idle", "wall_hangout/idle", "traversal/to_idle" };
static const QStringList linkAnimationsImp = { "wallclimbright/wcr_climb_right_250_wcr", "wallclimbright/wcr_jump_down_right_250", "wallclimbleft/wcl_climb_left_250_wcl", "wallclimbleft/wcl_jump_down_left_250", "wallclimb/wc_climb_250_wc", "wallclimb/wc_into_wl", "wallclimb/wc_into_wr", "wallclimb/wc_jump_back_1000_wc", "wallclimb/wc_jump_back_500", "wallclimb/wc_jump_back_500_wc", "wallclimb/wc_jump_back_down_250", "wallclimb/wc_jump_back_down_500", "wallclimb/wc_jump_left_down_250", "wallclimb/wc_jump_right_down_250", "wallclimbdown/wcd_climb_down45_250_wcd", "wallclimbdown/wcd_climb_down_250_wcd", "wallclimbdown/wcd_hang_down_drop_750", "wallclimbdown/wcd_jump_down_250" };
static const QStringList idleAnimationsImp = { "NONE", "wallclimb_hangout/idle", "upright_hangout/idle", "perch/pch_idle_pch" };


/*
    CLASSES
*/

class idInfo_Traversal_X{
public:
    std::string entityName;
    std::vector<double> coordinates;
};

class idInfo_TraversalPoint : public idInfo_Traversal_X{
};

class idInfo_TraversalChain_Hang : public idInfo_Traversal_X{
public:
    std::string linkAnimation;
    std::string idleAnimation;
};

class idInfo_TraversalChain_General : public idInfo_Traversal_X{
public:
    int animationIndex;
};

/*
    GENERAL FUNCTIONS
*/

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

/*
    ENTITY GENERATING FUNCTIONS
*/

// Create idInfoTraversal entities for the given inputs and writes them to their output
void generateInfoTraversal(
    int entityNum,
    std::vector<double> startCoords,
    std::vector<double> endCoords,
    std::vector<int> monsterIndices,
    int animIndex,
    bool reciprocalTraversal
)
{
    static const std::vector<std::string> infoTraversalTemplate = textFileToVector("Templates/Traversal Info/InfoTraversal.txt");

    for (const auto& monsterIndex : monsterIndices)
    {
        std::vector<std::string> generatedEntity = infoTraversalTemplate;

        std::string entityNumStr = zeroPadded(std::to_string(entityNum));

        const int animSetIndex = getAnimIndex(monsterIndex);

        const auto startX = std::to_string(startCoords.at(0));
        const auto startY = std::to_string(startCoords.at(1));
        const auto startZ = std::to_string(startCoords.at(2) - DEpmNormalViewHeight);
        const auto endX = std::to_string(endCoords.at(0) - startCoords.at(0));
        const auto endY = std::to_string(endCoords.at(1) - startCoords.at(1));
        const auto endZ = std::to_string((endCoords.at(2) - DEpmNormalViewHeight) - (startCoords.at(2) - DEpmNormalViewHeight));
        const std::string animation = DEAnimationSets.at(animSetIndex).at(animIndex);
        const std::string monsterName = DEMonsterNames.at(monsterIndex);
        const std::string monsterPath = DEMonsterPaths.at(monsterIndex);
        const std::string monsterType = DEMonsterTypes.at(monsterIndex);

        replaceThisInString((generatedEntity).at(1), "{{{entityNum}}}", entityNumStr);
        replaceThisInString((generatedEntity).at(1), "{{{monsterName}}}", monsterName);
        replaceThisInString((generatedEntity).at(9), "{{{monsterPath}}}", monsterPath);
        replaceThisInString((generatedEntity).at(9), "{{{animation}}}", animation);
        replaceThisInString((generatedEntity).at(10), "{{{monsterType}}}", monsterType);
        replaceThisInString((generatedEntity).at(13), "{{{startX}}}", startX);
        replaceThisInString((generatedEntity).at(14), "{{{startY}}}", startY);
        replaceThisInString((generatedEntity).at(15), "{{{startZ}}}", startZ);
        replaceThisInString((generatedEntity).at(18), "{{{endX}}}", endX);
        replaceThisInString((generatedEntity).at(19), "{{{endY}}}", endY);
        replaceThisInString((generatedEntity).at(20), "{{{endZ}}}", endZ);

        writeThisThing(generatedEntity, "DE Generated Info Traversals.txt");

        if (reciprocalTraversal)
        {
            std::vector<std::string> generatedEntity_r = infoTraversalTemplate;
            entityNumStr.append("_r");
            const auto startX_r = std::to_string(endCoords.at(0));
            const auto startY_r = std::to_string(endCoords.at(1));
            const auto startZ_r = std::to_string(endCoords.at(2) - DEpmNormalViewHeight);
            const auto endX_r = std::to_string(startCoords.at(0) - endCoords.at(0));
            const auto endY_r = std::to_string(startCoords.at(1) - endCoords.at(1));
            const auto endZ_r = std::to_string((startCoords.at(2) - DEpmNormalViewHeight) - (endCoords.at(2) - DEpmNormalViewHeight));
            const std::string animation_r = animReverser(animation);

            replaceThisInString((generatedEntity_r).at(1), "{{{entityNum}}}", entityNumStr);
            replaceThisInString((generatedEntity_r).at(1), "{{{monsterName}}}", monsterName);
            replaceThisInString((generatedEntity_r).at(9), "{{{monsterPath}}}", monsterPath);
            replaceThisInString((generatedEntity_r).at(9), "{{{animation}}}", animation_r);
            replaceThisInString((generatedEntity_r).at(10), "{{{monsterType}}}", monsterType);
            replaceThisInString((generatedEntity_r).at(13), "{{{startX}}}", startX_r);
            replaceThisInString((generatedEntity_r).at(14), "{{{startY}}}", startY_r);
            replaceThisInString((generatedEntity_r).at(15), "{{{startZ}}}", startZ_r);
            replaceThisInString((generatedEntity_r).at(18), "{{{endX}}}", endX_r);
            replaceThisInString((generatedEntity_r).at(19), "{{{endY}}}", endY_r);
            replaceThisInString((generatedEntity_r).at(20), "{{{endZ}}}", endZ_r);

            writeThisThing(generatedEntity_r, "DE Generated Info Traversals.txt");
        }
    }
}

void generateHangout(
    std::vector<std::string> hangoutTemplate,
    std::vector<idInfo_TraversalChain_Hang> entityObjects,
    idInfo_TraversalPoint finalEntity
)
{
    static const std::vector<std::string> hangoutEndTemplate = textFileToVector("Templates/Traversal Chain/TraversalPoint.txt");

    for (int i = 0; i < entityObjects.size(); i++)
    {
        std::vector<std::string> currentEntity = hangoutTemplate;

        auto entityName = entityObjects[i].entityName;

        auto entityX = std::to_string(entityObjects[i].coordinates[0]);
        auto entityY = std::to_string(entityObjects[i].coordinates[1]);
        auto entityZ = std::to_string(entityObjects[i].coordinates[2] - DEpmNormalViewHeight);

        const auto pitchYawRoll = angle_to_mat3(0, entityObjects[i].coordinates[3], 0);
        const auto mat0X = std::to_string(pitchYawRoll[0]);
        const auto mat0Y = std::to_string(pitchYawRoll[1]);
        const auto mat0Z = std::to_string(pitchYawRoll[2]);
        const auto mat1X = std::to_string(pitchYawRoll[3]);
        const auto mat1Y = std::to_string(pitchYawRoll[4]);
        const auto mat1Z = std::to_string(pitchYawRoll[5]);
        const auto mat2X = std::to_string(pitchYawRoll[6]);
        const auto mat2Y = std::to_string(pitchYawRoll[7]);
        const auto mat2Z = std::to_string(pitchYawRoll[8]);

        std::string nextTargetName;
        // Check if this is the last object in the vector. If it is, make the target the endpoint. If not, make the target the next object in the vector.
        if (i == entityObjects.size() - 1)
            nextTargetName = finalEntity.entityName;
        else
            nextTargetName = entityObjects[i+1].entityName;

        auto linkAnimation = entityObjects[i].linkAnimation;
        auto idleAnimation = entityObjects[i].idleAnimation;

        replaceThisInString(currentEntity[1], "{{{ENTITY_NAME}}}", entityName);
        replaceThisInString(currentEntity[12], "{{{COORDX}}}", entityX);
        replaceThisInString(currentEntity[13], "{{{COORDY}}}", entityY);
        replaceThisInString(currentEntity[14], "{{{COORDZ}}}", entityZ);
        replaceThisInString(currentEntity[19], "{{{MAT0X}}}", mat0X);
        replaceThisInString(currentEntity[20], "{{{MAT0Y}}}", mat0Y);
        replaceThisInString(currentEntity[21], "{{{MAT0Z}}}", mat0Z);
        replaceThisInString(currentEntity[24], "{{{MAT1X}}}", mat1X);
        replaceThisInString(currentEntity[25], "{{{MAT1Y}}}", mat1Y);
        replaceThisInString(currentEntity[26], "{{{MAT1Z}}}", mat1Z);
        replaceThisInString(currentEntity[29], "{{{MAT2X}}}", mat2X);
        replaceThisInString(currentEntity[30], "{{{MAT2Y}}}", mat2Y);
        replaceThisInString(currentEntity[31], "{{{MAT2Z}}}", mat2Z);
        replaceThisInString(currentEntity[39], "{{{NEXT_TARGET_NAME}}}", nextTargetName);
        replaceThisInString(currentEntity[40], "{{{LINK_ANIMATION}}}", linkAnimation);
        replaceThisInString(currentEntity[43], "{{{IDLE_ANIMATION}}}", idleAnimation);

        writeThisThing(currentEntity, "DE Generated Hangouts.txt");
    }

    std::vector<std::string> lastEntity = hangoutEndTemplate;

    replaceThisInString(lastEntity[1], "{{{ENTITY_NAME}}}", finalEntity.entityName);
    replaceThisInString(lastEntity[10], "{{{COORDX}}}", std::to_string(finalEntity.coordinates[0]));
    replaceThisInString(lastEntity[11], "{{{COORDY}}}", std::to_string(finalEntity.coordinates[1]));
    replaceThisInString(lastEntity[12], "{{{COORDZ}}}", std::to_string(finalEntity.coordinates[2] - DEpmNormalViewHeight));
    writeThisThing(lastEntity, "DE Generated Hangouts.txt");
}

void generateTraversalChain(
    std::vector<idInfo_TraversalChain_General> entityObjects,
    idInfo_TraversalPoint finalEntity,
    std::vector<int> monsterIndices,
    bool reciprocalTraversal
)
{
    static const std::vector<std::string> TraversalPointTemplate = textFileToVector("Templates/Traversal Chain/TraversalPoint.txt");

    // Generate the end point first, since there will only be one instance of it
    std::vector<std::string> lastEntity = TraversalPointTemplate;
    replaceThisInString(lastEntity[1], "{{{ENTITY_NAME}}}", finalEntity.entityName);
    replaceThisInString(lastEntity[10], "{{{COORDX}}}", std::to_string(finalEntity.coordinates[0]));
    replaceThisInString(lastEntity[11], "{{{COORDY}}}", std::to_string(finalEntity.coordinates[1]));
    replaceThisInString(lastEntity[12], "{{{COORDZ}}}", std::to_string(finalEntity.coordinates[2] - DEpmNormalViewHeight));
    writeThisThing(lastEntity, "DE Generated Traversal Chains.txt");

    // Generate reverse end point
    std::vector<std::string> lastEntity_r = TraversalPointTemplate;
    idInfo_TraversalChain_General finalObject_r = entityObjects[0];
    finalObject_r.entityName = finalEntity.entityName + "_r";

    replaceThisInString(lastEntity_r[1], "{{{ENTITY_NAME}}}", finalObject_r.entityName);
    replaceThisInString(lastEntity_r[10], "{{{COORDX}}}", std::to_string(finalObject_r.coordinates[0]));
    replaceThisInString(lastEntity_r[11], "{{{COORDY}}}", std::to_string(finalObject_r.coordinates[1]));
    replaceThisInString(lastEntity_r[12], "{{{COORDZ}}}", std::to_string(finalObject_r.coordinates[2] - DEpmNormalViewHeight));
    writeThisThing(lastEntity_r, "DE Generated Traversal Chains.txt");

    std::string reverse;
    if (reciprocalTraversal)
        reverse = "2";
    else
        reverse = "1";

    // Copy of traversal chain objects, but in reverse
    std::vector<idInfo_TraversalChain_General> entityObjects_r(entityObjects.rbegin(), entityObjects.rend());

    static const std::vector<std::string> TraversalChainTemplate = textFileToVector("Templates/Traversal Chain/TraversalChain.txt");

    for (const auto& monsterIndex : monsterIndices)
    {
        const int animSetIndex = getAnimIndex(monsterIndex);

        const auto monsterName = DEMonsterNames.at(monsterIndex);
        const auto monsterPath = DEMonsterPaths.at(monsterIndex);
        const auto monsterType = DEMonsterTypes.at(monsterIndex);
        const auto animWeb = monsterPathTruncater(monsterPath);

        for (int i = 0; i < entityObjects.size(); i++)
        {
            std::vector<std::string> currentEntity = TraversalChainTemplate;

            auto entityName = entityObjects[i].entityName + "_" + monsterName;

            auto entityX = std::to_string(entityObjects[i].coordinates[0]);
            auto entityY = std::to_string(entityObjects[i].coordinates[1]);
            auto entityZ = std::to_string(entityObjects[i].coordinates[2] - DEpmNormalViewHeight);

            auto animation = DEAnimationSets[animSetIndex][entityObjects[i].animationIndex];

            std::string nextTargetName;
            // Check if this is the last object in the vector. If it is, make the target the endpoint. If not, make the target the next object in the vector.
            if (i == entityObjects.size() - 1)
                nextTargetName = finalEntity.entityName;
            else
                nextTargetName = entityObjects[i+1].entityName + "_" + monsterName;

            std::string previousTargetName, animation_r;
            if (i == 0)
            {
                previousTargetName = "";
                animation_r = animation;
            }
            else if (i == 1)
            {
                previousTargetName = finalObject_r.entityName;
                animation_r = animReverser(DEAnimationSets[animSetIndex][entityObjects[i-1].animationIndex]);
            }
            else
            {
                previousTargetName = entityObjects[i-1].entityName + "_" + monsterName;
                animation_r = animReverser(DEAnimationSets[animSetIndex][entityObjects[i-1].animationIndex]);
            }

            replaceThisInString(currentEntity[1], "{{{ENTITY_NAME}}}", entityName);
            replaceThisInString(currentEntity[9], "{{{MONSTERTYPE}}}", monsterType);
            replaceThisInString(currentEntity[10], "{{{ANIMWEB}}}", animWeb);
            replaceThisInString(currentEntity[12], "{{{COORDX}}}", entityX);
            replaceThisInString(currentEntity[13], "{{{COORDY}}}", entityY);
            replaceThisInString(currentEntity[14], "{{{COORDZ}}}", entityZ);

            if (i == 0)
                replaceThisInString(currentEntity[18], "{{{REVERSE}}}", "1");
            else
                replaceThisInString(currentEntity[18], "{{{REVERSE}}}", reverse);

            replaceThisInString(currentEntity[20], "{{{NEXT_TARGET_NAME}}}", nextTargetName);
            replaceThisInString(currentEntity[21], "{{{MONSTER_PATH}}}", monsterPath);
            replaceThisInString(currentEntity[21], "{{{LINK_ANIMATION}}}", animation);
            replaceThisInString(currentEntity[24], "{{{PREVIOUS_TARGET_NAME}}}", previousTargetName);
            replaceThisInString(currentEntity[25], "{{{MONSTER_PATH}}}", monsterPath);
            replaceThisInString(currentEntity[25], "{{{LINK_ANIMATION_R}}}", animation_r);

            writeThisThing(currentEntity, "DE Generated Traversal Chains.txt");
        }

        if (reciprocalTraversal)
        {
            std::vector<std::string> currentEntity_r = TraversalChainTemplate;

            auto entityName_r = entityObjects[entityObjects.size()-1].entityName + "_" + monsterName + "_r";
            auto animation_r = animReverser(DEAnimationSets[animSetIndex][entityObjects[entityObjects.size()-1].animationIndex]);
            auto nextTargetName_r = entityObjects[entityObjects.size()-1].entityName + "_" + monsterName;

            replaceThisInString(currentEntity_r[1], "{{{ENTITY_NAME}}}", entityName_r);
            replaceThisInString(currentEntity_r[9], "{{{MONSTERTYPE}}}", monsterType);
            replaceThisInString(currentEntity_r[10], "{{{ANIMWEB}}}", animWeb);
            replaceThisInString(currentEntity_r[12], "{{{COORDX}}}", std::to_string(finalEntity.coordinates[0]));
            replaceThisInString(currentEntity_r[13], "{{{COORDY}}}", std::to_string(finalEntity.coordinates[1]));
            replaceThisInString(currentEntity_r[14], "{{{COORDZ}}}", std::to_string(finalEntity.coordinates[2] - DEpmNormalViewHeight));
            replaceThisInString(currentEntity_r[18], "{{{REVERSE}}}", "1");
            replaceThisInString(currentEntity_r[20], "{{{NEXT_TARGET_NAME}}}", nextTargetName_r);
            replaceThisInString(currentEntity_r[21], "{{{MONSTER_PATH}}}", monsterPath);
            replaceThisInString(currentEntity_r[21], "{{{LINK_ANIMATION}}}", animation_r);
            replaceThisInString(currentEntity_r[24], "{{{PREVIOUS_TARGET_NAME}}}", "");
            replaceThisInString(currentEntity_r[25], "{{{MONSTER_PATH}}}", monsterPath);
            replaceThisInString(currentEntity_r[25], "{{{LINK_ANIMATION_R}}}", animation_r);

            writeThisThing(currentEntity_r, "DE Generated Traversal Chains.txt");
        }
    }
}


/*
    MAIN WINDOW
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // Set window title
    setWindowTitle("TraversalMaykr-Cpp-GUI v0.2 by elizabethany");

    // Set the traversal info tab as the default
    ui->tabWidgetTraversalEntityTypes->setCurrentIndex(0);

    // For Traversal Info
    ui->demonSelect_19->setChecked(true);
    ui->radioButtonPresetNoneInfo->setChecked(true);
    ui->comboBoxAnimSelect->addItems(dropDownAnimations);
    ui->buttonGenerateTraversal->setEnabled(false); // Disable "generate traversal info" button

    // For Traversal Chain (General)
    ui->demonSelect_19_Chain->setChecked(true);
    ui->radioButtonPresetNoneChain->setChecked(true);
    ui->comboBoxAnimSelectStartChain_2->addItems(dropDownAnimations);
    ui->buttonGenerateTraversalChain->setEnabled(false); // Disable "generate traversal chain" button
    ui->pushButtonAddMidpoint->setEnabled(false); // Disable "add midpoint" button

    // For Traversal Chain (Dedicated)
    ui->comboBox_linkAnimsArachnotron->addItems(linkAnimationsArachnotron_Q);
    ui->comboBox_idleAnimsArachnotron->addItems(idleAnimationsArachnotron_Q);
    ui->comboBox_linkAnimsImp->addItems(linkAnimationsImp);
    ui->comboBox_idleAnimsImp->addItems(idleAnimationsImp);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
    GUI RELATED FUNCTIONS
*/

// Get the inputs, check if they are valid, then calculate the delta values and display them
void getDeltaValues(Ui::MainWindow *ui)
{
    // Get the text and convert them to std strings, then make a copy as vectors
    auto startCoordsStr = ui->inputStartCoords->text().toStdString();
    auto endCoordsStr = ui->inputEndCoords->text().toStdString();
    std::vector<double> startCoordsDouble = stringToVector(startCoordsStr);
    std::vector<double> endCoordsDouble = stringToVector(endCoordsStr);

    // Check if inputs are blank or are less than 3 coordinates
    if (startCoordsStr == "" || endCoordsStr == "" || startCoordsDouble.size() < 3 || endCoordsDouble.size() < 3)
    {
        // Display the values as 0 if the inputs are invalid
        ui->labelValXDelta->setText("0.0000");
        ui->labelValYDelta->setText("0.0000");
        ui->labelValHorDelta->setText("0.0000");
        ui->labelValVerDelta->setText("0.0000");
    }
    else // if the inputs are valid
    {
        // Calculate delta values for each axe plus total horizontal
        double deltaX = endCoordsDouble.at(0) - startCoordsDouble.at(0);
        double deltaY = endCoordsDouble.at(1) - startCoordsDouble.at(1);
        double deltaZ = endCoordsDouble.at(2) - startCoordsDouble.at(2);
        double deltaHor = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

        // Display the delta values, formatted with 4 decimal places
        ui->labelValXDelta->setText(QString::number(deltaX, 'f', 4));
        ui->labelValYDelta->setText(QString::number(deltaY, 'f', 4));
        ui->labelValHorDelta->setText(QString::number(deltaHor, 'f', 4));
        ui->labelValVerDelta->setText(QString::number(deltaZ, 'f', 4));
    }
}

std::vector<int> getMonsterTypesDEInfoTraversal(Ui::MainWindow *ui)
{
    std::vector<int> tempList;
    if (ui->radioButtonPresetNoneInfo->isChecked())
    {
        // Get all monster checkboxes
        auto checkboxes = ui->groupBoxMonsterSelect->findChildren<QCheckBox*>();

        // Look for checked checkboxes
        for (const auto& checkbox: checkboxes)
        {
            if (!checkbox->isChecked())
            {
                continue;
            }

            // Get checkbox name, e.g. "demonSelect_1"
            auto checkboxName = checkbox->objectName().toStdString();

            // Strip everything after the "_" to get the number only
            auto checkboxNumber = checkboxName.substr(checkboxName.find('_') + 1);

            // Convert the number str to int, then substract 1 (0-based)
            int checkboxIndex = std::stoi(checkboxNumber) - 1;

            // Add number to list
            tempList.push_back(checkboxIndex);
        }

        // Sort the list from smallest to biggest (is this needed?)
        std::sort(tempList.begin(), tempList.end());

        return tempList;
    }
    else if (ui->radioButtonPresetFodderInfo->isChecked()) // Fodder
    {
        tempList = {5, 18, 11, 12, 21, 15};
        return tempList;
    }
    else if (ui->radioButtonPresetHeavyInfo->isChecked()) // Heavy
    {
        tempList = {13, 1, 2, 4, 17, 19, 20, 7, 8, 10};
            return tempList;
    }
    else if (ui->radioButtonPresetSuperHeavyInfo->isChecked()) // Super Heavy
    {
        tempList = {0, 16, 3, 6, 9, 14};
        return tempList;
    }
    else if (ui->radioButtonPresetAInfo->isChecked()) // Fodder + Carcass, Prowler, Whiplash, Marauder
    {
        tempList = {5, 18, 11, 12, 21, 15, 2, 7, 10, 6};
        return tempList;
    }
    else if (ui->radioButtonPresetDInfo->isChecked()) // Maykr Drone, Soldier, Prowler, Revenant, Archvile, Doom Hunter
    {
        tempList = {11, 21, 7, 8, 0, 3};
        return tempList;
    }
    else if (ui->radioButtonPresetBInfo->isChecked()) // All sans Tyrant
    {
        tempList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
        return tempList;
    }
    else if (ui->radioButtonPresetCInfo->isChecked()) // All
    {
        tempList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
        return tempList;
    }
    else
    {
        return tempList;
    }
    
}

std::vector<int> getMonsterTypesDETraversalChain(Ui::MainWindow *ui)
{
    std::vector<int> tempList;
    if (ui->radioButtonPresetNoneChain->isChecked())
    {
        // Get all monster checkboxes
        auto checkboxes = ui->groupBoxMonsterSelect_3->findChildren<QCheckBox*>();

        // Look for checked checkboxes
        for (const auto& checkbox: checkboxes)
        {
            if (!checkbox->isChecked())
            {
                continue;
            }

            // Get checkbox name, e.g. "demonSelect_1"
            auto checkboxName = checkbox->objectName().toStdString();

            // Strip everything after the "_" to get the number only
            auto checkboxNumber = checkboxName.substr(checkboxName.find('_') + 1);

            // Convert the number str to int, then substract 1 (0-based)
            int checkboxIndex = std::stoi(checkboxNumber) - 1;

            // Add number to list
            tempList.push_back(checkboxIndex);
        }

        // Sort the list from smallest to biggest (is this needed?)
        std::sort(tempList.begin(), tempList.end());

        return tempList;
    }
    else if (ui->radioButtonPresetFodderChain->isChecked()) // Fodder
    {
        tempList = {5, 18, 11, 12, 21, 15};
        return tempList;
    }
    else if (ui->radioButtonPresetHeavyChain->isChecked()) // Heavy
    {
        tempList = {13, 1, 2, 4, 17, 19, 20, 7, 8, 10};
            return tempList;
    }
    else if (ui->radioButtonPresetSuperHeavyChain->isChecked()) // Super Heavy
    {
        tempList = {0, 16, 3, 6, 9, 14};
        return tempList;
    }
    else if (ui->radioButtonPresetAChain->isChecked()) // Fodder + Carcass, Prowler, Whiplash, Marauder
    {
        tempList = {5, 18, 11, 12, 21, 15, 2, 7, 10, 6};
        return tempList;
    }
    else if (ui->radioButtonPresetDChain->isChecked()) // Maykr Drone, Soldier, Prowler, Revenant, Archvile, Doom Hunter
    {
        tempList = {11, 21, 7, 8, 0, 3};
        return tempList;
    }
    else if (ui->radioButtonPresetBChain->isChecked()) // All sans Tyrant
    {
        tempList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
        return tempList;
    }
    else if (ui->radioButtonPresetCChain->isChecked()) // All
    {
        tempList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
        return tempList;
    }
    else
    {
        return tempList;
    }
    
}

// Clear the output files
void MainWindow::on_buttonClearOutput_clicked() // Traversal Info button
{
    std::fstream output("DE Generated Info Traversals.txt", std::fstream::out);
    output << "";
    output.close();
}
void MainWindow::on_buttonClearOutputChain_clicked() // Traversal Chain button
{
    std::fstream output("DE Generated Traversal Chains.txt", std::fstream::out);
    output << "";
    output.close();
}

// clearCoords
void MainWindow::on_buttonClearCoords_clicked() // Traversal Info button
{
    ui->inputStartCoords->clear();
    ui->inputEndCoords->clear();
}
void MainWindow::on_buttonClearCoordsAndAnims_clicked() // Traversal Chain button
{
    ui->inputMidCoordsChain->clear();
    ui->inputEndCoordsChain->clear();
    ui->listWidgetMidpoints->clear();
    ui->listWidgetMidAnims->clear();
    tempAnimList.clear();
}


bool areCoordsValid(const std::string& coordsStr)
{
    std::vector<double> coordsDouble = stringToVector(coordsStr);
    return coordsStr != "" && coordsDouble.size() >= 3;
}
// Check if the current inputs for the Traversal Info tab are valid
bool isInputValidInfo(Ui::MainWindow *ui)
{
    // Check if the start coords are valid
    bool areStartCoordsValid = areCoordsValid(ui->inputStartCoords->text().toStdString());

    // Check if the end coords are valid
    bool areEndCoordsValid = areCoordsValid(ui->inputEndCoords->text().toStdString());

    // Convert the entity number to int to check if it's valid
    bool isEntityNumberValid;
    ui->inputEntityNum->text().toInt(&isEntityNumberValid);
    isEntityNumberValid = isEntityNumberValid || ui->inputEntityNum->text().isEmpty();

    return areStartCoordsValid && areEndCoordsValid && isEntityNumberValid;
}

// If any input fields for the Traversal Info tab are changed, make sure their inputs are valid
// Also try to get the delta values
void MainWindow::on_inputStartCoords_textChanged(const QString& arg1)
{
    ui->buttonGenerateTraversal->setEnabled(isInputValidInfo(ui));
    getDeltaValues(ui);
}
void MainWindow::on_inputEndCoords_textChanged(const QString& arg1)
{
    ui->buttonGenerateTraversal->setEnabled(isInputValidInfo(ui));
    getDeltaValues(ui);
}
void MainWindow::on_inputEntityNumChain_textChanged(const QString& arg1)
{
    ui->buttonGenerateTraversal->setEnabled(isInputValidInfo(ui));
}

// Check if the start and end coords for the Traversal Chain are valid
bool isInputValidChain(Ui::MainWindow *ui)
{
    // Check if the start coords are valid
    //bool areStartCoordsValid = areCoordsValid(ui->inputStartCoordsChain->text().toStdString());

    // Check if the end coords are valid
    bool areEndCoordsValid = areCoordsValid(ui->inputEndCoordsChain->text().toStdString());

    // Convert the entity number to int to check if it's valid
    bool isEntityNumberValid;
    ui->inputEntityNum->text().toInt(&isEntityNumberValid);
    isEntityNumberValid = isEntityNumberValid || ui->inputEntityNumChain->text().isEmpty();

    bool wasMidpointAdded = ui->listWidgetMidpoints->count();

    return areEndCoordsValid && wasMidpointAdded;
}
// Check if the coords for the Traversal Chain midpoint are valid
bool isInputValidChainMidpoint(Ui::MainWindow *ui)
{
    // Check if the midpoint coords are valid
    bool areMidCoordsValid = areCoordsValid(ui->inputMidCoordsChain->text().toStdString());

    return areMidCoordsValid;
}

// If any input fields for the Traversal Chain tab are changed, make sure their inputs are valid
//void MainWindow::on_inputStartCoordsChain_textChanged(const QString &arg1)
//{
//    ui->buttonGenerateTraversalChain->setEnabled(isInputValidChain(ui));
//}
void MainWindow::on_inputEndCoordsChain_textChanged(const QString &arg1)
{
    ui->buttonGenerateTraversalChain->setEnabled(isInputValidChain(ui));
}
// Enable "add midpoint" button if the given midpoint coords are valid
void MainWindow::on_inputMidCoordsChain_textChanged(const QString &arg1)
{
    ui->pushButtonAddMidpoint->setEnabled(isInputValidChainMidpoint(ui));
}

// getGUIInputsDEInfoTraversal
void MainWindow::on_buttonGenerateTraversal_released()
{
    auto entityNum = ui->inputEntityNum->text().toInt();
    auto startCoords = stringToVector(ui->inputStartCoords->text().toStdString());
    auto endCoords = stringToVector(ui->inputEndCoords->text().toStdString());
    std::vector<int> monsterIndices = getMonsterTypesDEInfoTraversal(ui);
    bool reciprocalTraversal = ui->selectReciprocalTraversal->isChecked();
    int animIndex = ui->comboBoxAnimSelect->currentIndex();

    generateInfoTraversal(entityNum, startCoords, endCoords, monsterIndices, animIndex, reciprocalTraversal);
    ui->inputEntityNum->setText(QString::number(entityNum + 1));
}

// addMidPointToList
void MainWindow::on_pushButtonAddMidpoint_clicked()
{
    ui->listWidgetMidpoints->addItem(ui->inputMidCoordsChain->text());
    tempAnimList.push_back(ui->comboBoxAnimSelectStartChain_2->currentIndex());
    ui->listWidgetMidAnims->addItem(dropDownAnimations[ui->comboBoxAnimSelectStartChain_2->currentIndex()]);
    ui->inputMidCoordsChain->clear();

    // Also try to enable "generate traversal chain" button after adding midpoint
    ui->buttonGenerateTraversalChain->setEnabled(isInputValidChain(ui));
}

// getGUIInputsDETraversalChain
void MainWindow::on_buttonGenerateTraversalChain_clicked()
{
    auto entityName = ui->inputEntityNumChain->text().toStdString();

    std::vector<idInfo_TraversalChain_General> entityObjects;
    for (int i = 0; i < ui->listWidgetMidpoints->count(); i++)
    {
        idInfo_TraversalChain_General tempObject;
        tempObject.entityName = "mod_traversal_chain_" + entityName + "_" + numToLetterStr[i+1];
        tempObject.coordinates = stringToVector(ui->listWidgetMidpoints->item(i)->text().toStdString());
        tempObject.animationIndex = tempAnimList[i];

        entityObjects.push_back(tempObject);
    }

    idInfo_TraversalPoint lastEntity;
    lastEntity.entityName = "mod_traversal_chain_landing_" + entityName;
    lastEntity.coordinates = stringToVector(ui->inputEndCoordsChain->text().toStdString());

    std::vector<int> monsterIndices = getMonsterTypesDETraversalChain(ui);

    bool reciprocalTraversal = ui->selectReciprocalTraversalChain->isChecked();

    generateTraversalChain(entityObjects, lastEntity, monsterIndices, reciprocalTraversal);
}


void MainWindow::on_pushButtonClearOutputHang_clicked()
{
    std::fstream output("DE Generated Hangouts.txt", std::fstream::out);
    output << "";
    output.close();
}

// Generate Arachnotron Traversal Chain
void MainWindow::on_pushButtonForTesting_clicked()
{
    auto entityName = ui->inputEntityNameHangArachnotron->text().toStdString();

    idInfo_TraversalPoint landingEntity;
    landingEntity.entityName = "mod_traversal_chain_arachnotron_hangout_landing_" + entityName;
    landingEntity.coordinates = stringToVector(ui->inputCoordsLandArachnotron->text().toStdString());

    std::vector<idInfo_TraversalChain_Hang> entityObjects;
    for (int i = 0; i < ui->listWidget_hangCoordsArachnotron->count(); i++)
    {
        idInfo_TraversalChain_Hang tempObject;
        tempObject.entityName = "mod_traversal_chain_arachnotron_hangout_" + entityName + "_" + numToLetterStr[i+1];
        tempObject.coordinates = stringToVector(ui->listWidget_hangCoordsArachnotron->item(i)->text().toStdString());
        tempObject.linkAnimation = ui->listWidget_hangLinkArachnotron->item(i)->text().toStdString();

        auto tempStr = ui->listWidget_hangIdleArachnotron->item(i)->text().toStdString();
        if (tempStr == "NONE")
            tempObject.idleAnimation = "";
        else
            tempObject.idleAnimation = "animweb/characters/monsters/arachnotron/" + tempStr;

        entityObjects.push_back(tempObject);
    }

    static const std::vector<std::string> hangoutTemplate = textFileToVector("Templates/Traversal Chain/Hangout/Arachnotron/TraversalChainHangout.txt");

    generateHangout(hangoutTemplate, entityObjects, landingEntity);
}

// Add an Arachnotron Traversal Chain
void MainWindow::on_pushButton_addChain_clicked()
{
    ui->listWidget_hangCoordsArachnotron->addItem(ui->inputCoordsHangArachnotron->text());
    ui->listWidget_hangLinkArachnotron->addItem(ui->comboBox_linkAnimsArachnotron->currentText());
    ui->listWidget_hangIdleArachnotron->addItem(ui->comboBox_idleAnimsArachnotron->currentText());
    ui->inputCoordsHangArachnotron->clear();
}

// Clear Arachnotron Traversal Chains
void MainWindow::on_pushButton_clearHangArachnotron_clicked()
{
     ui->listWidget_hangCoordsArachnotron->clear();
     ui->listWidget_hangLinkArachnotron->clear();
     ui->listWidget_hangIdleArachnotron->clear();
}

// Generate Imp Traversal Chain
void MainWindow::on_pushButtonToMakeHangImp_clicked()
{
    auto entityName = ui->inputEntityNameHangImp->text().toStdString();

    idInfo_TraversalPoint landingEntity;
    landingEntity.entityName = "mod_traversal_chain_imp_hangout_landing_" + entityName;
    landingEntity.coordinates = stringToVector(ui->inputCoordsLandImp->text().toStdString());

    std::vector<idInfo_TraversalChain_Hang> entityObjects;
    for (int i = 0; i < ui->listWidget_hangCoordsImp->count(); i++)
    {
        idInfo_TraversalChain_Hang tempObject;
        tempObject.entityName = "mod_traversal_chain_imp_hangout_" + entityName + "_" + numToLetterStr[i+1];
        tempObject.coordinates = stringToVector(ui->listWidget_hangCoordsImp->item(i)->text().toStdString());
        tempObject.linkAnimation = ui->listWidget_hangLinkImp->item(i)->text().toStdString();

        auto tempStr = ui->listWidget_hangIdleImp->item(i)->text().toStdString();
        if (tempStr == "NONE")
            tempObject.idleAnimation = "";
        else
            tempObject.idleAnimation = "animweb/characters/monsters/imp/" + tempStr;

        entityObjects.push_back(tempObject);
    }

    static const std::vector<std::string> hangoutTemplate = textFileToVector("Templates/Traversal Chain/Hangout/Imp/TraversalChainHangout.txt");

    generateHangout(hangoutTemplate, entityObjects, landingEntity);
}


void MainWindow::on_pushButton_addChain_Imp_clicked()
{
    ui->listWidget_hangCoordsImp->addItem(ui->inputCoordsHangImp->text());
    ui->listWidget_hangLinkImp->addItem(ui->comboBox_linkAnimsImp->currentText());
    ui->listWidget_hangIdleImp->addItem(ui->comboBox_idleAnimsImp->currentText());
    ui->inputCoordsHangImp->clear();
}


void MainWindow::on_pushButton_clearHangImp_clicked()
{
    ui->listWidget_hangCoordsImp->clear();
    ui->listWidget_hangLinkImp->clear();
    ui->listWidget_hangIdleImp->clear();
}

