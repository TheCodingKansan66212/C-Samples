#include <iostream>
#include<cstdlib>
using std::cin; using std::cout;

using namespace std;

int main()
{
	int racers = 0, laps = 0;
	int racerId, racerTimeOne = 0, racerTimeTwo = 0, lowest = 9999;
	int lapTotal = 0, lapTime = 0;
	int difference, raceTimeTotal = 0;
	int winningRaceTime = 0, winningRaceId;

	cout << "Number of racers: " << endl;
	cin >> racers;

	cout << "Number of laps:" << endl;
	cin >> laps;

	for (int i = 0; i <= racers - 1; i++)
	{
		cout << "Racer Id: " << endl;
		cin >> racerId;

		cout << "First judge race time: " << endl;
		cin >> racerTimeOne;

		cout << "Second judge race time: " << endl;
		cin >> racerTimeTwo;


		raceTimeTotal = racerTimeOne + racerTimeTwo;
		if (raceTimeTotal < lowest) {
			lowest = raceTimeTotal;
			winningRaceId = racerId;
		}



		for (int j = 1; j <= laps - 1; j++)
		{
			cout << "Lap time:" << endl;
			cin >> lapTime;

			lapTotal = lapTime;
		}

		raceTimeTotal = (racerTimeOne + racerTimeTwo);
		difference = abs(raceTimeTotal - lapTime);

		if (difference == 0)
		{
			cout << lapTotal << endl;
			cout << "The two time keepers agree. ";
		}
		else
			cout << lapTotal << endl;
		cout << "The judges differ by " << difference << endl;
	}


	cout << "The racer id of the lowest race time:" << winningRaceId << endl;
	cout << "The lowest race time:" << lowest << endl;
	return 0;
}
/*Number of racers:
4
Number of laps:
2
Racer Id:
1111
First judge race time:
60
Second judge race time:
61
Lap time:
120
120
The judges differ by 1
Racer Id:
2222
First judge race time:
60
Second judge race time:
58
Lap time:
118
118
The two time keepers agree. The judges differ by 0
Racer Id:
3333
First judge race time:
59
Second judge race time:
65
Lap time:
121
121
The judges differ by 3
Racer Id:
4444
First judge race time:
57
Second judge race time:
62
Lap time:
119
119
The two time keepers agree. The judges differ by 0
The racer id of the lowest race time:2222
The lowest race time:118
*/