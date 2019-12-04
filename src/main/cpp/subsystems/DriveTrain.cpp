/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include "frc/smartdashboard/SmartDashboard.h"

using namespace frc;

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem") {}



void DriveTrain::TeleopDrive(XboxController* m_joyStick)
{
  double leftY = m_joyStick->GetY(GenericHID::kLeftHand);
  double rightY = m_joyStick->GetY(GenericHID::kRightHand);
  m_driveLeft.Set(-0.6*leftY);
  m_driveRight.Set(0.6*rightY);

  double distance = m_lidar.Get();
  SmartDashboard::PutNumber("Lidar", distance);
}

void DriveTrain::StopDriveMotors()
{
  m_driveLeft.Set(0.0);
  m_driveRight.Set(0.0);
}

void DriveTrain::LidarLite()
{
  m_pCounter = new frc::Counter(&m_lidar);
  m_pCounter->SetMaxPeriod(1.0);
  m_pCounter->SetSemiPeriodMode(true);
  m_pCounter->Reset();
}

void DriveTrain::GetDistance()
{
  double centimetres;
  centimetres = (m_pCounter->GetPeriod() * 1000000.0 / 10.0);
  SmartDashboard::PutNumber("distance", centimetres);
}

void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
