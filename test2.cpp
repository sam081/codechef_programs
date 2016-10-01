#include<bits/stdc++.h>
typedef std::pair<int, int> indices_t;
typedef std::vector<std::vector<int> > matrix_t;
typedef std::vector<indices_t> solution_t;
bool out_of_bounds(indices_t& current, matrix_t& matrix)
{
return (current.first < 0 ||current.second < 0 ||current.first >= (int) matrix.size() ||current.second >= (int) matrix[0].size());
}
void backtracking(indices_t current,indices_t& dst,matrix_t& matrix,matrix_t& visited,matrix_t& distances,solution_t& solution,solution_t& shortest_path)
{
// reject current indices if previously visited
// or solution larger than shortest_path
if (out_of_bounds(current, matrix) ||visited[current.first][current.second] == 1 ||matrix[current.first][current.second] == 0 ||(int) solution.size() >= distances[current.first][current.second])
    return;
// add current [i][j] indices to solution
solution.push_back(current);
visited[current.first][current.second] = 1;
distances[current.first][current.second] = (int) solution.size();
// check if destination reached
if (current.first == dst.first && current.second == dst.second)
    shortest_path = solution;
else
{
// visit all indices adjacent to [i][j] i.e. [first][second]
// [i-1][j-1] [i-1][j] [i-1][j+1]
// [i][j-1] [i][j] [i][j+1]
// [i+1][j-1] [i+1][j] [i+1][j+1]
for (int k = 1; k >= -1; k--)
for (int l = 1; l >= -1; l--)
backtracking(std::make_pair(current.first + k, current.second +l),dst, matrix, visited, distances, solution,shortest_path);
}
solution.pop_back();
visited[current.first][current.second] = 0;
}
void find_shortest_path(indices_t& src, indices_t& dst, matrix_t& matrix)
{
solution_t shortest_path;
solution_t solution;
// initialize visited matrix to all 0
matrix_t visited;
matrix_t distances;
visited.resize(matrix.size());
distances.resize(matrix.size());
for (std::size_t i = 0; i < visited.size(); i++)
{
    distances[i].resize(matrix[i].size(), std::numeric_limits<int>::max());
    visited[i].resize(matrix[i].size(), 0);
}
// find shortest path
backtracking(src, dst, matrix, visited, distances, solution, shortest_path);
// print shortest path
for (std::size_t i = 0; i < shortest_path.size(); i++)
    std::cout << "[" << shortest_path[i].first<< "][" << shortest_path[i].second << "], ";
    std::cout << std::endl;
}


int main()
{
matrix_t matrix ={
{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
{ 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
}
indices_t src(0, 0);
indices_t dst((int) matrix.size() - 1, (int) matrix[0].size() - 1);
find_shortest_path(src, dst, matrix);
return 0;
}
