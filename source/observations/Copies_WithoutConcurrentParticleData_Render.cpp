ParticleEffectComponent::Render(camera)
{
  // Use the Particle Drawable to draw particles to the screen
  if(this.playbackState == playing or this.playbackState == stopping)
  {
    // Lock the member mutex to keep particles and new particles safe
    using lock(this.mutex)
    {
      this.drawable->Draw(camera, this.GetNewParticleIndices());
    }
  }
}

Drawable::Draw(camera, newParticleIndices)
{
  // Activate the newly emitted particles in the static billboard  
  for(int index : newParticleIndices)
  {
    ActivateParticleInBillboard(index);
  }

  // Iterate through all of the particles and draw each one
  // The particles array is a member variable of the drawable
  DrawParticles(camera);
}