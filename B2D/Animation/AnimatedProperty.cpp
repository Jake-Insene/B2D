#include "B2D/Animation/AnimatedProperty.hpp"

#include <Math/funcs.h>


namespace B2D
{

AnimatedProperty::AnimatedProperty(f32 begin, f32 end, f32 duration)
{
    reset(begin, end, duration);
}

void AnimatedProperty::reset(f32 begin, f32 end, f32 duration)
{
    data.begin = begin;
    data.end = end;
    data.duration = duration;

    data.time = 0;
    data.state = State::Stop;
}

void AnimatedProperty::set_loop(bool loop)
{
    data.loop = loop;
}

void AnimatedProperty::start()
{
    data.time = 0;
    data.state = State::Playing;
}

void AnimatedProperty::stop()
{
    data.state = State::Stop;
}

f32 AnimatedProperty::value()
{
    const f32 t = Math::clamp(data.time / data.duration, 0.0F, 1.0F);
    return Math::lerp<f32>(data.begin, data.end, t);
}

void AnimatedProperty::update(f32 dt)
{
    if(data.state == State::Stop)
    {
        return;
    }

    data.time += dt;
    if(data.time >= data.duration && !data.loop)
    {
        data.state = State::Stop;
    }
    else if(data.time >= data.duration)
    {
        data.time = 0;
    }
}

}