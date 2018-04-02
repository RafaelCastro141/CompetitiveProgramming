// A C++ program to find maximal Bipartite matching.
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
 
// M is number of applicants and N is number of jobs
#define M 110
#define N 110
typedef	pair<int, int>	pii;
pii pb[N], pr[N];
// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(bool bpGraph[M][N], int u, bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in job v and v is
        // not visited
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true; // Mark v as visited
 
            // If job 'v' is not assigned to an applicant OR
            // previously assigned applicant for job v (which is matchR[v]) 
            // has an alternate job available. 
            // Since v is marked as visited in the above line, matchR[v] 
            // in the following recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
// Returns maximum number of matching from M to N
int maxBPM(bool bpGraph[M][N])
{
    // An array to keep track of the applicants assigned to
    // jobs. The value of matchR[i] is the applicant number
    // assigned to job i, the value -1 indicates nobody is
    // assigned.
    int matchR[N];
 
    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));
 
    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));
 
        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}

bool adj[N][N];

int main (){
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &pr[i].first, &pr[i].second);
	}
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d", &pb[i].first, &pb[i].second);
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(pr[i].first < pb[j].first && pr[i].second < pb[j].second){
				adj[i][j] = true;
			}
		}
	}
	
	printf("%d\n", maxBPM(adj));
	
	return 0;
}
