#include "mainwindow.h"
#include "ui_mainwindow.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include "GeneralFunctions.h"
#include "EntityClasses.h"
#include "EntityGeneratingFunctions.h"

/*
    UI QSTRINGS
*/
// To populate drown down menus with available animations
const QStringList dropDownAnimations = { "ledge_up_100", "ledge_up_200", "ledge_up_300", "ledge_up_400", "ledge_up_500", "ledge_up_700", "ledge_up_1000", "ledge_down_100", "ledge_down_200", "ledge_down_300", "ledge_down_400", "ledge_down_500", "ledge_down_700", "ledge_down_1000", "rail_down_100", "rail_down_200", "rail_down_300", "rail_down_400", "rail_down_500", "rail_down_700", "rail_down_1000", "rail_up_100", "rail_up_200", "rail_up_300", "rail_up_400", "rail_up_500", "rail_up_700", "rail_up_1000", "jump_forward_100", "jump_forward_200", "jump_forward_300", "jump_forward_400", "jump_forward_500", "jump_forward_700", "jump_forward_1000", "jump_forward_300_down_300", "jump_forward_300_down_500", "jump_forward_300_up_300", "jump_forward_300_up_500", "jump_forward_500_down_300", "jump_forward_500_down_500", "jump_forward_500_up_300", "jump_forward_500_up_500", "jump_forward_1000_down_1000", "jump_forward_1000_up_1000" };

