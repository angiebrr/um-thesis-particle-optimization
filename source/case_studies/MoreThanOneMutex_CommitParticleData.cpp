ConcurrentParticleData::CommitParticleData(particleArray, 
                                           newParticleIndicesArray, 
                                           AABB, Sphere)
{
  // Lock the particles mutex
  using lock(this.particlesMutex)
  {
    // Copy over all particles to the member particle array
    for(i = 0 to particleArray.size())
    {
      this.particleArray[i] = particleArray[i].copySubset();
    }
  }
  
  // Lock the new particle indices mutex
  using lock(this.newParticleIndicesMutex)
  {  
    // Append the new indices to the member new indices array
    this.newParticleIndices.append( newParticleIndices.copy() );
  }
  
  // Lock the normal (non-data structure) mutex
  using lock(this.normalMutex)
  {  
    // Copy the bounding information to the member variables
    this.AABB = AABB.copy();
    this.Sphere = Sphere.copy();
  }
}