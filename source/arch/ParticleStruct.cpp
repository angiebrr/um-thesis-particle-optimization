struct Particle final
{
    bool m_isActive = false;
    f32 m_lifetime = 0.0f;
    f32 m_energy = 0.0f;
    Vector3 m_position;
    Vector2 m_scale = Vector2::k_one;
    f32 m_rotation = 0.0f;
    Colour m_colour = Colour::k_white;
    Vector3 m_velocity;
    f32 m_angularVelocity = 0.0f;
};