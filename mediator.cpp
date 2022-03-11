#include <iostream>
#include "mediator.h"
#include "carparts.h"

using namespace std;

Mediator::Mediator() { 
    MyEngine = new Engine(this);
    MyElectric = new Electric(this);
    MyRadio = new Radio(this);
    MyWheels = new Wheels(this);
    MyBrakes = new Brakes(this);
    MyHeadlights = new Headlights(this);
    MyAirconditioner = new Airconditioner(this);
    MyRoad = new Road(this);
}

void Mediator::PartChanged(CarPart *part) {
    if (part == MyEngine) {
        if (MyEngine -> RPM == 0){
            MyWheels -> Speed = 0;
            return;
        }

        if (MyEngine -> Revamount){
        return;
        }

        MyElectric->ChangeOutputBy(MyEngine -> Revamount / 10);
        if (MyEngine -> Revamount > 0){
            MyWheels -> Accelerate(MyEngine -> Revamount / 50);
        }
    }
    else if (part == MyElectric){
        if (MyHeadlights -> Brightness > 0) {
            MyHeadlights->Adjust(MyElectric -> ChangedBy / 20);
        }
        if (MyRadio->Volume > 0){
            MyRadio-> AdjustVolume(MyElectric-> ChangedBy / 30);
        }
    }
    else if (part == MyBrakes){
        MyWheels -> Decelerate(MyBrakes -> Pressure / 5);
    }
    else if(part == MyAirconditioner){
        MyElectric -> ChangeOutputBy(0 - MyAirconditioner->ChangedBy*2);
    }
    else if (part == MyRoad) {
        if (MyRoad -> ClimbAngle > 0){
            MyWheels -> Decelerate(MyRoad -> ClimbAngle * 2);
            MyRoad -> ClimbAngle = 0;
        }
        else if (MyRoad -> ClimbAngle < 0){
            MyWheels -> Accelerate(MyRoad -> ClimbAngle * -4);
            MyRoad -> ClimbAngle = 0;
        }
    }
}

void  CarControls :: StartCar(){
    MyEngine -> Start();
}

void CarControls :: StopCar() {
    MyEngine -> Stop();
}

void  CarControls :: PushGasPedal(int amount) {
    MyEngine -> PushGasPedal(amount);
}

void  CarControls :: ReleaseGasPedal(int amount){
    MyEngine -> ReleaseGasPedal(amount);
}

void  CarControls :: PressBrake(int amount){
    MyBrakes -> Apply(amount);
}

void  CarControls :: TurnOnRadio() {
    MyRadio -> SetVolume(100);
}

void CarControls :: TurnOffRadio(){ 
    MyRadio -> SetVolume(0);
}


void  CarControls :: AdjustRadioVolume(int amount){
    MyRadio -> AdjustVolume(amount);
}

void  CarControls :: TurnOnHeadlights(){ 
    MyHeadlights -> TurnOn();
}

void  CarControls :: TurnOffHeadlights() { 
    MyHeadlights -> TurnOff();
}

void  CarControls :: ClimbHill(int angle){
    MyRoad -> ClimbDescend(angle);
}

void CarControls :: DescendHill(int angle){
    MyRoad -> ClimbDescend(0 - angle);
}

int CarControls :: GetSpeed(){ 
    return MyWheels -> Speed;
}

void CarControls::TurnOnAC() {
    MyAirconditioner->TurnOn();
}
void CarControls::TurnOffAC() {
    MyAirconditioner->TurnOff();
}
void CarControls::AdjustAC(int amount) {
    MyAirconditioner->SetLevel(amount);
}
