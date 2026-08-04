#pragma once
#include <resource/texture.h>

#include <Basic/2D/SpriteBatch.hpp>


namespace B2D
{

struct Sprite
{
    Texture2D* texture;

    Sprite();
    ~Sprite();

    void draw(Basic::SpriteBatch& sprite_batch);
};

}