// For Dedicated Traversal Chain tab
const QStringList linkAnimationsArachnotron = { "ceiling_hangout/floor_to_ceiling", "ceiling_hangout/ceiling_to_floor", "ceiling_hangout/ceiling_to_wall_center", "ceiling_hangout/ceiling_to_wall_left", "ceiling_hangout/ceiling_to_wall_right", "wall_hangout/floor_to_wall", "wall_hangout/wall_to_ceiling", "wall_hangout/wall_to_floor", "wall_hangout/custom_wall_left_to_ceiling_90", "wall_hangout/custom_wall_center_to_ceiling_90", "wall_hangout/custom_wall_right_to_ceiling_90", "wall_hangout/custom_wall_left_to_floor_90", "wall_hangout/custom_wall_center_to_floor_90", "wall_hangout/custom_wall_right_to_floor_90", "wall_hangout/custom_floor_to_wall_left_90", "wall_hangout/custom_floor_to_wall_center_90", "wall_hangout/custom_floor_to_wall_right_90", "traversal/ledge_up_100", "traversal/ledge_up_200", "traversal/ledge_up_300", "traversal/ledge_up_400", "traversal/ledge_up_500", "traversal/ledge_up_700", "traversal/ledge_up_1000", "traversal/ledge_down_100", "traversal/ledge_down_200", "traversal/ledge_down_300", "traversal/ledge_down_400", "traversal/ledge_down_500", "traversal/ledge_down_700", "traversal/ledge_down_1000", "traversal/rail_down_100", "traversal/rail_down_200", "traversal/rail_down_300", "traversal/rail_down_400", "traversal/rail_down_500", "traversal/rail_down_1000", "traversal/rail_down_700", "traversal/rail_up_100", "traversal/rail_up_200", "traversal/rail_up_300", "traversal/rail_up_400", "traversal/rail_up_500", "traversal/rail_up_700", "traversal/rail_up_1000", "traversal/jump_forward_100", "traversal/jump_forward_200", "traversal/jump_forward_2000", "traversal/jump_forward_300", "traversal/jump_forward_400", "traversal/jump_forward_500", "traversal/jump_forward_700", "traversal/jump_forward_1000", "traversal/ledge_forward_300_down_300", "traversal/ledge_forward_300_down_500", "traversal/ledge_forward_300_up_300", "traversal/ledge_forward_300_up_500", "traversal/ledge_forward_500_down_300", "traversal/ledge_forward_500_down_500", "traversal/ledge_forward_500_up_300", "traversal/ledge_forward_500_up_500", "traversal/ledge_forward_1000_down_1000", "traversal/ledge_forward_1000_up_1000", "traversal/window_forward_700_up_200", "traversal/window_forward_700_up_300", "traversal/window_forward_700_up_500", "traversal/window_forward_800_up_500" };
const QStringList idleAnimationsArachnotron = { "NONE", "ceiling_hangout/ceiling_idle", "wall_hangout/idle", "traversal/to_idle" };
const QStringList linkAnimationsImp = { "wallclimbright/wcr_climb_right_250_wcr", "wallclimbright/wcr_jump_down_right_250", "wallclimbleft/wcl_climb_left_250_wcl", "wallclimbleft/wcl_jump_down_left_250", "wallclimb/wc_climb_250_wc", "wallclimb/wc_climb_up_250_to_pch", "wallclimb/wc_climb_up_250_turn_180_to_pch", "wallclimb/wc_climb_up_ledge_250", "wallclimb/wc_into_wl", "wallclimb/wc_into_wr", "wallclimb/wc_jump_back_1000_wc", "wallclimb/wc_jump_back_500", "wallclimb/wc_jump_back_500_wc", "wallclimb/wc_jump_back_down_250", "wallclimb/wc_jump_back_down_500", "wallclimb/wc_jump_back_down_500_for_chain", "wallclimb/wc_jump_left_down_250", "wallclimb/wc_jump_right_down_250", "wallclimbdown/wcd_climb_down45_250_wcd", "wallclimbdown/wcd_climb_down_250_wcd", "wallclimbdown/wcd_hang_down_drop_750", "wallclimbdown/wcd_jump_down_250", "poleclimb/pc_climb_250_pc", "poleclimb/pc_climb_250_rotate_90_left_pc", "poleclimb/pc_climb_250_rotate_90_leftb_pc", "poleclimb/pc_climb_250_rotate_90_right_pc", "poleclimb/pc_climb_250_rotate_90_rightb_pc", "poleclimb/pc_climb_250b_pc", "poleclimb/pc_climb_streetlight_left_to_pch", "poleclimb/pc_climb_streetlight_right_to_pch", "poleclimb/pc_into_pl", "poleclimb/pc_into_pr", "poleclimb/pc_jump_back_500", "poleclimb/pc_jump_back_500_down_375", "poleclimb/pc_jump_back_500_to_wc", "poleclimb/pc_jump_back_down_500", "poleclimb/pc_rotate_right_180_pc", "perch/pch_jump_down_500", "perch/pch_jump_down_750", "perch/pch_jump_forward_500_down_500", "perch/pch_jump_left_250_to_pch", "perch/pch_jump_left_250b_to_pch", "perch/pch_jump_left_500_to_pch", "perch/pch_jump_left_500b_to_pch", "perch/pch_jump_right_250_to_pch", "perch/pch_jump_right_250_turn_180_to_pch", "perch/pch_jump_right_250b_to_pch", "perch/pch_jump_right_500_to_pc", "perch/pch_jump_right_500_to_pch", "perch/pch_jump_right_500b_to_pch", "traversal/jump_ledge_up_100", "traversal/jump_ledge_up_200", "traversal/jump_ledge_up_300", "traversal/jump_ledge_up_400", "traversal/jump_ledge_up_500", "traversal/jump_ledge_up_700", "traversal/jump_ledge_up_1000", "traversal/jump_ledge_down_100", "traversal/jump_ledge_down_200", "traversal/jump_ledge_down_300", "traversal/jump_ledge_down_400", "traversal/jump_ledge_down_500", "traversal/jump_ledge_down_700", "traversal/jump_ledge_down_1000", "traversal/jump_rail_down_100", "traversal/jump_rail_down_200", "traversal/jump_rail_down_300", "traversal/jump_rail_down_400", "traversal/jump_rail_down_500", "traversal/jump_rail_down_700", "traversal/jump_rail_down_1000", "traversal/jump_rail_up_100", "traversal/jump_rail_up_200", "traversal/jump_rail_up_300", "traversal/jump_rail_up_400", "traversal/jump_rail_up_500", "traversal/jump_rail_up_700", "traversal/jump_rail_up_1000", "traversal/jump_forward_100", "traversal/jump_forward_200", "traversal/jump_forward_300", "traversal/jump_forward_400", "traversal/jump_forward_500", "traversal/jump_forward_700", "traversal/jump_forward_1000", "traversal/jump_forward_300_down_300", "traversal/jump_forward_300_down_500", "traversal/jump_forward_300_up_300", "traversal/jump_forward_300_up_500", "traversal/jump_forward_500_down_300", "traversal/jump_forward_500_down_500", "traversal/jump_forward_500_up_300", "traversal/jump_forward_500_up_500", "traversal/jump_forward_1000_down_1000", "traversal/jump_forward_1000_up_1000" };
const QStringList idleAnimationsImp = { "NONE", "wallclimb_hangout/idle", "upright_hangout/idle", "poleclimb_hangout/idle", "perch/pch_idle_pch" };

