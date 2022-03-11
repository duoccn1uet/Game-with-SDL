#include <BaseObject.h>

using namespace std;

BaseObject :: BaseObject()
{
    d_object = nullptr;
    d_rect.x = d_rect.y = d_rect.w = d_rect.h = 0;
}

BaseObject :: ~BaseObject()
{
    Free();
}

bool BaseObject :: LoadImg(string path, SDL_Renderer* renderer)
{
    SDL_Texture* new_texture = nullptr;

    SDL_Surface* load_surface = IMG_Load(path.c_str());

    if (load_surface)
        cout << "Unable to load image " << path << " SDL_image Error: "
                 << IMG_GetError() << '\n';
    else
    {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
        new_texture = SDL_CreateTextureFromSurface(renderer, load_surface);
        if (new_texture == nullptr)
            cout << "Unable to load texture from " << path << " SDL Error: "
                 << SDL_GetError() << '\n';
        else
        {
            d_rect.w = load_surface->w;
            d_rect.h = load_surface->h;
        }
        SDL_FreeSurface(load_surface);
    }

    d_object = new_texture;
    return d_object != nullptr;
}

void BaseObject :: Render(SDL_Renderer* des, const SDL_Rect* clip)
{
    SDL_Rect renderquad = d_rect;

    SDL_RenderCopy(des, d_object, clip, &renderquad);
}

void BaseObject :: Free()
{
    if (d_object != nullptr)
    {
        SDL_DestroyTexture(d_object);
        d_object = nullptr;
        d_rect.w = 0;
        d_rect.h = 0;
    }
}
