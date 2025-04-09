/*
 * C++ Design Patterns: Mediator
 * The following source code was based on: github.com/JakubVojvoda
 * 
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */

#include <iostream>
#include <vector>
#include <string>

class trafficControl;

/*
 * Vehicle class (abstract)
 * each Vehicle communicates with (/through) its mediator (/the air traffic tower)
 * (with other Vehicles)
 */
class Vehicle
{
public:
    Vehicle(trafficControl* const m, const unsigned int i) :
        mediator(m), id(i) {}

    virtual ~Vehicle() {}

    unsigned int getID()
    {
        return id;
    }

    virtual void send_new_altitude(std::string) = 0;
    virtual void receive(std::string) = 0;

protected:
    trafficControl* mediator;
    unsigned int id;
};


// airVehicle class implements Vehicle (abstract) class
class airVehicle : public Vehicle
{
public:
    airVehicle(trafficControl* const m, const unsigned int i) :
        Vehicle(m, i) {}

    ~airVehicle() {}

    void send_new_altitude(std::string msg);

    void receive(std::string msg)
    {
        std::cout << "New altitude: '" << msg << "' received by Vehicle " << id << std::endl;
    }
};

/*
 * trafficControl (abstract) class is the Mediator
 * defines an interface for communication among Vehicle objects
 */
class trafficControl
{
public:
    virtual ~trafficControl() {}

    virtual void add(Vehicle* const c) = 0;
    virtual void distribute(Vehicle* const sender, std::string msg) = 0;

protected:
    trafficControl() {}
};

/*
 * Tower implements (abstract) trafficControl class
 * implements cooperative behavior by coordinating Vehicle objects
 * 
 */
class Tower : public trafficControl
{
public:
    ~Tower()
    {
        std::vector<Vehicle*>().swap(vehicle_group);
        // free memory
    }

    void add(Vehicle* const c)
    {
        vehicle_group.push_back(c);
    }

    void distribute(Vehicle* const sender, std::string msg)
    {
        for (unsigned int i = 0; i < vehicle_group.size(); i++)
        {
            if (vehicle_group.at(i)->getID() != sender->getID())
            {
                vehicle_group.at(i)->receive(msg);
            }
        }
    }

private:
    std::vector<Vehicle*> vehicle_group;
};

void airVehicle::send_new_altitude(std::string msg)
{
    std::cout << std::endl << "Message '" << msg << "' sent by Vehicle " << id << std::endl;
    mediator->distribute(this, msg);
}


int main()
{
    trafficControl* mediator = new Tower();

    Vehicle* aircraft01 = new airVehicle(mediator, 1);
    Vehicle* aircraft02 = new airVehicle(mediator, 2);
    Vehicle* drone01 = new airVehicle(mediator, 3);
    Vehicle* helicopter01 = new airVehicle(mediator, 4);

    mediator->add(aircraft01);
    mediator->add(aircraft02);
    mediator->add(drone01);
    mediator->add(helicopter01);

    aircraft01->send_new_altitude("3500m");
    aircraft02->send_new_altitude("5000m");
    helicopter01->send_new_altitude("50m");

    // free memory
    delete mediator;
    delete aircraft01;
    delete aircraft02;
    delete drone01;
    delete helicopter01;

    return 0;
}
