
CS::EntityUPtr BasicEntityFactory::CreateAmbientLight
                                                (const CS::Colour& in_colour)
{
  // Use the application system, Render Component Factory, to create an 
  // ambient light.
  auto ambientLightComponent = m_renderComponentFactory
                                    ->CreateAmbientLightComponent(in_colour);

  // Create an entity, and attach the ambient light component to it.
  auto entity = CS::Entity::Create();
  entity->AddComponent(ambientLightComponent);

  // Return the entity
  return entity;
}