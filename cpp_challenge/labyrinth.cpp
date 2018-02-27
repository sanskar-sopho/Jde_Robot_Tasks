#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

void DFS(vector<string> map, vector< vector<int> > &visited, vector<string> &temp_path_map, int &count, int m, int n);
int isvalid(vector<string> map, int i, int j);

int main()
{
	fstream file;
	file.open("input_2.txt");
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

	int max_count = 0;
	for(int i = 0; i < map.size(); i++)
	{
		for(int j = 0; map[i][j] != '\0'; j++)
		{
			if(visited[i][j] != 0)
				continue;
			int current_count = 0;
			vector<string> temp_path_map = map;
			DFS(map, visited, temp_path_map, current_count, i, j);
			if(current_count > max_count)
			{
				final_path_map = temp_path_map;
				max_count = current_count;
			}
		}
	}
	
	cout<<"\nFinal traversal path is \n";
	for(int i=0; i < final_path_map.size(); i++)
		cout<<final_path_map[i]<<endl;
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

void DFS(vector<string> map, vector< vector<int> > &visited, vector<string> &temp_path_map, int &count, int m, int n)
{
	// cout<<count<<endl;
	if(isvalid(map, m, n) == 0) return;
	temp_path_map[m][n] = '*';
	count++;
	visited[m][n] = 1;
	if(isvalid(map,m-1,n))
		if(visited[m-1][n] == 0) DFS(map, visited, temp_path_map, count, m-1, n);
	if(isvalid(map,m,n-1))
		if(visited[m][n-1] == 0) DFS(map, visited, temp_path_map, count, m, n-1);
	if(isvalid(map,m+1,n))
		if(visited[m+1][n] == 0) DFS(map, visited, temp_path_map, count, m+1, n);
	if(isvalid(map,m,n+1))
		if(visited[m][n+1] == 0) DFS(map, visited, temp_path_map, count, m, n+1);
}