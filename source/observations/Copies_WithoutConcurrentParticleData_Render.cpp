ParticleEffectComponent::Render(camera)
{
  // Use the Particle Drawable to draw particles to the screen
  if(this.playbackState is playing or this.playbackState is stopping)
  {
    // Lock the member mutex to keep particles and new particle indices safe
    using lock(this.mutex)
    {
      this.drawable.Draw(camera, this.TakeNewParticleIndices());
    }
  }
}

Drawable::Draw(camera, newParticleIndices)
{
  // Activate the newly emitted particles in the static billboard  
  for(particleIndex in newParticleIndices)
  {
    ActivateParticleInBillboard(particleIndex);
  }

  // Iterate through all of the particles and draw each one
  // The particles array is a member variable of the drawable
  DrawParticles(camera);
}