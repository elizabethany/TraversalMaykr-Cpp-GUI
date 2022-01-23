#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

// pm_NormalViewHeight, using default value
static const double DEpmNormalViewHeight = 1.65735;

/*
Set 1 is for all monsters not listed below
Set 2 is for the Baron, Hell Knight, Imp, Mancubus, Pinky, and Soldier
Set 3 is for the Marauder Wolf
Set 4 is for the Arachnotron
Set 5 is for the Zombie
*/
static const std::vector<std::string> animationSet1 = { "ledge_up_100", "ledge_up_200", "ledge_up_300", "ledge_up_400", "ledge_up_500", "ledge_up_700", "ledge_up_1000", "ledge_down_100", "ledge_down_200", "ledge_down_300", "ledge_down_400", "ledge_down_500", "ledge_down_700", "ledge_down_1000", "rail_down_100", "rail_down_200", "rail_down_300", "rail_down_400", "rail_down_500", "rail_down_700", "rail_down_1000", "rail_up_100", "rail_up_200", "rail_up_300", "rail_up_400", "rail_up_500", "rail_up_700", "rail_up_1000", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_1000", "jump_forward_300_down_300", "jump_forward_300_down_500", "jump_forward_300_up_300", "jump_forward_300_up_500", "jump_forward_500_down_300", "jump_forward_500_down_500", "jump_forward_500_up_300", "jump_forward_500_up_500", "jump_forward_1000_down_1000", "jump_forward_1000_up_1000" };
static const std::vector<std::string> animationSet2 = { "jump_ledge_up_100", "jump_ledge_up_200", "jump_ledge_up_300", "jump_ledge_up_400", "jump_ledge_up_500", "jump_ledge_up_700", "jump_ledge_up_1000", "jump_ledge_down_100", "jump_ledge_down_200", "jump_ledge_down_300", "jump_ledge_down_400", "jump_ledge_down_500", "jump_ledge_down_700", "jump_ledge_down_1000", "jump_rail_down_100", "jump_rail_down_200", "jump_rail_down_300", "jump_rail_down_400", "jump_rail_down_500", "jump_rail_down_700", "jump_rail_down_1000", "jump_rail_up_100", "jump_rail_up_200", "jump_rail_up_300", "jump_rail_up_400", "jump_rail_up_500", "jump_rail_up_700", "jump_rail_up_1000", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_1000", "jump_forward_300_down_300", "jump_forward_300_down_500", "jump_forward_300_up_300", "jump_forward_300_up_500", "jump_forward_500_down_300", "jump_forward_500_down_500", "jump_forward_500_up_300", "jump_forward_500_up_500", "jump_forward_1000_down_1000", "jump_forward_1000_up_1000" };
static const std::vector<std::string> animationSet3 = { "ledge_up_100", "ledge_up_200", "ledge_up_300", "ledge_up_400", "ledge_up_500", "ledge_up_700", "ledge_up_1000", "ledge_down_100", "ledge_down_200", "ledge_down_300", "ledge_down_400", "ledge_down_500", "ledge_down_700", "ledge_down_1000", "rail_down_100", "rail_down_200", "rail_down_300", "rail_down_400", "rail_down_500", "rail_down_700", "rail_down_1000", "rail_up_100", "rail_up_200", "rail_up_300", "rail_up_400", "rail_up_500", "rail_up_700", "rail_up_1000", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_1000", "ledge_forward_300_down_300", "ledge_forward_300_down_500", "ledge_forward_300_up_300", "ledge_forward_300_up_500", "ledge_forward_500_down_300", "ledge_forward_500_down_500", "ledge_forward_500_up_300", "ledge_forward_500_up_500", "ledge_forward_1000_down_1000", "ledge_forward_1000_up_1000" };
static const std::vector<std::string> animationSet4 = { "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "", "", "", "", "", "", "", "", "", "" };
static const std::vector<std::string> animationSet5 = { "ledge_up_100", "ledge_up_200", "ledge_up_300", "ledge_up_400", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_down_100", "ledge_down_200", "ledge_down_300", "ledge_down_400", "ledge_down_500", "ledge_down_700", "ledge_down_1000", "rail_down_100", "rail_down_200", "rail_down_300", "rail_down_400", "rail_down_500", "rail_down_700", "rail_down_1000", "rail_up_100", "rail_up_200", "rail_up_300", "rail_up_400", "rail_up_500", "rail_up_500", "rail_up_500", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_700", "jump_forward_300_down_300", "jump_forward_300_down_500", "jump_forward_300_up_300", "jump_forward_300_up_500", "jump_forward_500_down_300", "jump_forward_500_down_500", "jump_forward_500_up_300", "jump_forward_500_up_500", "jump_forward_1000_down_1000", "jump_forward_500_up_500" };
static const std::vector<std::vector<std::string>> DEAnimationSets = { animationSet1, animationSet2, animationSet3, animationSet4, animationSet5 };

// Various items to substitute in the templates, depending on the monster type you picked
static const std::vector<std::string> DEMonsterNames = { "archvile", "blood_maykr", "carcass", "doom_hunter", "dread_knight", "gargoyle", "marauder", "prowler", "revenant", "tyrant", "whiplash", "maykr_drone", "mecha_zombie", "arachnatron", "wolf", "zombie", "baron", "hell_knight", "imp", "mancubus", "pinky", "soldier" };
static const std::vector<std::string> DEMonsterTypes = { "TRAVERSALMONSTERTYPE_ARCHVILE", "TRAVERSALMONSTERTYPE_BLOOD_ANGEL", "TRAVERSALMONSTERTYPE_CARCASS", "TRAVERSALMONSTERTYPE_DOOM_HUNTER", "TRAVERSALMONSTERTYPE_DREADKNIGHT", "TRAVERSALMONSTERTYPE_GARGOYLE", "TRAVERSALMONSTERTYPE_MARAUDER", "TRAVERSALMONSTERTYPE_PROWLER", "TRAVERSALMONSTERTYPE_REVENANT", "TRAVERSALMONSTERTYPE_TYRANT", "TRAVERSALMONSTERTYPE_WHIPLASH", "TRAVERSALMONSTERTYPE_ZOMBIE_MAYKR", "TRAVERSALMONSTERTYPE_ZOMBIE_T3", "TRAVERSALMONSTERTYPE_ARACHNATRON", "TRAVERSALMONSTERTYPE_MARAUDER_WOLF", "TRAVERSALMONSTERTYPE_ZOMBIE", "TRAVERSALMONSTERTYPE_BARON", "TRAVERSALMONSTERTYPE_HELLKNIGHT", "TRAVERSALMONSTERTYPE_IMP", "TRAVERSALMONSTERTYPE_MANCUBUS", "TRAVERSALMONSTERTYPE_PINKY", "TRAVERSALMONSTERTYPE_HELLIFIED_SOLDIER" };
static const std::vector<std::string> DEMonsterPaths = { "archvile/traversal", "bloodangel/traversal", "carcass/traversal", "doomhunter/traversal", "dreadknight/traversal", "gargoyle/traversal", "marauder/traversals", "prowler/traversal", "revenant/traversals", "tyrant/traversal", "whiplash/traversal", "zombie_maykr/traversal", "zombie_tier_3/traversal", "arachnotron/traversal", "marauder_wolf/traversals", "zombie_tier_1/traversal", "baron/traversal", "hellknight/traversal", "imp/traversal",    "mancubus_fire/traversal", "pinky/traversal", "soldier_blaster/traversal" };

// Quick int to char (to string) conversion
static const std::vector<std::string> numToLetterStr = { "0", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };

// To popular drown down menu with available animations
static const QStringList dropDownAnimations = { "ledge_up_100", "ledge_up_200", "ledge_up_300", "ledge_up_400", "ledge_up_500", "ledge_up_700", "ledge_up_1000", "ledge_down_100", "ledge_down_200", "ledge_down_300", "ledge_down_400", "ledge_down_500", "ledge_down_700", "ledge_down_1000", "rail_down_100", "rail_down_200", "rail_down_300", "rail_down_400", "rail_down_500", "rail_down_700", "rail_down_1000", "rail_up_100", "rail_up_200", "rail_up_300", "rail_up_400", "rail_up_500", "rail_up_700", "rail_up_1000", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_1000", "jump_forward_300_down_300", "jump_forward_300_down_500", "jump_forward_300_up_300", "jump_forward_300_up_500", "jump_forward_500_down_300", "jump_forward_500_down_500", "jump_forward_500_up_300", "jump_forward_500_up_500", "jump_forward_1000_down_1000", "jump_forward_1000_up_1000" };

std::vector<int> tempAnimList;

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
    static const std::vector<std::string> infoTraversalTemplate = textFileToVector("Templates/Eternal/InfoTraversal.txt");

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

// Create idInfo_TraversalChain and idInfo_TraversalPoint entities for the given inputs and writes them to their output
void generateTraversalChain(
    int entityNum,
    std::vector<double> startCoords,
    std::vector<std::vector<double>> midCoords,
    std::vector<double> endCoords,
    std::vector<int> monsterIndices,
    std::vector<int> traversalAnims,
    bool reciprocalTraversal
)
{
    static const std::vector<std::string> TraversalChainTemplate = textFileToVector("Templates/Eternal/TraversalChain.txt");
    static const std::vector<std::string> TraversalChainMidTemplate = textFileToVector("Templates/Eternal/TraversalChainMid.txt");

    for (const auto& monsterIndex : monsterIndices)
    {
        auto generatedEntity1 = TraversalChainTemplate;

        std::string entityNumStr = zeroPadded(std::to_string(entityNum));

        const int animSetIndex = getAnimIndex(monsterIndex);

        const std::string monsterName = DEMonsterNames.at(monsterIndex);
        const std::string monsterPath = DEMonsterPaths.at(monsterIndex);
        const std::string monsterType = DEMonsterTypes.at(monsterIndex);
        const std::string animWeb = monsterPathTruncater(monsterPath);

        const auto startX = std::to_string(startCoords.at(0));
        const auto startY = std::to_string(startCoords.at(1));
        const auto startZ = std::to_string(startCoords.at(2) - DEpmNormalViewHeight);
        const auto endX = std::to_string(endCoords.at(0));
        const auto endY = std::to_string(endCoords.at(1));
        const auto endZ = std::to_string(endCoords.at(2) - DEpmNormalViewHeight);
        const std::string animation = DEAnimationSets.at(animSetIndex).at(traversalAnims.at(0));

        replaceThisInString((generatedEntity1).at(1), "{{{entityNum}}}", entityNumStr);
        replaceThisInString((generatedEntity1).at(1), "{{{monsterName}}}", monsterName);
        replaceThisInString((generatedEntity1).at(9), "{{{monsterType}}}", monsterType);
        replaceThisInString((generatedEntity1).at(10), "{{{animWeb}}}", animWeb);
        replaceThisInString((generatedEntity1).at(12), "{{{startX}}}", startX);
        replaceThisInString((generatedEntity1).at(13), "{{{startY}}}", startY);
        replaceThisInString((generatedEntity1).at(14), "{{{startZ}}}", startZ);
        replaceThisInString((generatedEntity1).at(20), "{{{monsterName}}}", monsterName);
        replaceThisInString((generatedEntity1).at(20), "{{{entityNum}}}", entityNumStr);
        replaceThisInString((generatedEntity1).at(21), "{{{monsterPathStart}}}", monsterPath);
        replaceThisInString((generatedEntity1).at(21), "{{{animation}}}", animation);

        replaceThisInString((generatedEntity1).at(28), "{{{monsterName}}}", monsterName);
        replaceThisInString((generatedEntity1).at(28), "{{{entityNum}}}", entityNumStr);
        replaceThisInString((generatedEntity1).at(37), "{{{endX}}}", endX);
        replaceThisInString((generatedEntity1).at(38), "{{{endY}}}", endY);
        replaceThisInString((generatedEntity1).at(39), "{{{endZ}}}", endZ);

        writeThisThing(generatedEntity1, "DE Generated Traversal Chains.txt");

        int midNum = 1;
        for (const auto& currentMidPoint : midCoords)
        {
            std::vector<std::string> generatedEntity2 = TraversalChainMidTemplate;

            std::string nextPoint;
            if (midNum == midCoords.size())
            {
                nextPoint = "mod_traversal_point_" + monsterName + "_end_" + entityNumStr;
            }
            else
            {
                nextPoint = "mod_traversal_chain_" + monsterName + "_mid_" + numToLetterStr.at(midNum + 1) + "_" + entityNumStr;
            }

            const auto midCoordX = std::to_string(currentMidPoint.at(0));
            const auto midCoordY = std::to_string(currentMidPoint.at(1));
            const auto midCoordZ = std::to_string(currentMidPoint.at(2) - DEpmNormalViewHeight);
            const std::string currentMidLetter = numToLetterStr.at(midNum);
            const std::string midAnimation = DEAnimationSets.at(animSetIndex).at(traversalAnims.at(midNum));

            replaceThisInString((generatedEntity2).at(1), "{{{monsterName}}}", monsterName);
            replaceThisInString((generatedEntity2).at(1), "{{{midLetter}}}", currentMidLetter);
            replaceThisInString((generatedEntity2).at(1), "{{{entityNum}}}", entityNumStr);
            replaceThisInString((generatedEntity2).at(9), "{{{monsterType}}}", monsterType);
            replaceThisInString((generatedEntity2).at(10), "{{{animWeb}}}", animWeb);
            replaceThisInString((generatedEntity2).at(12), "{{{midCoordX}}}", midCoordX);
            replaceThisInString((generatedEntity2).at(13), "{{{midCoordY}}}", midCoordY);
            replaceThisInString((generatedEntity2).at(14), "{{{midCoordZ}}}", midCoordZ);
            replaceThisInString((generatedEntity2).at(20), "{{{nextPoint}}}", nextPoint);
            replaceThisInString((generatedEntity2).at(21), "{{{monsterPathMid}}}", monsterPath);
            replaceThisInString((generatedEntity2).at(21), "{{{midAnimation}}}", midAnimation);

            writeThisThing(generatedEntity2, "DE Generated Traversal Chains.txt");

            midNum++;
        }

        if (reciprocalTraversal)
        {
            auto generatedEntity1_r = TraversalChainTemplate;

            const auto startX_r = std::to_string(endCoords.at(0));
            const auto startY_r = std::to_string(endCoords.at(1));
            const auto startZ_r = std::to_string(endCoords.at(2) - DEpmNormalViewHeight);
            const auto endX_r = std::to_string(startCoords.at(0));
            const auto endY_r = std::to_string(startCoords.at(1));
            const auto endZ_r = std::to_string(startCoords.at(2) - DEpmNormalViewHeight);
            const std::string animation_r = animReverser(DEAnimationSets.at(animSetIndex).at(traversalAnims.at(midNum-1)));
            entityNumStr.append("_r");

            replaceThisInString((generatedEntity1_r).at(1), "{{{entityNum}}}", entityNumStr);
            replaceThisInString((generatedEntity1_r).at(1), "{{{monsterName}}}", monsterName);
            replaceThisInString((generatedEntity1_r).at(9), "{{{monsterType}}}", monsterType);
            replaceThisInString((generatedEntity1_r).at(10), "{{{animWeb}}}", animWeb);
            replaceThisInString((generatedEntity1_r).at(12), "{{{startX}}}", startX_r);
            replaceThisInString((generatedEntity1_r).at(13), "{{{startY}}}", startY_r);
            replaceThisInString((generatedEntity1_r).at(14), "{{{startZ}}}", startZ_r);
            replaceThisInString((generatedEntity1_r).at(20), "{{{monsterName}}}", monsterName);
            replaceThisInString((generatedEntity1_r).at(20), "{{{entityNum}}}", entityNumStr);
            replaceThisInString((generatedEntity1_r).at(21), "{{{monsterPathStart}}}", monsterPath);
            replaceThisInString((generatedEntity1_r).at(21), "{{{animation}}}", animation_r);

            replaceThisInString((generatedEntity1_r).at(28), "{{{monsterName}}}", monsterName);
            replaceThisInString((generatedEntity1_r).at(28), "{{{entityNum}}}", entityNumStr);
            replaceThisInString((generatedEntity1_r).at(37), "{{{endX}}}", endX_r);
            replaceThisInString((generatedEntity1_r).at(38), "{{{endY}}}", endY_r);
            replaceThisInString((generatedEntity1_r).at(39), "{{{endZ}}}", endZ_r);

            writeThisThing(generatedEntity1_r, "DE Generated Traversal Chains.txt");

            std::vector<std::vector<double>> midCoords_r(midCoords.rbegin(), midCoords.rend());
            std::vector<double> traversalAnims_r(traversalAnims.rbegin(), traversalAnims.rend());
            //for (double currentLine : traversalAnims_r)
            //{
            //    std::cout << currentLine << "\n";
            //}
            int midNum_r = 1;
            for (const auto& currentMidPoint : midCoords_r)
            {
                std::vector<std::string> generatedEntity2_r = TraversalChainMidTemplate;

                std::string nextPoint;
                if (midNum_r == midCoords_r.size())
                {
                    nextPoint = "mod_traversal_point_" + monsterName + "_end_" + entityNumStr;
                }
                else
                {
                    nextPoint = "mod_traversal_chain_" + monsterName + "_mid_" + numToLetterStr.at(midNum_r + 1) + "_" + entityNumStr;
                }

                const auto midCoordX = std::to_string(currentMidPoint.at(0));
                const auto midCoordY = std::to_string(currentMidPoint.at(1));
                const auto midCoordZ = std::to_string(currentMidPoint.at(2) - DEpmNormalViewHeight);
                const std::string currentMidLetter = numToLetterStr.at(midNum_r);
                const std::string midAnimation = animReverser(DEAnimationSets.at(animSetIndex).at(traversalAnims_r.at(midNum_r)));

                replaceThisInString((generatedEntity2_r).at(1), "{{{monsterName}}}", monsterName);
                replaceThisInString((generatedEntity2_r).at(1), "{{{midLetter}}}", currentMidLetter);
                replaceThisInString((generatedEntity2_r).at(1), "{{{entityNum}}}", entityNumStr);
                replaceThisInString((generatedEntity2_r).at(9), "{{{monsterType}}}", monsterType);
                replaceThisInString((generatedEntity2_r).at(10), "{{{animWeb}}}", animWeb);
                replaceThisInString((generatedEntity2_r).at(12), "{{{midCoordX}}}", midCoordX);
                replaceThisInString((generatedEntity2_r).at(13), "{{{midCoordY}}}", midCoordY);
                replaceThisInString((generatedEntity2_r).at(14), "{{{midCoordZ}}}", midCoordZ);
                replaceThisInString((generatedEntity2_r).at(20), "{{{nextPoint}}}", nextPoint);
                replaceThisInString((generatedEntity2_r).at(21), "{{{monsterPathMid}}}", monsterPath);
                replaceThisInString((generatedEntity2_r).at(21), "{{{midAnimation}}}", midAnimation);

                writeThisThing(generatedEntity2_r, "DE Generated Traversal Chains.txt");

                midNum_r++;
            }
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // Set window title
    setWindowTitle("TraversalMaykr-Cpp-GUI v0.2 by elizabethany");

    // For Traversal Info
    ui->demonSelect_19->setChecked(true);
    ui->radioButtonPresetNoneInfo->setChecked(true);
    ui->comboBoxAnimSelect->addItems(dropDownAnimations);
    ui->buttonGenerateTraversal->setEnabled(false); // Disable "generate traversal info" button

    // For Traversal Chain
    ui->demonSelect_19_Chain->setChecked(true);
    ui->radioButtonPresetNoneChain->setChecked(true);
    ui->comboBoxAnimSelectStartChain->addItems(dropDownAnimations);
    ui->comboBoxAnimSelectStartChain_2->addItems(dropDownAnimations);
    ui->buttonGenerateTraversalChain->setEnabled(false); // Disable "generate traversal chain" button
    ui->pushButtonAddMidpoint->setEnabled(false); // Disable "add midpoint" button
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
    ui->inputStartCoordsChain->clear();
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

// Check if the current inputs for the Traversal Chain tab are valid
bool isInputValidChain(Ui::MainWindow *ui)
{
    // Check if the start coords are valid
    bool areStartCoordsValid = areCoordsValid(ui->inputStartCoordsChain->text().toStdString());

    // Check if the end coords are valid
    bool areEndCoordsValid = areCoordsValid(ui->inputEndCoordsChain->text().toStdString());

    // Convert the entity number to int to check if it's valid
    bool isEntityNumberValid;
    ui->inputEntityNum->text().toInt(&isEntityNumberValid);
    isEntityNumberValid = isEntityNumberValid || ui->inputEntityNumChain->text().isEmpty();

    return areStartCoordsValid && areEndCoordsValid && isEntityNumberValid;
}
bool isInputValidChainMidpoint(Ui::MainWindow *ui)
{
    // Check if the midpoint coords are valid
    bool areMidCoordsValid = areCoordsValid(ui->inputMidCoordsChain->text().toStdString());

    return areMidCoordsValid;
}

// If any input fields for the Traversal Chain tab are changed, make sure their inputs are valid
void MainWindow::on_inputStartCoordsChain_textChanged(const QString &arg1)
{
    ui->buttonGenerateTraversalChain->setEnabled(isInputValidChain(ui));
}
void MainWindow::on_inputEndCoordsChain_textChanged(const QString &arg1)
{
    ui->buttonGenerateTraversalChain->setEnabled(isInputValidChain(ui));
}
void MainWindow::on_inputMidCoordsChain_textChanged(const QString &arg1)
{
    ui->buttonGenerateTraversalChain->setEnabled(isInputValidChainMidpoint(ui));
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
}

// getGUIInputsDETraversalChain
void MainWindow::on_buttonGenerateTraversalChain_clicked()
{
    auto entityNum = ui->inputEntityNumChain->text().toInt();
    auto startCoords = stringToVector(ui->inputStartCoordsChain->text().toStdString());

    std::vector<std::vector<double>> midCoords;
    for (int i = 0; i < ui->listWidgetMidpoints->count(); i++)
    {
       midCoords.push_back(stringToVector(ui->listWidgetMidpoints->item(i)->text().toStdString()));
    }

    auto endCoords = stringToVector(ui->inputEndCoordsChain->text().toStdString());

    auto monsterIndices = getMonsterTypesDETraversalChain(ui);
    auto traversalAnims = tempAnimList;
    traversalAnims.insert(traversalAnims.begin()+0, ui->comboBoxAnimSelectStartChain->currentIndex());
    auto reciprocalTraversal = ui->selectReciprocalTraversalChain->isChecked();

    generateTraversalChain(entityNum, startCoords, midCoords, endCoords, monsterIndices, traversalAnims, reciprocalTraversal);
    ui->inputEntityNumChain->setText(QString::number(entityNum + 1));
}

