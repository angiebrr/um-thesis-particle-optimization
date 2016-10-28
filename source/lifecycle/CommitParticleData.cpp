ConcurrentParticleData::CommitParticleData(particleArray, 
                                           newParticleIndicesArray, 
                                           AABB, Sphere)
{
  // Lock the mutex for the scope of the whole function
  using lock(this.mutex)
  {
    // Copy over all particles to the member particle array
    for(i = 0 to particleArray.size())
    {
      this.particleArray[i] = particleArray[i].copySubset();
    }
    
    // Append the new indices to the member new indices array
    this.newParticleIndices.append( newParticleIndices.copy() );
    
    // Copy the bounding information to the member variables
    this.AABB = AABB.copy();
    this.Sphere = Sphere.copy();
  }
}