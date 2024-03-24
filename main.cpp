#include<bits/stdc++.h>
#include<ctime>
#include<random>
#include<SDL2/SDL.h>

using namespace std;

const int ScreenWidth = 800;
const int ScreenHeight = 600;
const int CellSize = 20;
const int MazeSizeX = ScreenWidth / CellSize;
const int MazeSizeY = ScreenHeight / CellSize;

SDL_Window *gWindow = nullptr;
SDL_Renderer *gRenderer = nullptr;

enum CellType
{
    Wall,
    Path,
    Start,
    End,
    SOLVISITED
};

struct Cell
{
    CellType type;
    bool genvisited;
};

vector<vector<Cell>> maze(MazeSizeY, vector<Cell>(MazeSizeX, {Wall, false}));

void generateMaze(int x, int y)
{
    maze[y][x].genvisited = true;

    int moves[4][2] = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};
    random_shuffle(begin(moves), end(moves)); // randomly shuffle moves

    for (int i = 0; i < 4; i++)
    {
        int newX = x + moves[i][0];
        int newY = y + moves[i][1];

        if (newX > 0 && newX < MazeSizeX - 1 && newY > 0 && newY < MazeSizeY - 1 && !maze[newY][newX].genvisited)
        {
            maze[y + moves[i][1] / 2][x + moves[i][0] / 2].type = Path;
            maze[newY][newX].type = Path;
            generateMaze(newX, newY);
        }
    }
}

void renderMaze()
{
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    SDL_RenderClear(gRenderer);

    for (int y = 0; y < MazeSizeY; ++y)
    {
        for (int x = 0; x < MazeSizeX; ++x)
        {
            SDL_Rect cellRect = {x * CellSize, y * CellSize, CellSize, CellSize};

            switch (maze[y][x].type)
            {
            case Wall:
                SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
                break;
            case Path:
                SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
                break;
            case Start:
                SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
                break;
            case End:
                SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
                break;
            case SOLVISITED:
                SDL_SetRenderDrawColor(gRenderer, 128, 128, 128, 255);
                break;
            }

            SDL_RenderFillRect(gRenderer, &cellRect);
        }
    }

    SDL_RenderPresent(gRenderer);
}

void delay(int milliseconds)
{
    SDL_Delay(milliseconds);
}

bool isValidMove(int x, int y)
{
    return (x >= 0 && x < MazeSizeX && y >= 0 && y < MazeSizeY && maze[y][x].type != Wall && maze[y][x].type != SOLVISITED);
}

bool SolveBack(int x, int y)
{
    if (maze[y][x].type == End)
    {
        return true;
    }

    maze[y][x].type = SOLVISITED;
    renderMaze();
    delay(50);

    int moves[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    for (int i = 0; i < 4; i++)
    {
        int newX = x + moves[i][0];
        int newY = y + moves[i][1];

        if (isValidMove(newX, newY) && SolveBack(newX, newY))
        {
            return true;
        }
    }

    maze[y][x].type = Path; // Backtrack
    renderMaze();
    delay(50);

    return false;
}

int main(int argc, char *args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return -1;
    }

    gWindow = SDL_CreateWindow("Random Maze Generator and Solver", 100, 100, ScreenWidth, ScreenHeight, 4);
    if (gWindow == nullptr)
    {
        cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return -1;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, 2);
    if (gRenderer == nullptr)
    {
        cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        return -1;
    }

    srand(time(0));
    int startX = rand() % (MazeSizeX / 2) * 2;
    int startY = rand() % (MazeSizeY / 2) * 2;
    maze[startY][startX].type = Start;

    generateMaze(startX, startY);
    maze[MazeSizeY - 2][MazeSizeX - 2].type = End; // Set the end point

    renderMaze();

    delay(1000);

    if (SolveBack(startX, startY))
    {
        cout << "Path found!" << endl;
    }
    else
    {
        cout << "No Path found!" << endl;
    }

    cout << "Press Enter key to exit..." << endl;
    cin.ignore(); // Wait for user input

    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    SDL_Quit();

    return 0;
}
