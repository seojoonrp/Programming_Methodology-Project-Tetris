#include "raylib.h"
#include <ctime> // For current time

// Constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 450;
const int TARGET_FPS = 60;
const int BLOCK_SIZE = 40;
const float MOVE_SPEED = 2.0f;
const char *WINDOW_TITLE = "Tetris Project";
const char *CENTER_TEXT = "Playground";
const int FONT_SIZE = 20;

// Game state
struct GameState {
  float blockX;
  float blockY;
};

// Function declarations
void InitializeGame(GameState &state);
void UpdateBlockPosition(GameState &state);
void HandleBlockBoundary(GameState &state);
void DrawGame(const GameState &state);

int main(void) {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
  SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  SetTargetFPS(TARGET_FPS);

  GameState state;
  InitializeGame(state);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawGame(state);

    EndDrawing();

    UpdateBlockPosition(state);

    HandleBlockBoundary(state);
  }

  CloseWindow();
  return 0;
}

void InitializeGame(GameState &state) {
  // Initialize the block position to the center of the window
  state.blockX = (WINDOW_WIDTH - BLOCK_SIZE) / 2;
  state.blockY = (WINDOW_HEIGHT - BLOCK_SIZE) / 2;
}

void UpdateBlockPosition(GameState &state) {
  // TODO (Assignment): Move the block using arrow keys (UP, DOWN, LEFT, RIGHT)
}

void HandleBlockBoundary(GameState &state) {
  // TODO (Assignment): If the block goes outside the screen, wrap it to the
}

void DrawGame(const GameState &state) {
  int screenWidth = GetScreenWidth();
  int screenHeight = GetScreenHeight();

  // Draw the CENTER_TEXT at the center of the screen
  int textWidth = MeasureText(CENTER_TEXT, FONT_SIZE);
  int textX = (screenWidth - textWidth) / 2;
  int textY = (screenHeight - FONT_SIZE) / 2;
  DrawText(CENTER_TEXT, textX, textY, FONT_SIZE, LIGHTGRAY);

  // Draw screen border
  DrawLine(1, 1, screenWidth - 1, 1, BLACK);
  DrawLine(1, 1, 1, screenHeight - 1, BLACK);
  DrawLine(screenWidth - 1, 1, screenWidth - 1, screenHeight - 1, BLACK);
  DrawLine(1, screenHeight - 1, screenWidth - 1, screenHeight - 1, BLACK);

  // TODO (Assignment): Draw a red block at state.blockX, state.blockY

  // TODO (Attendance): Draw current time (HH:MM:SS) at top-left
}
