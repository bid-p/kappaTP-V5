#ifndef DRIVE_DEFINE_GUARD
#define DRIVE_DEFINE_GUARD

#include "api.h"
#include "okapi/api.hpp"
#include "ports.hpp"

using namespace okapi;

Motor driveR1(MPORT_DRIVE_R1, true, AbstractMotor::gearset::green,
              AbstractMotor::encoderUnits::degrees);
Motor driveR2(MPORT_DRIVE_R2, true, AbstractMotor::gearset::green,
              AbstractMotor::encoderUnits::degrees);
Motor driveR3(MPORT_DRIVE_R3, true, AbstractMotor::gearset::green,
              AbstractMotor::encoderUnits::degrees);
Motor driveL1(MPORT_DRIVE_L1, false, AbstractMotor::gearset::green,
              AbstractMotor::encoderUnits::degrees);
Motor driveL2(MPORT_DRIVE_L2, false, AbstractMotor::gearset::green,
              AbstractMotor::encoderUnits::degrees);
Motor driveL3(MPORT_DRIVE_L3, false, AbstractMotor::gearset::green,
              AbstractMotor::encoderUnits::degrees);

auto chassis = ChassisControllerFactory::create(
    {MPORT_DRIVE_L1, MPORT_DRIVE_L2, MPORT_DRIVE_L3},    // Left Motors
    {-MPORT_DRIVE_R1, -MPORT_DRIVE_R2, -MPORT_DRIVE_R3}, // Right Motors
    AbstractMotor::gearset::green,                       // 200 RPM
    {4_in, 12.5_in} // 4 in wheels and 12.5 in wheelbase width
);

void changeDriveState();
void checkDriveState();
void driveTank();
void updateDrive();

#endif
