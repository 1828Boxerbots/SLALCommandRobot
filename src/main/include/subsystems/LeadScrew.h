/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/XboxController.h>
#include <frc/Talon.h>
#include <frc/DigitalInput.h>
#include "RobotMap.h"

using namespace frc;

class LeadScrew : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  // Talon Motors w/ Port Numbers
  Talon m_leftScrew {SCREW_LEFT};
  Talon m_rightScrew {SCREW_RIGHT};
  DigitalInput m_topLimit {TOP_LIMIT};
  DigitalInput m_bottomLimit{BOTTOM_LIMIT};
 public:
  LeadScrew();
  void TeleopScrew(XboxController* m_joyStick);
  void StopScrews();
  void InitDefaultCommand() override;
};
