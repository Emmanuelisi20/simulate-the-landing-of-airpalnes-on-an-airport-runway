//Emmanuel Isidahomen
/* This Program is used to simulate the landing of airpalnes on an airport runway.*/
#include <iostream>  // Input and output
#include <string>    // string of charaters 
#include <cstdlib>   // random number generator
#include <vector>    // Arrays resize
#include <queue>     // FIFO
using namespace std;  // Namespace
// Trying to determind the time the plane landed 
class Airplanline
{
public:
	string Name;
	int ArrivalTime; // Arrivaling time 
	int PlaneDelayed; // Delay time
	Airplanline(string Aname, int AnPlaneDelayed, int Atime):Name(Aname), PlaneDelayed(AnPlaneDelayed),ArrivalTime(Atime) { }
};
int landDownCount = 1;  
Airplanline &genlandDown()
{
	string names;
	int PlaneDelayed = (rand() % 2) + 1;
	int arrivalTime = (int)(rand() % 35);
	if (landDownCount < 1) {
		names = "Airplanline" + to_string(landDownCount++);
	}
	else {
		names = "Airplanline0" + to_string(landDownCount++);
	}
	return *(new Airplanline(names, PlaneDelayed, arrivalTime));
}
struct AirplanlineCompareGreater
{
	bool operator()(const Airplanline &structAirplanline1, const Airplanline &structAirplanline2)
	{
		return structAirplanline1.ArrivalTime > structAirplanline2.ArrivalTime;
	}
};
void displayAirplanline(const Airplanline &landDownAirplanline, int keyArrivalTime, int aTime)
{
	string stringDelay = to_string(landDownAirplanline.PlaneDelayed);
	string time;
	string arrival;
	if (aTime < 10)
		time = "0" + to_string(aTime);
	else
		time = to_string(aTime);
	if (landDownAirplanline.ArrivalTime < 10)
		arrival = "0" + to_string(landDownAirplanline.ArrivalTime);
	else
		arrival = to_string(landDownAirplanline.ArrivalTime);
	cout << landDownAirplanline.Name << " Scheduled to arrive at " << arrival << " with landDown delay " << stringDelay << " touched down at " << time << endl;
	if (landDownAirplanline.ArrivalTime <= keyArrivalTime)
		cout << " Airplanline was delayed " << keyArrivalTime - landDownAirplanline.ArrivalTime << " minutes" << endl;
	else
		cout << " Airport was not landDown Airplanlines " << landDownAirplanline.ArrivalTime - keyArrivalTime << " minutes" << endl;
}
// Display the number of planes for them to be queue on and disping the how-much could be added to the queue
int main()
{
	priority_queue <Airplanline, std::vector<Airplanline>, AirplanlineCompareGreater> landDownAirplanlines;
	int size = 19;   // Number Of Airplanlines that are landing and been delayed
	int time = 0;    // Time for landing and delayers
	int keyArrivalTime = 0;
	for (int i = 0; i <= size; i++)
	{
		landDownAirplanlines.push(genlandDown());
	}
	while (!landDownAirplanlines.empty())
	{
		if (landDownAirplanlines.top().ArrivalTime <= keyArrivalTime)
			time = keyArrivalTime + landDownAirplanlines.top().PlaneDelayed;
		
		else
			time = landDownAirplanlines.top().ArrivalTime + landDownAirplanlines.top().PlaneDelayed;

		displayAirplanline(landDownAirplanlines.top(), keyArrivalTime, time);
		keyArrivalTime = time;
		landDownAirplanlines.pop();
	}
	system("pause");
	return 0;
}
