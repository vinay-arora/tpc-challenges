#include <iostream>
#include <stdio.h>
#include <set>

// pPlayers - list of players
// set - set of dependencies
// pPlayer - Player for whose dependencies are being listed
// pPlayerToLook - The player which is to be looked in the list
void FillSet(int ** pPlayers, std::set<int> set, int pPlayer, int pPlayerToLook)
{
	 std::set<int>::iterator it;
	// stop when either the numbers are over 
	// or there is no further dependency e.g. 1 can defeat 2 and 2 can't defeat anyone
	// skip if its you only or a number which is already checked
	for (int j = 1; j <= pPlayers[pPlayerToLook][0]; j++)
	{

		// if player not in set, insert and go to its dependencies
		it=set.find(pPlayers [pPlayerToLook][j]);
		
		// it is not the set
		if (it == set.end()) {
			// insert the element in set
			set.insert(pPlayers [pPlayerToLook][j]);
			FillSet (pPlayers, set, pPlayer, pPlayers [pPlayerToLook][j]);
		}
	}
}

// This function fills all the dependencies
void FillDependencies (int ** pPlayers, int pNumParticipants, int pLast, int pOwn)
{
	
	// no of players fr whose tournament can be fixed.
	int playertour = 0;
	
	
	for (int i = 0; i < pNumParticipants ; i++)
	{
		std::set<int> set;
		
		// inserting in the set who can lose by this player
		// since the first line contains the num of players who can beat this person
		for (int j = 1; j <= pPlayers[i][0]; j++)
		{
			//inserting in set and filling further dependencies
			set.insert(pPlayers[i][j]);

			FillSet (pPlayers, set, i, pPlayers[i][j]);
		}

		// check if set contains pNumParticipants - 1, then we can set the tournament for him (excluding 1 for his own)
		if (set.size() == pNumParticipants - 1)
			++playertour;
		
	}
}


int main ()
{
	int nooftests = 0;
	printf("Enter no. of tests = ");
	scanf("%d",&nooftests);

	// getting input for all test cases
	for (int i = 0; i < nooftests ; i++)
	{
		//taking no. of participants as input
		int noofparticipants = 0;

		printf("Enter no. of participants = ");
		scanf("%d",&noofparticipants);

		// no of participants are limited to 1000
		if (noofparticipants > 1000)
			exit (1);

		// allocating array of participants
		int ** arr; 
		arr = new int*[noofparticipants];
		if (arr)
		{
		  for (int i = 0; i < noofparticipants; i++)
		  {
			  // start taking line by line input and start
			int playernumwhocanbeatthisplayer = 0;

			printf("Enter no. of players who can beat this player = ");
			scanf("%d",&playernumwhocanbeatthisplayer);
			
			arr[i] = new int [playernumwhocanbeatthisplayer+1];
			
			//setting all as fasle initially
			memset (arr[i], 0, playernumwhocanbeatthisplayer);

			arr[i][0] = playernumwhocanbeatthisplayer;

			//taking input 
			for (int j = 0; j< playernumwhocanbeatthisplayer ; j++)
			{
				// turn the positions to true which user can beat this
				int playernum = 0;

				printf("Enter the player number = ");
				scanf("%d",&playernum);

				//setting to true
				arr[i][j] = playernum;
			}

			if (arr[i])
				continue;
			  // initialize arr[i]
			else
			  exit (1);// panic
		  }
		}
		
		
			
		FillDependencies (arr, noofparticipants, 0, 0);

		delete arr; // in MS this deletes the 2-D array wholly

	}// end of test cases
	return 0;
}
