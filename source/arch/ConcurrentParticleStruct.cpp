struct Particle final
{
    bool m_isActive = false;
    Vector3 m_position;
    Vector2 m_scale = Vector2::k_zero;
    f32 m_rotation = 0.0f;
    Colour m_colour = Colour::k_white;
};