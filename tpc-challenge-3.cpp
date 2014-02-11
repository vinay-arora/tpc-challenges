#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

// no. of men or women
#define N 4


bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1)
{
    // Check if w prefers m over her current engagment m1
    for (int i = 0; i < N; i++)
    {
        // CASE : m1 comes before m in preference list of w, then w prefers her m1 over m, OK
        if (prefer[w][i] == m1)
            return true;
 
        //CASE : m comes before m1 in w's preference list, then free her current
        // engagement and engage her with m
        if (prefer[w][i] == m)
           return false;
    }
}
 
//Boys are numbered as 0 to N-1. Girls are numbereed as N to 2N-1.
void StableMarriage(int prefer[2*N][N])
{
    // Stores partner of women.-1 indicates that woman is free
    int wPartner[N];
 
    // store availability of men.  If mFree[i] is false, then man 'i' is free, otherwise engaged.
    bool mFree[N];
 
    // Initialize all men and women as free
    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    
	int freemen = N;
 
    // repeat till there are free men
    while (freemen > 0)
    {
        
        int m;
        
        // repeat till any men is free
        for (m = 0; m < N; m++)
            if (mFree[m] == false)
                break;
 
        // Search all women according to m's preferences. If m is not engaged
        for (int i = 0; i < N && mFree[m] == false; i++)
        {
            int w = prefer[m][i];
 
            // The woman of preference is free, w and m become
            // partners (Note that the partnership maybe changed
            // later). So we can say they are engaged not married
            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mFree[m] = true;
                freemen--;
            }
			//CASE: women is not free, 
			//although she can be engaged not married so, 
			//checking for her preferences
            else
            {
                // getting the current engagement of w
                int m1 = wPartner[w-N];
 
                // If w prefers m over her current engagement m1,
                // then break the engagement between w and m1 and
                // engage m with w.
                if (wPrefersM1OverM(prefer, w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            } // End of Else
        } // End of the for loop that goes to all women in m's list
    } // End of main while loop
 
 
    // Print the solution
    cout << "Woman-Man" << endl;
    for (int i = 0; i < N; i++)
       cout << " " << i+N << "-" << wPartner[i] << endl;
}
 
int main()
{
  // test case
    int prefer[2*N][N] = { {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    
    // calling for getting stable marriages
    StableMarriage(prefer);
 
	 _getch();
    return 0;
}
