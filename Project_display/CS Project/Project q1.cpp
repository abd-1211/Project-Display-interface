#include <stdlib.h>
#include <sys/time.h>
#include <iostream>
#include <string>

using namespace std;

// Function prototypes
int senseDistance()
{
	return rand()%101;
}
void getSensors(int sensors[])
{
	for(int i=0; i<4;i++)
	{
		sensors[i]=senseDistance();
	}
}
void printSensors(int sensors[], string labels[])
{
	for(int i=0;i<4;i++)
	{
		cout<<labels[i] <<" = "<< sensors[i]<< endl;
	}
};
int furthest(int sensors[])
{
	int compare=0;
	for(int i=0;i<4;i++)
	{
	if(sensors[i]>sensors[compare])
		{
			compare=i;
		}
	}
	return compare;
}

// Main function
int main() {
   int sensors[4];      // Array of four distance sensors
   string labels[4];    // Array of labels for each sensor
   int dire;             // Indicates which direction to go next

   srand(time(NULL));   // Initialize the random number generator

   labels[0] = "(north)"; // Initialize the sensor labels
   labels[1] = "(west)";
   labels[2] = "(south)";
   labels[3] = "(east)";

   for (int i = 0; i < 5; i++) {  // Simulate 5 moves by the robot
       getSensors(sensors);      // Get values for all the sensors
       printSensors(sensors, labels); // Print out the sensor values
       dire = furthest(sensors);  // Find the direction that is furthest from an obstacle
       cout << "moving " << labels[dire] << endl; // ``go''
   }
}

