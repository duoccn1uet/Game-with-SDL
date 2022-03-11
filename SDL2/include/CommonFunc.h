#ifndef COMMONFUNC_H_INCLUDED
#define COMMONFUNC_H_INCLUDED

#include <bits/stdc++.h>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

using namespace std;

static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr;
static SDL_Event d_event;

/// Screen

const string WINDOW_TITLE = "WELCOME TO MY EMPIRE";

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;
const int RENDER_DRAW_COLOR = 0xff;



#endif // COMMONFUNC_H_INCLUDED
