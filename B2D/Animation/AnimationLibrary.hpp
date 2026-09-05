#pragma once
#include <Collections/StringMap.hpp>
#include <Math/rect_2d.h>
#include <Basic/Resource/Texture.hpp>


namespace B2D
{

struct AnimationLibrary
{
    struct Frame
    {
        Rect2D uv;
        f32 duration;

        Frame(Rect2D uv, f32 duration)
        : uv(uv), duration(duration)
        {}
    };

    struct Animation
    {
        Mem::Allocator& allocator;
        Collections::StringMap<Frame> frames;
        Collections::Array<Collections::String> sequence;
        
        bool loop;

        Animation(Mem::Allocator& allocator)
        : allocator(allocator), frames(allocator, 4), sequence(allocator, 4, {})
        {}

        void add_frame(Collections::StringView id, Rect2D uv, f32 duration);

        void add_frame_to_sequence(Collections::StringView frame);
    };

    struct InternalData
    {
        Mem::Allocator& allocator;
        
        Basic::Texture2D* spritesheet;
        Collections::StringMap<Animation> animations;

        InternalData(Mem::Allocator& allocator, Basic::Texture2D* spritesheet)
        : allocator(allocator), spritesheet(spritesheet), animations(allocator, 4)
        {
            DebugAssert(spritesheet, "invalid sprite sheet");
        }
    } data;

    AnimationLibrary(Mem::Allocator& allocator, Basic::Texture2D* spritesheet);

    Animation& add_animation(Collections::StringView name, bool loop);
};

}
