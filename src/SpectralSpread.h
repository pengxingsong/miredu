
/* MIR.EDU vamp library
 *
 * Feature name: Spectral Spread
 * Description: Compute the spectral spread of each frame of the signal.
 * If a frame is completely silent, a value of 0 is returned.
 * Unit: Hz
 * Formula: computed as the weighted standard deviation,
 * spread = sqrt( sum( (f_i - c)^2 * m_i ) / sum (m_i) )
 * where f_i are frequencies in Hz and m_i are their respective
 * spectral magnitudes, and c is the centroid given by:
 * c = sum(f_i * m_i) / sum(m_i)
 * Reference:
 */

// Remember to use a different guard symbol in each header!
#ifndef _SPECTRALSPREAD_H_
#define _SPECTRALSPREAD_H_

#include <vector>
#include <cmath>
#include <vamp-sdk/Plugin.h>

using std::string;
using std::vector;

class SpectralSpread : public Vamp::Plugin
{
public:
    SpectralSpread(float inputSampleRate);
    virtual ~SpectralSpread();

    string getIdentifier() const;
    string getName() const;
    string getDescription() const;
    string getMaker() const;
    int getPluginVersion() const;
    string getCopyright() const;

    InputDomain getInputDomain() const;
    size_t getPreferredBlockSize() const;
    size_t getPreferredStepSize() const;
    size_t getMinChannelCount() const;
    size_t getMaxChannelCount() const;

    ParameterList getParameterDescriptors() const;
    float getParameter(string identifier) const;
    void setParameter(string identifier, float value);

    ProgramList getPrograms() const;
    string getCurrentProgram() const;
    void selectProgram(string name);

    OutputList getOutputDescriptors() const;

    bool initialise(size_t channels, size_t stepSize, size_t blockSize);
    void reset();

    FeatureSet process(const float *const *inputBuffers,
                       Vamp::RealTime timestamp);

    FeatureSet getRemainingFeatures();

protected:
    // plugin-specific data and methods go here
	size_t m_blockSize;
	size_t m_stepSize;
};


#endif // _SPECTRALSPREAD_H_