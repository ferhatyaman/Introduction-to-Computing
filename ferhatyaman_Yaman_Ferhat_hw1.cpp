#include<iostream>

using namespace std;

int main()
{
	int movie, episode;
	double internetusage, remainingquota, totalquota;    // define the interger as how you can understand easily

	cout << "This program is Netflix quota program." << endl;
	
	cout << "Please enter your internet usage limit in GBs:";
	cin >> totalquota;
	cout << "Please enter the number of movies you watched in this month:";
	cin >> movie;
	cout << "Please enter the number of episodes you watched in this month:";
	cin >> episode;

	internetusage = (6144 * movie) + (2520 * episode);    // find the total usage to use amount of data for movies and for episodes 

	remainingquota = totalquota - (internetusage / 1024);   // subtract from the total quota, the usage of internet and obtain the remaining quota.

	cout << "Total Netflix usage in MBs:" << internetusage << endl;

	cout << "Remaining quota in GBs:" << remainingquota << endl;

	




	return 0;
}