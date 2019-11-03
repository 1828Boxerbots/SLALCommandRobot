/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/LeadScrew.h"
#include <frc/smartdashboard/SmartDashboard.h>

LeadScrew::LeadScrew() : Subsystem("ExampleSubsystem") {}

void LeadScrew::TeleopScrew(XboxController* m_joyStick)
{
 bool topLimit = m_topLimit.Get();
  bool bottomLimit = m_bottomLimit.Get();
  SmartDashboard::PutBoolean("TopLimit", topLimit);
  SmartDashboard::PutBoolean("BottomLimit", bottomLimit);

  bool rightBumper = m_joyStick->GetBumper(GenericHID::kRightHand);
  bool leftBumper = m_joyStick->GetBumper(GenericHID::kLeftHand);

  if (((topLimit  == true) && (bottomLimit == true)) || ((topLimit == false) && (bottomLimit == false)))
  {
    if (((rightBumper  == true) && (leftBumper == true)) || ((rightBumper == false) && (leftBumper == false)))
    {
      m_leftScrew.Set(0.0);
      m_rightScrew.Set(0.0);
    }
    else
    {
      if (leftBumper == true)
      {
        m_leftScrew.Set(-0.75);
        m_rightScrew.Set(-0.75);
      }
      if (rightBumper == true)
      {
        m_leftScrew.Set(.75);
        m_rightScrew.Set(.75);
      }
    }
  }
  else
  {
    if (topLimit == true)
    {
      if (leftBumper == true)
      {
        m_leftScrew.Set(-0.75);
        m_rightScrew.Set(-0.75);
      }
      else
      {
        m_leftScrew.Set(0);
        m_rightScrew.Set(0);
      }
    }
    if (bottomLimit == true)
    {
      if (rightBumper == true)
      {
        m_leftScrew.Set(.75);
        m_rightScrew.Set(.75);
      }
      else
      {
        m_leftScrew.Set(0);
        m_rightScrew.Set(0);
      }
    }
  }
}

void LeadScrew::StopScrews()
{
  m_leftScrew.Set(0.0);
  m_rightScrew.Set(0.0);
}

void LeadScrew::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
