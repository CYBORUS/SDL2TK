#version 120

uniform float Time;
uniform mat4 MVPM;

attribute vec4 MCVertex;
attribute vec4 MColor;
attribute vec3 Velocity;
attribute float StartTime;
varying vec4 Color;

void main()
{
    vec4 vert;
    float t = Time - StartTime;
    
    if (t >= 0.0)
    {
        t = mod(t, 32.0);
        vert = MCVertex + vec4(Velocity * t, 0.0);
        vert.y -= 4.9 * t * t;
        Color = MColor;
    }
    else
    {
        vert = MCVertex;
        Color = vec4(0.0, 0.0, 0.0, 0.0);
    }
    
    //Color.a = 0.5;
    
    gl_Position = MVPM * vert;
}
