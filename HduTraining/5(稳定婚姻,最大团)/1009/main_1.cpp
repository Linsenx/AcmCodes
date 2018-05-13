#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 200;

struct student
{
	int id;
	int region;
	int score;
	int k, pt;
	int tar[maxn];
	int join;
} students[maxn];

struct school
{
	int region;
	int now, max;
	int stu[maxn];
} schools[maxn];

int n, m;
int G[maxn][maxn];

int fdu_region;
int cmp(student a, student b)
{
	if (a.region == fdu_region)
	{
		if (b.region == fdu_region) return a.score > b.score;
		else return a.score * 10 > b.score * 7;
	}
	else if (b.region == fdu_region)
	{
		if (a.region == fdu_region) return a.score > b.score;
		else return a.score * 7 > b.score * 10;
	}
	else
		return a.score > b.score;
}

int cmp1(student a, student b)
{
	return a.id < b.id;
}

void makeMap()
{
	for (int i = 1; i <= m; ++i)
	{
		fdu_region = schools[i].region;
		sort(students, students + n, cmp);
		//for (int j = 0; j < n; ++j) G[i][j] = students[j].id;
		for (int j = 0; j < n; ++j) G[i][students[j].id] = j;
	}
	sort(students, students + n, cmp1);
} 

int getRank(int school, int student)
{
	for (int i = 0; i < n; ++i) 
	{
		if (G[school][i] == student) return i;
	}
	return 1000;
}

void stableMatch()
{
	queue<int> single;
	for (int i = 0; i < n; ++i) single.push(students[i].id);
	
	while (!single.empty()) 
	{
		int man = single.front(); single.pop();
		if (students[man].pt >= students[man].k) 
		{
			continue;
		}
		
		int woman = students[man].tar[students[man].pt++];
		
		if (schools[woman].now < schools[woman].max)
		{
			students[man].join = woman;
			schools[woman].stu[schools[woman].now++] = man;
		}
		else
		{
			int drop_student = man;
			int drop_studentj = 0;
			for (int i = 0; i < schools[woman].now; ++i)
			{
				int j = schools[woman].stu[i];
				if (G[woman][drop_student] < G[woman][j]) drop_student = j, drop_studentj = i;	
			}
			
			if (drop_student != man)
			{
				students[drop_student].join = 0;
				single.push(drop_student);
				
				students[man].join = woman;
				schools[woman].stu[drop_studentj] = man;
			}
			else
			{
				single.push(man);
			}
			
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		if (students[i].join == 0) printf("not accepted\n");
		else printf("%d\n", students[i].join);
	}
}

int main()
{
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	
	int test;
	scanf("%d", &test);
	while (test--) 
	{
		memset(G, 0, sizeof(G));
		
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			students[i].id = i;
			students[i].pt = 0;
			students[i].join = 0;
			scanf("%d%d%d", &students[i].region, &students[i].score, &students[i].k);
			for (int j = 0; j < students[i].k; ++j) scanf("%d", &students[i].tar[j]);
		}
		
		for (int i = 1; i <= m; ++i) 
		{
			schools[i].now = 0;
			scanf("%d%d", &schools[i].region, &schools[i].max);
		}
		
		makeMap();
		stableMatch();	
		
		if (test) printf("\n");
	}
	
	return 0;
}