// For InfoPath tab
const QStringList walkStates = { "WALKSTATE_WALKING", "WALKSTATE_RUNNING", "WALKSTATE_SPRINTING", "WALKSTATE_NOCLIP" };
const QStringList navSizes = { "NAVSIZE_SMALL", "NAVSIZE_MEDIUM", "NAVSIZE_LARGE", "NAVSIZE_SUPER" };

// Quick int to char (to string) conversion
const std::vector<std::string> numToLetterStr = { "0", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };


// For storing the index of the animation, rather than the animation string itself, as there are variations between monster types for equivalent animations
std::vector<int> tempAnimList;


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

    // Set Imp tab in dedicated traversal chains as default
    ui->tabWidget_TraversalChainHang->setCurrentIndex(0);

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
    ui->pushButton_addChain->setEnabled(false);
    ui->pushButtonForTesting->setEnabled(false);
    ui->comboBox_linkAnimsArachnotron->addItems(linkAnimationsArachnotron);
    ui->comboBox_idleAnimsArachnotron->addItems(idleAnimationsArachnotron);
    ui->pushButton_addChain_Imp->setEnabled(false);
    ui->pushButtonToMakeHangImp->setEnabled(false);
    ui->comboBox_linkAnimsImp->addItems(linkAnimationsImp);
    ui->comboBox_idleAnimsImp->addItems(idleAnimationsImp);

    // For Path Info
    ui->comboBox_InfoPath_WalkState->addItems(walkStates);
    ui->comboBox_InfoPath_NavSize->addItems(navSizes);
    ui->pushButton_Add_InfoPath->setEnabled(false);
    ui->pushButton_Generate_InfoPath->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
    TRAVERSAL INFO TAB
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

