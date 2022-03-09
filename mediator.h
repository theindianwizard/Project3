#ifndef MEDIATOR_H_INCLUDED
#define MEDIATOR_H_INCLUDED

class CarPart;
class Engine;
class Electric;
class Radio;
class SteeringWheel;
class Wheels;
class Brakes;
class Headlights;
class Airconditioner;
class Road;

class Mediator {
    public:
        Engine *MyEngine;
        Electric *MyElectric;
        Radio *MyRadio;
        SteeringWheel *MySteeringWheel;
        Wheels *MyWheels;
        Brakes *MyBrakes;
        Headlights *MyHeadlights;
        Airconditioner *MyAirconditioner;
        Road *MyRoad;
        Mediator();
        void PartChanged(CarPart *part);
};

class CarControls : public Mediator {
    public:
        void StartCar();
        void StopCar();
        void PushGasPedal(int amount);
        void ReleaseGasPedal(int amount);
        void PressBrake(int amount);
        void Turn(int amount);
        void TurnOnRadio();
        void TurnOffRadio();
        void AdjustRadioVolume(int amount);
        void TurnOnHeadlights();
        void TurnOffHeadlights();
        void ClimbHill(int angle);
        void DescendHill(int angle);
        void TurnOnAC();
        void TurnOffAC();
        void AdjustAC(int amount);
        int GetSpeed(int amount);
        CarControls() : Mediator() {}
};
#endif \\MEDIATOR_H_INCLUDED