/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Talon.h>
#include <frc/Counter.h>
#include <frc/DigitalInput.h>
#include <frc/XboxController.h>
#include "RobotMap.h"

using namespace frc;

class DriveTrain : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  // Talon Motors w/ Port Numbers
  Talon m_driveLeft {DRIVE_LEFT};
  Talon m_driveRight {DRIVE_RIGHT};
  DigitalInput m_lidar {LIDAR};
  Counter* m_pCounter;

 public:
 // Definition of commands
  DriveTrain();
  void LidarLite();
  void GetDistance();
  void TeleopDrive(XboxController* m_joyStick);
  void StopDriveMotors();
  void InitDefaultCommand() override;
};
