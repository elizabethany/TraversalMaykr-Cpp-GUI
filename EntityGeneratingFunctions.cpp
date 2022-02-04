#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include "EntityGeneratingFunctions.h"
#include "GeneralFunctions.h"
#include "EntityClasses.h"

// pm_NormalViewHeight, using default value for Doom Eternal
const double DEpmNormalViewHeight = 1.65735;

// Set 1 is for all monsters not listed below
const std::vector<std::string> animationSet1 = { "ledge_up_100", "ledge_up_200", "ledge_up_300", "ledge_up_400", "ledge_up_500", "ledge_up_700", "ledge_up_1000", "ledge_down_100", "ledge_down_200", "ledge_down_300", "ledge_down_400", "ledge_down_500", "ledge_down_700", "ledge_down_1000", "rail_down_100", "rail_down_200", "rail_down_300", "rail_down_400", "rail_down_500", "rail_down_700", "rail_down_1000", "rail_up_100", "rail_up_200", "rail_up_300", "rail_up_400", "rail_up_500", "rail_up_700", "rail_up_1000", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_1000", "jump_forward_300_down_300", "jump_forward_300_down_500", "jump_forward_300_up_300", "jump_forward_300_up_500", "jump_forward_500_down_300", "jump_forward_500_down_500", "jump_forward_500_up_300", "jump_forward_500_up_500", "jump_forward_1000_down_1000", "jump_forward_1000_up_1000" };
// Set 2 is for the Baron, Hell Knight, Imp, Mancubus, Pinky, and Soldier
const std::vector<std::string> animationSet2 = { "jump_ledge_up_100", "jump_ledge_up_200", "jump_ledge_up_300", "jump_ledge_up_400", "jump_ledge_up_500", "jump_ledge_up_700", "jump_ledge_up_1000", "jump_ledge_down_100", "jump_ledge_down_200", "jump_ledge_down_300", "jump_ledge_down_400", "jump_ledge_down_500", "jump_ledge_down_700", "jump_ledge_down_1000", "jump_rail_down_100", "jump_rail_down_200", "jump_rail_down_300", "jump_rail_down_400", "jump_rail_down_500", "jump_rail_down_700", "jump_rail_down_1000", "jump_rail_up_100", "jump_rail_up_200", "jump_rail_up_300", "jump_rail_up_400", "jump_rail_up_500", "jump_rail_up_700", "jump_rail_up_1000", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_1000", "jump_forward_300_down_300", "jump_forward_300_down_500", "jump_forward_300_up_300", "jump_forward_300_up_500", "jump_forward_500_down_300", "jump_forward_500_down_500", "jump_forward_500_up_300", "jump_forward_500_up_500", "jump_forward_1000_down_1000", "jump_forward_1000_up_1000" };
// Set 3 is for the Marauder Wolf
const std::vector<std::string> animationSet3 = { "ledge_up_100", "ledge_up_200", "ledge_up_300", "ledge_up_400", "ledge_up_500", "ledge_up_700", "ledge_up_1000", "ledge_down_100", "ledge_down_200", "ledge_down_300", "ledge_down_400", "ledge_down_500", "ledge_down_700", "ledge_down_1000", "rail_down_100", "rail_down_200", "rail_down_300", "rail_down_400", "rail_down_500", "rail_down_700", "rail_down_1000", "rail_up_100", "rail_up_200", "rail_up_300", "rail_up_400", "rail_up_500", "rail_up_700", "rail_up_1000", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_1000", "ledge_forward_300_down_300", "ledge_forward_300_down_500", "ledge_forward_300_up_300", "ledge_forward_300_up_500", "ledge_forward_500_down_300", "ledge_forward_500_down_500", "ledge_forward_500_up_300", "ledge_forward_500_up_500", "ledge_forward_1000_down_1000", "ledge_forward_1000_up_1000" };
// Set 4 is for the Arachnotron
const std::vector<std::string> animationSet4 = { "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "", "", "", "", "", "", "", "", "", "" };
// Set 5 is for the Zombie
const std::vector<std::string> animationSet5 = { "ledge_up_100", "ledge_up_200", "ledge_up_300", "ledge_up_400", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_down_100", "ledge_down_200", "ledge_down_300", "ledge_down_400", "ledge_down_500", "ledge_down_700", "ledge_down_1000", "rail_down_100", "rail_down_200", "rail_down_300", "rail_down_400", "rail_down_500", "rail_down_700", "rail_down_1000", "rail_up_100", "rail_up_200", "rail_up_300", "rail_up_400", "rail_up_500", "rail_up_500", "rail_up_500", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_700", "jump_forward_300_down_300", "jump_forward_300_down_500", "jump_forward_300_up_300", "jump_forward_300_up_500", "jump_forward_500_down_300", "jump_forward_500_down_500", "jump_forward_500_up_300", "jump_forward_500_up_500", "jump_forward_1000_down_1000", "jump_forward_500_up_500" };
// Set 6 is for the Gladiator
const std::vector<std::string> animationSet6 = { "ledge_up_250", "ledge_up_250", "ledge_up_250", "ledge_up_400", "ledge_up_500", "ledge_up_500", "ledge_up_500", "ledge_down_250", "ledge_down_250", "ledge_down_250", "ledge_down_500", "ledge_down_500", "ledge_down_500", "ledge_down_500", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "jump_forward_250", "jump_forward_250", "jump_forward_250", "jump_forward_500", "jump_forward_500", "jump_forward_500", "jump_forward_500", "", "", "", "", "", "", "", "", "", "" };
// Vector of all the above animation sets
const std::vector<std::vector<std::string>> DEAnimationSets = { animationSet1, animationSet2, animationSet3, animationSet4, animationSet5, animationSet6 };

// Various items to substitute in the templates, depending on the monster type you picked
const std::vector<std::string> DEMonsterNames = { "archvile", "blood_maykr", "carcass", "doom_hunter", "dread_knight", "gargoyle", "marauder", "prowler", "revenant", "tyrant", "whiplash", "maykr_drone", "mecha_zombie", "arachnatron", "wolf", "zombie", "baron", "hell_knight", "imp", "mancubus", "pinky", "soldier", "gladiator", "samuel" };
const std::vector<std::string> DEMonsterTypes = { "TRAVERSALMONSTERTYPE_ARCHVILE", "TRAVERSALMONSTERTYPE_BLOOD_ANGEL", "TRAVERSALMONSTERTYPE_CARCASS", "TRAVERSALMONSTERTYPE_DOOM_HUNTER", "TRAVERSALMONSTERTYPE_DREADKNIGHT", "TRAVERSALMONSTERTYPE_GARGOYLE", "TRAVERSALMONSTERTYPE_MARAUDER", "TRAVERSALMONSTERTYPE_PROWLER", "TRAVERSALMONSTERTYPE_REVENANT", "TRAVERSALMONSTERTYPE_TYRANT", "TRAVERSALMONSTERTYPE_WHIPLASH", "TRAVERSALMONSTERTYPE_ZOMBIE_MAYKR", "TRAVERSALMONSTERTYPE_ZOMBIE_T3", "TRAVERSALMONSTERTYPE_ARACHNATRON", "TRAVERSALMONSTERTYPE_MARAUDER_WOLF", "TRAVERSALMONSTERTYPE_ZOMBIE", "TRAVERSALMONSTERTYPE_BARON", "TRAVERSALMONSTERTYPE_HELLKNIGHT", "TRAVERSALMONSTERTYPE_IMP", "TRAVERSALMONSTERTYPE_MANCUBUS", "TRAVERSALMONSTERTYPE_PINKY", "TRAVERSALMONSTERTYPE_HELLIFIED_SOLDIER", "TRAVERSALMONSTERTYPE_GLADIATOR", "TRAVERSALMONSTERTYPE_SAMUEL_BOSS" };
const std::vector<std::string> DEMonsterPaths = { "archvile/traversal", "bloodangel/traversal", "carcass/traversal", "doomhunter/traversal", "dreadknight/traversal", "gargoyle/traversal", "marauder/traversals", "prowler/traversal", "revenant/traversals", "tyrant/traversal", "whiplash/traversal", "zombie_maykr/traversal", "zombie_tier_3/traversal", "arachnotron/traversal", "marauder_wolf/traversals", "zombie_tier_1/traversal", "baron/traversal", "hellknight/traversal", "imp/traversal",    "mancubus_fire/traversal", "pinky/traversal", "soldier_blaster/traversal", "gladiator/traversal", "samuel/combat" };


// Create idInfoTraversal entities for the given inputs and writes them to their output
void generateInfoTraversal(
    idInfoTraversal entity,
    std::vector<int> monsterIndices,
    bool reciprocalTraversal
)
{
    static const std::vector<std::string> infoTraversalTemplate = textFileToVector("Templates/Traversal Info/InfoTraversal.txt");

    for (const auto& monsterIndex : monsterIndices)
    {
        std::vector<std::string> generatedEntity = infoTraversalTemplate;

        auto entityName = entity.entityName + "_" + DEMonsterNames.at(monsterIndex);
        const auto animSetIndex = getAnimIndex(monsterIndex);
        const auto monsterName = DEMonsterNames.at(monsterIndex);
        const auto monsterPath = DEMonsterPaths.at(monsterIndex);
        const auto monsterType = DEMonsterTypes.at(monsterIndex);

        std::string animation;
        if (monsterIndex == 23) // Check if it's Samur, since all of his animations are "idle"
        {
            animation = "idle";
        }
        else // Get the animation normally
        {
            animation = DEAnimationSets.at(animSetIndex).at(entity.animationIndex);
        }

        std::vector<std::pair<std::string, std::string>> args = {
            {"ENTITY_NAME", entityName},
            {"monsterPath", monsterPath},
            {"animation", animation},
            {"monsterType", monsterType},
            {"startX", std::to_string(entity.coordinates[0])},
            {"startY", std::to_string(entity.coordinates[1])},
            {"startZ", std::to_string(entity.coordinates[2] - DEpmNormalViewHeight)},
            {"endX", std::to_string(entity.endCoordinates[0] - entity.coordinates[0])},
            {"endY", std::to_string(entity.endCoordinates[1] - entity.coordinates[1])},
            {"endZ", std::to_string((entity.endCoordinates[2] - DEpmNormalViewHeight) - (entity.coordinates[2] - DEpmNormalViewHeight))}
        };
        renderThis(generatedEntity, args);
        writeThisThing(generatedEntity, "Output/Traversal Info.txt");

        if (reciprocalTraversal)
        {
            std::vector<std::string> generatedEntity_r = infoTraversalTemplate;
            entityName.append("_r");

            std::vector<std::pair<std::string, std::string>> args_r = {
                {"ENTITY_NAME", entityName},
                {"monsterName", monsterName},
                {"monsterPath", monsterPath},
                {"animation", animReverser(animation)},
                {"monsterType", monsterType},
                {"startX", std::to_string(entity.endCoordinates[0])},
                {"startY", std::to_string(entity.endCoordinates[1])},
                {"startZ", std::to_string(entity.endCoordinates[2] - DEpmNormalViewHeight)},
                {"endX", std::to_string(entity.coordinates[0] - entity.endCoordinates[0])},
                {"endY", std::to_string(entity.coordinates[1] - entity.endCoordinates[1])},
                {"endZ", std::to_string((entity.coordinates[2] - DEpmNormalViewHeight) - (entity.endCoordinates[2] - DEpmNormalViewHeight))}
            };
            renderThis(generatedEntity_r, args_r);
            writeThisThing(generatedEntity_r, "Output/Traversal Info.txt");
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
        {
            nextTargetName = finalEntity.entityName;
        }
        else
        {
            nextTargetName = entityObjects[i+1].entityName;
        }

        auto linkAnimation = entityObjects[i].linkAnimation;
        auto idleAnimation = entityObjects[i].idleAnimation;

        std::vector<std::pair<std::string, std::string>> args = {
            {"ENTITY_NAME", entityName},
            {"COORDX", entityX},
            {"COORDY", entityY},
            {"COORDZ", entityZ},
            {"MAT0X", mat0X},
            {"MAT0Y", mat0Y},
            {"MAT0Z", mat0Z},
            {"MAT1X", mat1X},
            {"MAT1Y", mat1Y},
            {"MAT1Z", mat1Z},
            {"MAT2X", mat2X},
            {"MAT2Y", mat2Y},
            {"MAT2Z", mat2Z},
            {"NEXT_TARGET_NAME", nextTargetName},
            {"LINK_ANIMATION", linkAnimation},
            {"IDLE_ANIMATION", idleAnimation}
        };
        renderThis(currentEntity, args);
        writeThisThing(currentEntity, "Output/Traversal Chains (Dedicated).txt");
    }

    std::vector<std::string> lastEntity = hangoutEndTemplate;

    replaceThisInString(lastEntity[1], "{{{ENTITY_NAME}}}", finalEntity.entityName);
    replaceThisInString(lastEntity[10], "{{{COORDX}}}", std::to_string(finalEntity.coordinates[0]));
    replaceThisInString(lastEntity[11], "{{{COORDY}}}", std::to_string(finalEntity.coordinates[1]));
    replaceThisInString(lastEntity[12], "{{{COORDZ}}}", std::to_string(finalEntity.coordinates[2] - DEpmNormalViewHeight));
    writeThisThing(lastEntity, "Output/Traversal Chains (Dedicated).txt");
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
    writeThisThing(lastEntity, "Output/Traversal Chains (General).txt");

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

            std::string animation;
            if (monsterIndex == 23) // Check if it's Samur, since all of his animations are "idle"
                animation = "idle";
            else if (reciprocalTraversal) // Get the animation and reverse it if we are making reciprocal traversals
                animation = animReverser(DEAnimationSets[animSetIndex][entityObjects[i].animationIndex]);
            else // Get the animation normally
                animation = DEAnimationSets[animSetIndex][entityObjects[i].animationIndex];

            std::string nextTargetName;
            // Check if this is the last object in the vector. If it is, make the target the endpoint. If not, make the target the next object in the vector.
            if (i == entityObjects.size() - 1)
            {
                nextTargetName = finalEntity.entityName;
            }
            else
            {
                nextTargetName = entityObjects[i+1].entityName + "_" + monsterName;
            }

            std::vector<std::pair<std::string, std::string>> args = {
                {"ENTITY_NAME", entityName},
                {"MONSTERTYPE", monsterType},
                {"ANIMWEB", animWeb},
                {"COORDX", entityX},
                {"COORDY", entityY},
                {"COORDZ", entityZ},
                {"NEXT_TARGET_NAME", nextTargetName},
                {"MONSTER_PATH", monsterPath},
                {"LINK_ANIMATION", animation}
            };
            renderThis(currentEntity, args);
            writeThisThing(currentEntity, "Output/Traversal Chains (General).txt");
        }
    }
}

void generateInfoPath(
    std::vector<idInfoPath> entityObjects
)
{
    static const auto infoPathTemplate = textFileToVector("Templates/Path/InfoPath.txt");

    for (int i = 0; i < entityObjects.size(); i++)
    {
        auto currentEntity = infoPathTemplate;

        /*
        replaceThisInString(currentEntity[1], "{{{ENTITY_NAME}}}", entityObjects[i].entityName);
        replaceThisInString(currentEntity[10], "{{{COORDX}}}", std::to_string(entityObjects[i].coordinates[0]));
        replaceThisInString(currentEntity[11], "{{{COORDY}}}", std::to_string(entityObjects[i].coordinates[1]));
        replaceThisInString(currentEntity[12], "{{{COORDZ}}}", std::to_string(entityObjects[i].coordinates[2] - DEpmNormalViewHeight));

        if (i == entityObjects.size() - 1)
        {
            replaceThisInString(currentEntity[15], "{{{NUM_TARGETS}}}", "0");
            replaceThisInString(currentEntity[16], "{{{NEXT_TARGET}}}", "");
        }
        else
        {
            replaceThisInString(currentEntity[15], "{{{NUM_TARGETS}}}", "1");
            replaceThisInString(currentEntity[16], "{{{NEXT_TARGET}}}", entityObjects[i+1].entityName);
        }

        replaceThisInString(currentEntity[18], "{{{WALKSTATE}}}", entityObjects[i].walkState);
        replaceThisInString(currentEntity[19], "{{{NAVSIZE}}}", entityObjects[i].navSize);
        */

        std::string numTargets, nextTarget;
        if (i == entityObjects.size() - 1)
        {
            numTargets = "0";
            nextTarget = "";
        }
        else
        {
            numTargets = "1";
            nextTarget = entityObjects[i+1].entityName;
        }

        std::vector<std::pair<std::string, std::string>> args = {
            {"ENTITY_NAME", entityObjects[i].entityName},
            {"COORDX", std::to_string(entityObjects[i].coordinates[0])},
            {"COORDY", std::to_string(entityObjects[i].coordinates[1])},
            {"COORDZ", std::to_string(entityObjects[i].coordinates[2] - DEpmNormalViewHeight)},
            {"NUM_TARGETS", numTargets},
            {"NEXT_TARGET", nextTarget},
            {"WALKSTATE", entityObjects[i].walkState},
            {"NAVSIZE", entityObjects[i].navSize}
        };
        renderThis(currentEntity, args);
        writeThisThing(currentEntity, "Output/Info Path.txt");
    }
}
