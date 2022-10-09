#pragma once

#include <rev/CANSparkMax.h>
#include <wpi/numbers>
#include <frc/controller/PIDController.h>

namespace hb {
  class NeoMotor : public rev::CANSparkMax, public rev::SparkMaxRelativeEncoder{
    public:
    
      explicit NeoMotor(const int& Id, rev::CANSparkMax::MotorType type);

      /**
       * @brief this method is used to set the conversion from RPM to MPS
       * to do this we get the gear ratio * 2pi * wheel diameter(meters)
       * 
       * @param ratio
       */
      void SetRPM2MPS(const double&);

      /**
       * @brief calling this function will multiply the rotations per second of the
       * motor by the set ratio of RPM2MPS set in the SetRPM2MPS method
       * 
       * @return Meters per second
       */
      double GetRate() const;

      /**
       * @brief Sets the Motor RPM using frc2::PIDController
       * 
       * @param RPM
       */
      void SetRPMpid(double&);

    private:
      double m_Ratio = 1;
      frc2::PIDController m_PID{1 , 0 , 0};
  }; // class NeoMotor
} // namespace hb