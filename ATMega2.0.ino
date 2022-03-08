#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial linkSerial(10, 11);
double fsrForce1;
double fsrForce2;
double fsrForce3;
double fsrForce4;
double fsrForce5;
double fsrForce6;

void setup()
{
  Serial.begin(115200);
  pinMode(13, OUTPUT);
}
void loop()
{
  {
    int analogResult1 = analogRead(14);
    int fsrVoltage1;
    unsigned long fsrResistance1;
    unsigned long fsrConductance1;
    Serial.print("Analog reading = ");
    Serial.println(analogResult1);

    fsrVoltage1 = map(analogResult1, 0, 1023, 0, 5000);
    Serial.print("Voltage reading in mV = ");
    Serial.println(fsrVoltage1);

    if (fsrVoltage1 == 0)
    {
      Serial.println("No pressure");
    }
    else
    {
      fsrResistance1 = 5000 - fsrVoltage1;
      fsrResistance1 *= 10000;
      fsrResistance1 /= fsrVoltage1;
      Serial.print("FSR resistance in ohms = ");
      Serial.println(fsrResistance1);

      fsrConductance1 = 1000000;
      fsrConductance1 /= fsrResistance1;
      Serial.print("Conductance in microMhos: ");
      Serial.println(fsrConductance1);
      if (fsrConductance1 <= 1000)
      {
        fsrForce1 = (fsrConductance1 / 80) * 0.10197;
        Serial.print("Force in Kilogram: ");
        Serial.println(fsrForce1);
      }
      else
      {
        fsrForce1 = fsrConductance1 - 1000;
        fsrForce1 /= 30;
        Serial.print("Force in Kilogram: ");
        Serial.println(fsrForce1);
      }
    }
  }
  {
    int analogResult2 = analogRead(15);
    int fsrVoltage2;
    unsigned long fsrResistance2;
    unsigned long fsrConductance2;
    Serial.print("Analog reading = ");
    Serial.println(analogResult2);
    fsrVoltage2 = map(analogResult2, 0, 1023, 0, 5000);
    Serial.print("Voltage reading in mV = ");
    Serial.println(fsrVoltage2);

    if (fsrVoltage2 == 0)
    {
      Serial.println("No pressure");
    }
    else
    {
      fsrResistance2 = 5000 - fsrVoltage2;
      fsrResistance2 *= 10000;
      fsrResistance2 /= fsrVoltage2;
      Serial.print("FSR resistance in ohms = ");
      Serial.println(fsrResistance2);

      fsrConductance2 = 1000000;
      fsrConductance2 /= fsrResistance2;
      Serial.print("Conductance in microMhos: ");
      Serial.println(fsrConductance2);
      if (fsrConductance2 <= 1000)
      {
        fsrForce2 = (fsrConductance2 / 80) * 0.10197;
        Serial.print("Force in Kilogram: ");
        Serial.println(fsrForce2);
      }
      else
      {
        fsrForce2 = fsrConductance2 - 1000;
        fsrForce2 /= 30;
        Serial.print("Force in Kilogram: ");
        Serial.println(fsrForce2);
      }
    }
  }
  {
    int analogResult3 = analogRead(16);
    int fsrVoltage3;
    unsigned long fsrResistance3;
    unsigned long fsrConductance3;
    Serial.print("Analog reading = ");
    Serial.println(analogResult3);
    fsrVoltage3 = map(analogResult3, 0, 1023, 0, 5000);
    Serial.print("Voltage reading in mV = ");
    Serial.println(fsrVoltage3);

    if (fsrVoltage3 == 0)
    {
      Serial.println("No pressure");
    }
    else
    {
      fsrResistance3 = 5000 - fsrVoltage3;
      fsrResistance3 *= 10000;
      fsrResistance3 /= fsrVoltage3;
      Serial.print("FSR resistance in ohms = ");
      Serial.println(fsrResistance3);

      fsrConductance3 = 1000000;
      fsrConductance3 /= fsrResistance3;
      Serial.print("Conductance in microMhos: ");
      Serial.println(fsrConductance3);
      if (fsrConductance3 <= 1000)
      {
        fsrForce3 = (fsrConductance3 / 80) * 0.10197;
        Serial.print("Force in Kilogram: ");
        Serial.println(fsrForce3);
      }
      else
      {
        fsrForce3 = fsrConductance3 - 1000;
        fsrForce3 /= 30;
        Serial.print("Force in Kilogram: ");
        Serial.println(fsrForce3);
      }
    }
  }
  {
    int analogResult4 = analogRead(17);
    int fsrVoltage4;
    unsigned long fsrResistance4;
    unsigned long fsrConductance4;
    Serial.print("Analog reading = ");
    Serial.println(analogResult4);
    fsrVoltage4 = map(analogResult4, 0, 1023, 0, 5000);
    Serial.print("Voltage reading in mV = ");
    Serial.println(fsrVoltage4);

    if (fsrVoltage4 == 0)
    {
      Serial.println("No pressure");
    }
    else
    {

      fsrResistance4 = 5000 - fsrVoltage4;
      fsrResistance4 *= 10000;
      fsrResistance4 /= fsrVoltage4;
      Serial.print("FSR resistance in ohms = ");
      Serial.println(fsrResistance4);

      fsrConductance4 = 1000000;
      fsrConductance4 /= fsrResistance4;
      Serial.print("Conductance in microMhos: ");
      Serial.println(fsrConductance4);
      if (fsrConductance4 <= 1000)
      {
        fsrForce4 = (fsrConductance4 / 80) * 0.10197;
        Serial.print("Force in Kilogram: ");
        Serial.println(fsrForce4);
      }
      else
      {
        fsrForce4 = fsrConductance4 - 1000;
        fsrForce4 /= 30;
        Serial.print("Force in Kilogram: ");
        Serial.println(fsrForce4);
      }
    }
  }
  {
    int analogResult5 = analogRead(18);
    int fsrVoltage5;
    unsigned long fsrResistance5;
    unsigned long fsrConductance5;
    Serial.print("Analog reading = ");
    Serial.println(analogResult5);
    fsrVoltage5 = map(analogResult5, 0, 1023, 0, 5000);
    Serial.print("Voltage reading in mV = ");
    Serial.println(fsrVoltage5);

    if (fsrVoltage5 == 0)
    {
      Serial.println("No pressure");
    }
    else
    {

      fsrResistance5 = 5000 - fsrVoltage5;
      fsrResistance5 *= 10000;
      fsrResistance5 /= fsrVoltage5;
      Serial.print("FSR resistance in ohms = ");
      Serial.println(fsrResistance5);

      fsrConductance5 = 1000000;
      fsrConductance5 /= fsrResistance5;
      Serial.print("Conductance in microMhos: ");
      Serial.println(fsrConductance5);
      if (fsrConductance5 <= 1000)
      {
        fsrForce5 = (fsrConductance5 / 80) * 0.10197;
        Serial.print("Force in Kilogram: ");
        Serial.println(fsrForce5);
      }
      else
      {
        fsrForce5 = fsrConductance5 - 1000;
        fsrForce5 /= 30;
        Serial.print("Force in Kilogram: ");
        Serial.println(fsrForce5);
      }
    }
  }
  {
    int analogResult6 = analogRead(19);
    int fsrVoltage6;
    unsigned long fsrResistance6;
    unsigned long fsrConductance6;
    Serial.print("Analog reading = ");
    Serial.println(analogResult6);
    fsrVoltage6 = map(analogResult6, 0, 1023, 0, 5000);
    Serial.print("Voltage reading in mV = ");
    Serial.println(fsrVoltage6);

    if (fsrVoltage6 == 0)
    {
      Serial.println("No pressure");
    }
    else
    {

      fsrResistance6 = 5000 - fsrVoltage6;
      fsrResistance6 *= 10000;
      fsrResistance6 /= fsrVoltage6;
      Serial.print("FSR resistance in ohms = ");
      Serial.println(fsrResistance6);

      fsrConductance6 = 1000000;
      fsrConductance6 /= fsrResistance6;
      Serial.print("Conductance in microMhos: ");
      Serial.println(fsrConductance6);
      if (fsrConductance6 <= 1000)
      {
        fsrForce6 = (fsrConductance6 / 80) * 0.10197;
        Serial.print("Force in Kilogram: ");
        Serial.println(fsrForce6);
      }
      else
      {
        fsrForce6 = fsrConductance6 - 1000;
        fsrForce6 /= 30;
        Serial.print("Force in Kilogram: ");
        Serial.println(fsrForce6);
      }
    }
  }
  StaticJsonDocument<200> doc;
  doc["fsr1"] = fsrForce1;
  doc["fsr2"] = fsrForce2;
  doc["fsr3"] = fsrForce3;
  doc["fsr4"] = fsrForce4;
  doc["fsr5"] = fsrForce5;
  doc["fsr6"] = fsrForce6;
  serializeJson(doc, Serial);
  Serial.println("--------------------");
  delay(1000);
}
