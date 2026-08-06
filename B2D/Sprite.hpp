#pragma once
#include <math/transform_2d.h>
#include <resource/texture.h>

#include <Basic/2D/SpriteBatch.hpp>


namespace B2D
{

struct Sprite
{
    Texture2D* texture = nullptr;
    Rect2D sprite_rect = Rect2D(0, 0, 1, 1);
    Rect2D uv_rect = Rect2D(0, 0, 1, 1);
    Color mod_color = Color(255, 255, 255, 255);

    Sprite();
    ~Sprite();

    void set_texture(Texture2D* new_texture);

    void draw(const Transform2D& transform, Basic::SpriteBatch& sprite_batch);
};

}