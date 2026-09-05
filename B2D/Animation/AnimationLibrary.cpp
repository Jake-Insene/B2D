#include "B2D/Animation/AnimationLibrary.hpp"


namespace B2D
{

void AnimationLibrary::Animation::add_frame(Collections::StringView id, Rect2D uv, f32 duration)
{
    frames.emplace(id, uv, duration);
}

void AnimationLibrary::Animation::add_frame_to_sequence(Collections::StringView frame)
{
    (void)sequence.emplace(allocator, 0, frame);
}

AnimationLibrary::AnimationLibrary(Mem::Allocator& allocator, Basic::Texture2D* spritesheet)
: data(allocator, spritesheet)
{
}

AnimationLibrary::Animation& AnimationLibrary::add_animation(Collections::StringView name, bool loop)
{
    Animation& anim = data.animations.emplace(name, data.allocator);
    anim.loop = loop;
    return anim;
}

}
