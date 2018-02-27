#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
// #include <string>

using namespace std;

vector<string> DFS(vector<string> map, &vector<vector<int>> visited, &int count);

int main()
{
	fstream file;
	file.open("input.txt");
	vector<string> map;
	string line;
	while(getline(file,line))
		map.push_back(line);
	for(int i=0; i < map.size(); i++)
		cout<<map[i]<<endl;

	vector<vector<int>> visited;
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
			vector<string> temp_path_map = DFS(map, &visited, &current_count);
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

vector<string> DFS(vector<string> map, &vector<vector<int>> visited, &int count)
{
	
}