#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

int DFS(vector<string> map, vector< vector<int> > &visited, vector<string> &path_map, int m, int n);
int isvalid(vector<string> map, int i, int j);

int main(int argc,char** argv)
{
	fstream file;
	if(argc>1)
		file.open(argv[1]);
	else
		file.open("../input.txt");
	vector<string> map;
	string line;
	while(getline(file,line))
		map.push_back(line);
	for(int i=0; i < map.size(); i++)
		cout<<map[i]<<endl;

	vector< vector<int> > visited;
	vector<string> final_path_map;
	for(int i = 0; i < map.size(); i++)
	{
		vector<int> temp;
		for(int j=0; map[i][j] != '\0'; j++)
		{
			if(map[i][j] == '.')
				temp.push_back(0);
			else temp.push_back(-1);
		}
		visited.push_back(temp);
	}

	vector< vector<int> > visited_final = visited;
	int max_count = 0;
	for(int i = 0; i < map.size(); i++)
	{
		for(int j = 0; map[i][j] != '\0'; j++)
		{
			if(visited[i][j] != 0)
				continue;
			vector< vector<int> > visited_temp = visited;
			int current_count = 0;
			vector<string> temp_path_map = map;
			current_count = DFS(map, visited_temp, temp_path_map, i, j);
			if(current_count > max_count)
			{
				final_path_map = temp_path_map;
				max_count = current_count;
				visited_final = visited_temp;
			}
		}
	}
	cout<<"\nLength of path : "<<max_count;
	cout<<"\nFinal traversal path is \n";
	for(int i=0; i < final_path_map.size(); i++)
	{
		for(int j=0; final_path_map[i][j] != '\0'; j++)
		{
			if((int)final_path_map[i][j] == 35 || (int)final_path_map[i][j] == 46)
				cout<<final_path_map[i][j]<<' ';
			else 
			{
				int no = ((int)final_path_map[i][j] - 49);
				if(no>9) cout<<no;
				else cout<<no<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}

int isvalid(vector<string> map, int i, int j)
{
	if(i < 0 || j < 0 || i >= map.size())
		return 0;
	int len = -1;;
	while(map[0][++len] != '\0');
	if(j >= len) return 0;
	return 1;
}

int DFS(vector<string> map, vector< vector<int> > &visited, vector<string> &path_map, int m, int n)
{
	// cout<<count<<endl;
	if(isvalid(map, m, n) == 0) return 0;
	visited[m][n] = 1;

	int max_count = 0;
	vector< vector<int> > temp_visited_1, temp_visited_2, temp_visited_3, temp_visited_4;
	vector<string> temp_path_map_1,temp_path_map_2,temp_path_map_3,temp_path_map_4;

	temp_visited_1=temp_visited_2=temp_visited_3=temp_visited_4=visited;
	temp_path_map_1=temp_path_map_2=temp_path_map_3=temp_path_map_4=path_map;

	if(isvalid(map,m-1,n))
		if(visited[m-1][n] == 0)
		{
			int count = DFS(map, temp_visited_1, temp_path_map_1, m-1, n);
			if(count > max_count)
			{
				path_map = temp_path_map_1;
				visited = temp_visited_1;
				max_count = count;
			}
		}
	if(isvalid(map,m,n-1))
		if(visited[m][n-1] == 0)
		{
			int count = DFS(map, temp_visited_2, temp_path_map_2, m, n-1);
			if(count > max_count)
			{
				path_map = temp_path_map_2;
				visited = temp_visited_2;
				max_count = count;
			}
		}
	if(isvalid(map,m+1,n))
		if(visited[m+1][n] == 0)
		{
			int count = DFS(map, temp_visited_3, temp_path_map_3, m+1, n);
			if(count > max_count)
			{
				path_map = temp_path_map_3;
				visited = temp_visited_3;
				max_count = count;
			}
		}
	if(isvalid(map,m,n+1))
		if(visited[m][n+1] == 0)
		{
			int count = DFS(map, temp_visited_4, temp_path_map_4, m, n+1);
			if(count > max_count)
			{
				path_map = temp_path_map_4;
				visited = temp_visited_4;
				max_count = count;
			}
		}

	path_map[m][n] = (char)(48+1+max_count);
	return 1 + max_count;
}