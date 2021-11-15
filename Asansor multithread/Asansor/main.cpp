#include <vector>
#include <thread>
#include <string>
#include <iostream>
#include <chrono>

using namespace std;



// Classes
class Client
{
private:
    int floor;
    int destination;
    bool line;
public:
    Client(int floor, int destination,bool line)
    {
        this->floor = floor;
        this->destination = destination;
        this->line = line;
    }

    int getFloor()
    {
        return this->floor;
    }

    int getDestination()
    {
        return this->destination;
    }

    bool getLine()
    {
        return this->line;
    }

    void setFloor(int floor)
    {
        this->floor = floor;
    }

    void setDestination(int destination)
    {
        this->destination = destination;
    }

    void setLine(bool line)
    {
        this->line = line;
    }
};

// Variable
vector < Client > zeroClients;
vector < Client > firstClients;
vector < Client > secondClients;
vector < Client > thirdClients;
vector < Client > fourthClients;
int exitCount = 0;

class Elevator
{
private:
    int floor;
    int destination;
    bool status;
    vector < Client > clients;
public:
    Elevator()
    {
        this->floor = 0;
        this->destination = 1;
        this->status = false;
    }

    bool addClients(Client client)
    {
        if(clients.size() > 9)
        {
            return false;
        }
        else
        {
            this->clients.push_back(client);
            return true;
        }
    }

    void removeClients(int floor)
    {
        for(int i = 0 ; i < clients.size(); i++)
        {
            if(clients[i].getDestination() == floor)
            {
                switch (floor)
                {
                case 0:
                    exitCount++;
                    clients.erase(clients.begin() + i);
                    break;
                case 1:
                    clients[i].setLine(false);
                    clients[i].setFloor(floor);
                    firstClients.push_back(clients[i]);
                    clients.erase(clients.begin() + i);
                    break;
                case 2:
                    clients[i].setLine(false);
                    clients[i].setFloor(floor);
                    secondClients.push_back(clients[i]);
                    clients.erase(clients.begin() + i);
                    break;
                case 3:
                    clients[i].setLine(false);
                    clients[i].setFloor(floor);
                    thirdClients.push_back(clients[i]);
                    clients.erase(clients.begin() + i);
                    break;
                case 4:
                    clients[i].setLine(false);
                    clients[i].setFloor(floor);
                    fourthClients.push_back(clients[i]);
                    clients.erase(clients.begin() + i);
                    break;
                }

            }
        }
    }

    int getFloor()
    {
        return this->floor;
    }

    int getDestination()
    {
        return this->destination;
    }

    bool getStatus()
    {
        return this->status;
    }

    void setFloor(int floor)
    {
        this->floor = floor;
    }

    void setDestination(int destination)
    {
        this->destination = destination;
    }

    void setStatus(bool status)
    {
        this->status = status;
    }

    string getDirection()
    {
        if(floor < destination)
        {
            return "Yukari";
        }
        else
        {
            return "Asagi";
        }
    }

    int getClientsCount()
    {
        return clients.size();
    }

    string getClientsDetail()
    {
        int zero = 0;
        int first = 0;
        int second = 0;
        int third = 0;
        int fourth = 0;
        for(int i = 0; i < clients.size(); i++)
        {
            switch(clients[i].getDestination()){
                case 0:
                    zero++;
                    break;
                case 1:
                    first++;
                    break;
                case 2:
                    second++;
                    break;
                case 3:
                    third++;
                    break;
                case 4:
                    fourth++;
                    break;
                default:
                    break;
            }
        }

        return "Cikis : " + to_string(zero) + " || 1. Kat : " + to_string(first) + " || 2. Kat : " + to_string(second) + " || 3. Kat : " + to_string(third) + " || 4. Kat : " + to_string(fourth);
    }
};

vector < Elevator > elevators;

