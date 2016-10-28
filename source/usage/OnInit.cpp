void State::OnInit() 
{
  // Retrieve the resource pool application system to create a particle effect 
  // Set the state's current scene's clear color to black
  GetScene()->SetClearColour(CS::Colour::k_black);

  // Retrieve an application system that will help create basic entities like 
  // cameras, rooms, and lights.
  auto basicEntityFactory = CS::Application::Get()
                          ->GetSystem<Common::BasicEntityFactory>();

  // Create a basic room and add it to the scene
  CS::EntitySPtr room = basicEntityFactory->CreateRoom();
  room->GetTransform().SetPosition(0.0f, 10.0f, 0.0f);
  GetScene()->Add(room);

  // Create a third person camera and add it to the scene
  auto camera = basicEntityFactory
              ->CreateThirdPersonCamera(room, CS::Vector3(0.0f, -9.0f, 0.0f));
  GetScene()->Add(std::move(camera));

  // Create an ambient light and add it to the scene
  CS::EntitySPtr ambientLight = basicEntityFactory
                              ->CreateAmbientLight
                              (CS::Colour(0.65f, 0.65f, 0.65f, 1.0f));
  GetScene()->Add(ambientLight);

  // Create a particle effect entity and add it to the scene
  auto particleEntity = CreateParticleEffect();
  GetScene()->Add(std::move(particleEntity));
}