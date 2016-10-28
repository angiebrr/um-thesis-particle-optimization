CS::EntityUPtr State::CreateParticleEffect() 
{
  // Retrieve the singleton application instance through a static method
  auto app = CS::Application::Get();

  // Retrieve the resource pool application system to create a particle effect 
  // from a JSON csparticle file
  auto resourcePool = app->GetResourcePool();
  auto particleEffect = resourcePool
                      ->LoadResource<CS::ParticleEffect>
                      (CS::StorageLocation::k_package, 
                          "Particle/generic.csparticle");

  // Using a render component factory application system and the particle
  // effect, create a particle effect component 
  auto renderComponentFactory = app->GetSystem<CS::RenderComponentFactory>();
  auto particleComponent = renderComponentFactory
                          ->CreateParticleEffectComponent(particleEffect);

  // Set the particle component's playback to looping
  particleComponent
      ->SetPlaybackType(CS::ParticleEffectComponent::PlaybackType::k_looping);

  // Create an entity, and add the particle component to the entity
  auto particleEntity = CS::Entity::Create();
  particleEntity->AddComponent(std::move(particleComponent));

  return particleEntity;
}