// Functions
void loginAvm()
{
    while(true)
    {

        int key = rand() % 10 + 1;
        for (int i = 0; i < key; i++)
        {
            Client client = Client(0, rand() % 4 + 1,true);
            zeroClients.push_back(client);
        }

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void exitAvm()
{
    while(true)
    {

        int key = rand() % 5 + 1;
        for (int i = 0; i < key; i++)
        {
            int floor = rand() % 4 + 1;
            switch(floor)
            {
            case 1:
                if(firstClients.size() > 0)
                {
                    for(int i = 0; i < firstClients.size(); i++)
                    {
                        if(firstClients[i].getLine() == false)
                        {
                            firstClients[i].setLine(true);
                            firstClients[i].setDestination(0);
                            break;
                        }
                    }
                }
                break;
            case 2:
                if(secondClients.size() > 0)
                {
                    for(int i = 0; i < secondClients.size(); i++)
                    {
                        if(secondClients[i].getLine() == false)
                        {
                            secondClients[i].setLine(true);
                            secondClients[i].setDestination(0);
                            break;
                        }
                    }
                }
                break;
            case 3:
                if(thirdClients.size() > 0)
                {
                    for(int i = 0; i < thirdClients.size(); i++)
                    {
                        if(thirdClients[i].getLine() == false)
                        {
                            thirdClients[i].setLine(true);
                            thirdClients[i].setDestination(0);
                            break;
                        }
                    }
                }
                break;
            case 4:
                if(fourthClients.size() > 0)
                {
                    for(int i = 0; i < fourthClients.size(); i++)
                    {
                        if(fourthClients[i].getLine() == false)
                        {
                            fourthClients[i].setLine(true);
                            fourthClients[i].setDestination(0);
                            break;
                        }
                    }
                }
                break;
            default:
                break;

            }
        }

        this_thread::sleep_for(chrono::milliseconds(1000));
    }
};

void elevatorAvm(int index)
{
    while(true)
    {

        if(elevators[index].getStatus() == true)
        {
            switch(elevators[index].getFloor())
            {
            case 0:
                elevators[index].removeClients(0);
                for(int i = 0 ; i < zeroClients.size(); i++)
                {
                    if(zeroClients[i].getLine())
                    {
                        bool check = elevators[index].addClients(zeroClients[i]);
                        if(check == true)
                        {
                            zeroClients[i].setLine(false);
                            zeroClients.erase(zeroClients.begin() + i);
                        }
                    }
                }
                break;
            case 1:
                elevators[index].removeClients(1);
                for(int i = 0 ; i < firstClients.size(); i++)
                {
                    if(firstClients[i].getLine())
                    {
                        bool check = elevators[index].addClients(firstClients[i]);
                        if(check == true)
                        {
                            firstClients[i].setLine(false);
                            firstClients.erase(firstClients.begin() + i);
                        }
                    }
                }
                break;
            case 2:
                elevators[index].removeClients(2);
                for(int i = 0 ; i < secondClients.size(); i++)
                {
                    if(secondClients[i].getLine())
                    {
                        bool check = elevators[index].addClients(secondClients[i]);
                        if(check == true)
                        {
                            secondClients[i].setLine(false);
                            secondClients.erase(secondClients.begin() + i);
                        }
                    }
                }
                break;
            case 3:
                elevators[index].removeClients(3);
                for(int i = 0 ; i < thirdClients.size(); i++)
                {
                    if(thirdClients[i].getLine())
                    {
                        bool check = elevators[index].addClients(thirdClients[i]);
                        if(check == true)
                        {
                            thirdClients[i].setLine(false);
                            thirdClients.erase(thirdClients.begin() + i);
                        }
                    }
                }
                break;
            case 4:
                elevators[index].removeClients(4);
                for(int i = 0 ; i < fourthClients.size(); i++)
                {
                    if(fourthClients[i].getLine())
                    {
                        if(elevators[index].getClientsCount() < 10)
                        {
                            bool check = elevators[index].addClients(fourthClients[i]);
                            if(check == true)
                            {
                                fourthClients[i].setLine(false);
                                fourthClients.erase(fourthClients.begin() + i);
                            }
                        }
                    }
                }
                break;
            }

            if(elevators[index].getDestination() == 0)
            {
                elevators[index].setFloor(0);
                elevators[index].setDestination(1);
            }
            else if(elevators[index].getDestination() == 4)
            {
                elevators[index].setFloor(4);
                elevators[index].setDestination(3);
            }
            else
            {
                if(elevators[index].getFloor() < elevators[index].getDestination())
                {
                    elevators[index].setFloor(elevators[index].getDestination());
                    elevators[index].setDestination(elevators[index].getDestination() + 1);
                }
                else
                {
                    elevators[index].setFloor(elevators[index].getDestination());
                    elevators[index].setDestination(elevators[index].getDestination() - 1);
                }
            }
        }

        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void controlElevator()
{
    while(true)
    {

        int queueCount = 0;

        for(int i = 0 ; i < zeroClients.size() ; i++)
        {
            if(zeroClients[i].getLine())
            {
                queueCount++;
            }
        }
        for(int i = 0 ; i < firstClients.size() ; i++)
        {
            if(firstClients[i].getLine())
            {
                queueCount++;
            }
        }
        for(int i = 0 ; i < secondClients.size() ; i++)
        {
            if(secondClients[i].getLine())
            {
                queueCount++;
            }
        }
        for(int i = 0 ; i < thirdClients.size() ; i++)
        {
            if(thirdClients[i].getLine())
            {
                queueCount++;
            }
        }
        for(int i = 0 ; i < fourthClients.size() ; i++)
        {
            if(fourthClients[i].getLine())
            {
                queueCount++;
            }
        }

        if(queueCount < 20)
        {
            elevators[0].setStatus(true);

            if(elevators[1].getClientsCount() == 0) {
                elevators[1].setStatus(false);
                elevators[1].setFloor(0);
                elevators[1].setDestination(1);
            }

            if(elevators[2].getClientsCount() == 0) {
                elevators[2].setStatus(false);
                elevators[2].setFloor(0);
                elevators[2].setDestination(1);
            }

            if(elevators[3].getClientsCount() == 0) {
                elevators[3].setStatus(false);
                elevators[3].setFloor(0);
                elevators[3].setDestination(1);
            }

            if(elevators[4].getClientsCount() == 0) {
                elevators[4].setStatus(false);
                elevators[4].setFloor(0);
                elevators[4].setDestination(1);
            }
        }

        if(queueCount >= 20 && queueCount < 40)
        {
            elevators[0].setStatus(true);
            elevators[1].setStatus(true);

            if(elevators[2].getClientsCount() == 0) {
                elevators[2].setStatus(false);
                elevators[2].setFloor(0);
                elevators[2].setDestination(1);
            }

            if(elevators[3].getClientsCount() == 0) {
                elevators[3].setStatus(false);
                elevators[3].setFloor(0);
                elevators[3].setDestination(1);
            }

            if(elevators[4].getClientsCount() == 0) {
                elevators[4].setStatus(false);
                elevators[4].setFloor(0);
                elevators[4].setDestination(1);
            }
        }

        if(queueCount >= 40 && queueCount < 60)
        {
            elevators[0].setStatus(true);
            elevators[1].setStatus(true);
            elevators[2].setStatus(true);

            if(elevators[3].getClientsCount() == 0) {
                elevators[3].setStatus(false);
                elevators[3].setFloor(0);
                elevators[3].setDestination(1);
            }

            if(elevators[4].getClientsCount() == 0) {
                elevators[4].setStatus(false);
                elevators[4].setFloor(0);
                elevators[4].setDestination(1);
            }
        }

        if(queueCount >= 60 && queueCount < 80)
        {
            elevators[0].setStatus(true);
            elevators[1].setStatus(true);
            elevators[2].setStatus(true);
            elevators[3].setStatus(true);

            if(elevators[4].getClientsCount() == 0) {
                elevators[4].setStatus(false);
                elevators[4].setFloor(0);
                elevators[4].setDestination(1);
            }
        }

        if(queueCount >= 80)
        {
            elevators[0].setStatus(true);
            elevators[1].setStatus(true);
            elevators[2].setStatus(true);
            elevators[3].setStatus(true);
            elevators[4].setStatus(true);
        }


        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void clear()
{
    system("cls");
}

int countQueueFirstFloor()
{
    int queueCount = 0;
    for(int i = 0 ; i < firstClients.size() ; i++)
    {
        if(firstClients[i].getLine() == true)
        {
            queueCount++;
        }
    }
    return queueCount;
}

int countQueueSecondFloor()
{
    int queueCount = 0;
    for(int i = 0 ; i < secondClients.size() ; i++)
    {
        if(secondClients[i].getLine())
        {
            queueCount++;
        }
    }
    return queueCount;
}

int countQueueThirdFloor()
{
    int queueCount = 0;
    for(int i = 0 ; i < thirdClients.size() ; i++)
    {
        if(thirdClients[i].getLine())
        {
            queueCount++;
        }
    }
    return queueCount;
}

int countQueueFourthFloor()
{
    int queueCount = 0;
    for(int i = 0 ; i < fourthClients.size() ; i++)
    {
        if(fourthClients[i].getLine())
        {
            queueCount++;
        }
    }
    return queueCount;
}

void writeScreen()
{
    while(true)
    {

        clear();
        cout << "Zemin Kat => Kuyruk : " << zeroClients.size() << endl<<flush;
        cout << "1. Kat => Toplam Kuyruk : " << firstClients.size() << " Kuyruk : " << countQueueFirstFloor() << endl<<flush;
        cout << "2. Kat => Toplam Kuyruk : " << secondClients.size() << " Kuyruk : " << countQueueSecondFloor() << endl<<flush;
        cout << "3. Kat => Toplam Kuyruk : " << thirdClients.size() << " Kuyruk : " << countQueueThirdFloor() << endl<<flush;
        cout << "4. Kat => Toplam Kuyruk : " << fourthClients.size() << " Kuyruk : " << countQueueFourthFloor() << endl<<flush;
        cout << "Toplam Cikis Yapanlar : " << exitCount << endl<<flush;

        string status = (elevators[0].getStatus()) ? " Aktif" : "Beklemede";
        cout << "1. Asansor => " << status << endl<<flush;
        cout << "                Bulundugu Kat : " << elevators[0].getFloor() << endl<<flush;
        cout << "                Gidecegi Kat : " << elevators[0].getDestination() << endl<<flush;
        cout << "                Yon : " << elevators[0].getDirection() << endl<<flush;
        cout << "                Kisi Sayisi : " << elevators[0].getClientsCount() << endl<<flush;
        cout << "                "<< elevators[0].getClientsDetail() << endl<<flush;

        status = (elevators[1].getStatus()) ? " Aktif" : "Beklemede";
        cout << "2. Asansor => " << status << endl<<flush;
        cout << "                Bulundugu Kat : " << elevators[1].getFloor() << endl<<flush;
        cout << "                Gidecegi Kat : " << elevators[1].getDestination() << endl<<flush;
        cout << "                Yon : " << elevators[1].getDirection() << endl<<flush;
        cout << "                Kisi Sayisi : " << elevators[1].getClientsCount() << endl<<flush;
        cout << "                "<< elevators[1].getClientsDetail() << endl<<flush;

        status = (elevators[2].getStatus()) ? " Aktif" : "Beklemede";
        cout << "3. Asansor => " << status << endl<<flush;
        cout << "                Bulundugu Kat : " << elevators[2].getFloor() << endl<<flush;
        cout << "                Gidecegi Kat : " << elevators[2].getDestination() << endl<<flush;
        cout << "                Yon : " << elevators[2].getDirection() << endl<<flush;
        cout << "                Kisi Sayisi : " << elevators[2].getClientsCount() << endl<<flush;
        cout << "                "<< elevators[2].getClientsDetail() << endl<<flush;

        status = (elevators[3].getStatus()) ? " Aktif" : "Beklemede";
        cout << "4. Asansor => " << status << endl<<flush;
        cout << "                Bulundugu Kat : " << elevators[3].getFloor() << endl<<flush;
        cout << "                Gidecegi Kat : " << elevators[3].getDestination() << endl<<flush;
        cout << "                Yon : " << elevators[3].getDirection() << endl<<flush;
        cout << "                Kisi Sayisi : " << elevators[3].getClientsCount() << endl<<flush;
        cout << "                "<< elevators[3].getClientsDetail() << endl<<flush;

        status = (elevators[4].getStatus()) ? " Aktif" : "Beklemede";
        cout << "5. Asansor => " << status << endl<<flush;
        cout << "                Bulundugu Kat : " << elevators[4].getFloor() << endl<<flush;
        cout << "                Gidecegi Kat : " << elevators[4].getDestination() << endl<<flush;
        cout << "                Yon : " << elevators[4].getDirection() << endl<<flush;
        cout << "                Kisi Sayisi : " << elevators[4].getClientsCount() << endl<<flush;
        cout << "                "<< elevators[4].getClientsDetail() << endl<<flush;


        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

// Main
int main(int argc, char *argv[])
{
    srand(time(NULL));
    Elevator ele1 = Elevator();
    Elevator ele2 = Elevator();
    Elevator ele3 = Elevator();
    Elevator ele4 = Elevator();
    Elevator ele5 = Elevator();
    ele1.setStatus(true);

    elevators.push_back(ele1);
    elevators.push_back(ele2);
    elevators.push_back(ele3);
    elevators.push_back(ele4);
    elevators.push_back(ele5);

    // Threads
    thread LoginThread(loginAvm);
    thread ExitThread(exitAvm);
    thread FirstElevatorThread(elevatorAvm,0);
    thread SecondElevatorThread(elevatorAvm,1);
    thread ThirdElevatorThread(elevatorAvm,2);
    thread FourthElevatorThread(elevatorAvm,3);
    thread FifthElevatorThread(elevatorAvm,4);
    thread ControlThread(controlElevator);
    thread WriteThread(writeScreen);

    while(true);


}