// Check if the current inputs for the Traversal Info tab are valid
bool isInputValidInfo(Ui::MainWindow *ui)
{
    // Check if the start coords are valid
    bool areStartCoordsValid = areCoordsValid(ui->inputStartCoords->text().toStdString());

    // Check if the end coords are valid
    bool areEndCoordsValid = areCoordsValid(ui->inputEndCoords->text().toStdString());

    return areStartCoordsValid && areEndCoordsValid;
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

// Clear the output files
void MainWindow::on_buttonClearOutput_clicked() // Traversal Info button
{
    std::fstream output("Output/Traversal Info.txt", std::fstream::out);
    output << "";
    output.close();
}

// clearCoords
void MainWindow::on_buttonClearCoords_clicked() // Traversal Info button
{
    ui->inputStartCoords->clear();
    ui->inputEndCoords->clear();
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


/*
    TRAVERSAL CHAIN (GENERAL) TAB
*/

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
void MainWindow::on_buttonClearOutputChain_clicked() // Traversal Chain button
{
    std::fstream output("Output/Traversal Chains (General).txt", std::fstream::out);
    output << "";
    output.close();
}

// clearCoords
void MainWindow::on_buttonClearCoordsAndAnims_clicked() // Traversal Chain button
{
    ui->inputMidCoordsChain->clear();
    ui->inputEndCoordsChain->clear();
    ui->listWidgetMidpoints->clear();
    ui->listWidgetMidAnims->clear();
    tempAnimList.clear();
}

// Check if the start and end coords for the Traversal Chain are valid
bool isInputValidChain(Ui::MainWindow *ui)
{
    // Check if the end coords are valid
    bool areEndCoordsValid = areCoordsValid(ui->inputEndCoordsChain->text().toStdString());

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

    generateTraversalChain(entityObjects, lastEntity, monsterIndices, false);

    auto reciprocalTraversal = ui->selectReciprocalTraversalChain->isChecked();
    if(reciprocalTraversal)
    {
        auto size_r = entityObjects.size() - 1;
        std::vector<idInfo_TraversalChain_General> entityObjects_r;

        idInfo_TraversalChain_General firstEntity_r;
        firstEntity_r.entityName = "mod_traversal_chain_" + entityName + "_" + numToLetterStr[size_r+2] + "_r";
        firstEntity_r.coordinates = lastEntity.coordinates;
        firstEntity_r.animationIndex = entityObjects[size_r].animationIndex;

        entityObjects_r.push_back(firstEntity_r);

        for (int i = static_cast<int>(size_r); i > 0; i--)
        {
            idInfo_TraversalChain_General tempObject_r;
            tempObject_r.entityName = entityObjects[i].entityName + "_r";
            tempObject_r.coordinates = entityObjects[i].coordinates;
            tempObject_r.animationIndex = entityObjects[i-1].animationIndex;

            entityObjects_r.push_back(tempObject_r);
        }

        idInfo_TraversalPoint lastEntity_r;
        lastEntity_r.entityName = lastEntity.entityName + "_r";
        lastEntity_r.coordinates = entityObjects[0].coordinates;

        generateTraversalChain(entityObjects_r, lastEntity_r, monsterIndices, true);
    }
}


/*
    TRAVERSAL CHAIN (DEDICATED) TAB
*/

// Clear output file (affects all sub-tabs)
void MainWindow::on_pushButtonClearOutputHang_clicked()
{
    std::fstream output("Output/Traversal Chains (Dedicated).txt", std::fstream::out);
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
     ui->inputCoordsLandArachnotron->clear();
}

// Check if the coords for the Arachnotron Traversal Chain are valid
bool isInputValidHangArachnotron(Ui::MainWindow *ui)
{
    bool areChainCoordsValid = areCoordsValid(ui->inputCoordsHangArachnotron->text().toStdString());

    return areChainCoordsValid;
}

// Check if the coords for the Arachnotron landing point
bool isInputValidHangLandArachnotron(Ui::MainWindow *ui)
{
    // Check if the end coords are valid
    bool areEndCoordsValid = areCoordsValid(ui->inputCoordsLandArachnotron->text().toStdString());

    bool wasMidpointAdded = ui->listWidget_hangCoordsArachnotron->count();

    return areEndCoordsValid && wasMidpointAdded;
}

// When the Arachnotron's Traversal Chain coords are changed, check if they are valid
void MainWindow::on_inputCoordsHangArachnotron_textChanged(const QString &arg1)
{
    ui->pushButton_addChain->setEnabled(isInputValidHangArachnotron(ui));
    ui->pushButtonForTesting->setEnabled(isInputValidHangLandArachnotron(ui));
}
// When the Imp's landing coords are changed, check if they are valid
void MainWindow::on_inputCoordsLandArachnotron_textChanged(const QString &arg1)
{
    ui->pushButtonForTesting->setEnabled(isInputValidHangLandArachnotron(ui));
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

// Add Imp traversal chain to list
void MainWindow::on_pushButton_addChain_Imp_clicked()
{
    ui->listWidget_hangCoordsImp->addItem(ui->inputCoordsHangImp->text());
    ui->listWidget_hangLinkImp->addItem(ui->comboBox_linkAnimsImp->currentText());
    ui->listWidget_hangIdleImp->addItem(ui->comboBox_idleAnimsImp->currentText());
    ui->inputCoordsHangImp->clear();
}

// Clear Imp traversal chains
void MainWindow::on_pushButton_clearHangImp_clicked()
{
    ui->listWidget_hangCoordsImp->clear();
    ui->listWidget_hangLinkImp->clear();
    ui->listWidget_hangIdleImp->clear();
    ui->inputCoordsLandImp->clear();
}

// Check if the coords for the Imp Traversal Chain are valid
bool isInputValidHangImp(Ui::MainWindow *ui)
{
    bool areChainCoordsValid = areCoordsValid(ui->inputCoordsHangImp->text().toStdString());

    return areChainCoordsValid;
}

// Check if the coords for the Imp landing point
bool isInputValidHangLandImp(Ui::MainWindow *ui)
{
    // Check if the end coords are valid
    bool areEndCoordsValid = areCoordsValid(ui->inputCoordsLandImp->text().toStdString());

    bool wasMidpointAdded = ui->listWidget_hangCoordsImp->count();

    return areEndCoordsValid && wasMidpointAdded;
}

// When the Imp's Traversal Chain coords are changed, check if they are valid
void MainWindow::on_inputCoordsHangImp_textChanged(const QString &arg1)
{
    ui->pushButton_addChain_Imp->setEnabled(isInputValidHangImp(ui));
    ui->pushButtonToMakeHangImp->setEnabled(isInputValidHangLandImp(ui));
}
// When the Imp's landing coords are changed, check if they are valid
void MainWindow::on_inputCoordsLandImp_textChanged(const QString &arg1)
{
    ui->pushButtonToMakeHangImp->setEnabled(isInputValidHangLandImp(ui));
}

/*
    PATH INFO TAB
*/

// Add Path Info to list
void MainWindow::on_pushButton_Add_InfoPath_clicked()
{
    ui->listWidget_InfoPath_Coords->addItem(ui->lineEdit_InfoPath_Coords->text());
    ui->listWidget_InfoPath_WalkState->addItem(ui->comboBox_InfoPath_WalkState->currentText());
    ui->listWidget_InfoPath_NavSize->addItem(ui->comboBox_InfoPath_NavSize->currentText());
    ui->lineEdit_InfoPath_Coords->clear();
}

// Check if the coords for the Path Info are valid
bool isInputValidInfoPath(Ui::MainWindow *ui)
{
    bool arePathCoordsValid = areCoordsValid(ui->lineEdit_InfoPath_Coords->text().toStdString());

    return arePathCoordsValid;
}

// Check if any Path Info were added
bool checkAddedPaths(Ui::MainWindow *ui)
{
    bool wasPathAdded = ui->listWidget_InfoPath_Coords->count();
    return wasPathAdded;
}

// When the Path Info's coords are changed, check if they are valid, and enable the "Add Path Info" and "Generate Path Info" buttons
void MainWindow::on_lineEdit_InfoPath_Coords_textChanged(const QString &arg1)
{
    ui->pushButton_Add_InfoPath->setEnabled(isInputValidInfoPath(ui));
    ui->pushButton_Generate_InfoPath->setEnabled(checkAddedPaths(ui));
}

// Clear Path Info
void MainWindow::on_pushButton_Clear_InfoPath_clicked()
{
    ui->listWidget_InfoPath_Coords->clear();
    ui->listWidget_InfoPath_WalkState->clear();
    ui->listWidget_InfoPath_NavSize->clear();
    ui->pushButton_Generate_InfoPath->setEnabled(checkAddedPaths(ui));
}

// Clear output file for Path Info
void MainWindow::on_pushButton_ClearOutput_InfoPath_clicked()
{
    std::fstream output("Output/Info Path.txt", std::fstream::out);
    output << "";
    output.close();
}


void MainWindow::on_pushButton_Generate_InfoPath_clicked()
{
    auto entityName = ui->lineEdit_InfoPath_EntityName->text().toStdString();
    std::vector<idInfoPath> entityObjects;

    for (int i = 0; i < ui->listWidget_InfoPath_Coords->count(); i++)
    {
        idInfoPath tempObject;
        tempObject.entityName = "mod_info_path_" + entityName + "_" + numToLetterStr[i+1];
        tempObject.coordinates = stringToVector(ui->listWidget_InfoPath_Coords->item(i)->text().toStdString());
        tempObject.walkState = ui->listWidget_InfoPath_WalkState->item(i)->text().toStdString();
        tempObject.navSize = ui->listWidget_InfoPath_NavSize->item(i)->text().toStdString();

        entityObjects.push_back(tempObject);
    }

    generateInfoPath(entityObjects);
}

