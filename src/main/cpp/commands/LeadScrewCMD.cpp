/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LeadScrewCMD.h"
#include "Robot.h"

LeadScrewCMD::LeadScrewCMD() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_leadScrew.get());
  }

// Called just before this Command runs the first time
void LeadScrewCMD::Initialize() 
{
  Robot::m_leadScrew->StopScrews();
}

// Called repeatedly when this Command is scheduled to run
void LeadScrewCMD::Execute() 
{
  Robot::m_leadScrew->TeleopScrew(Robot::m_oi.GetController());
}

// Make this return true when this Command no longer needs to run execute()
bool LeadScrewCMD::IsFinished() 
{ 
  return false; 
}

// Called once after isFinished returns true
void LeadScrewCMD::End() 
{
  Robot::m_leadScrew->StopScrews();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LeadScrewCMD::Interrupted() 
{

}
