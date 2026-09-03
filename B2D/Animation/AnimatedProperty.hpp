#pragma once
#include <Core/Header.hpp>


namespace B2D
{

struct AnimatedProperty
{
    enum class AnimationMethod
    {
        Linear,
    };

    enum class State
    {
        Playing,
        Stop,
    };

    struct InternalData
    {
        f32 begin = 0;
        f32 end = 0;
        f32 duration = 0;
        f32 time = 0; // time elapsed, local
        AnimationMethod method = AnimationMethod::Linear;
        State state = State::Stop;
        bool loop = false;
    } data;

    AnimatedProperty(f32 begin, f32 end, f32 duration);

    void reset(f32 begin, f32 end, f32 duration);
    void set_loop(bool loop);

    void start();
    void stop();

    f32 value();
    void update(f32 dt);
};

}