struct ParticleUpdateDesc final
{
    ParticleEffectCSPtr m_particleEffect;
    ParticleEmitterSPtr m_particleEmitter;
    std::vector<ParticleAffectorSPtr> m_particleAffectors;
    std::shared_ptr<dynamic_array<Particle>> m_particleArray;
    ConcurrentParticleDataSPtr m_concurrentParticleData;
    f32 m_playbackTime = 0.0f;
    f32 m_deltaTime = 0.0f; 
    Vector3 m_entityPosition;
    Vector3 m_entityScale;
    Quaternion m_entityOrientation;
    bool m_interpolateEmission = false;
};