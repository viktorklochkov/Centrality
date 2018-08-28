//
// Created by Viktor Klochkov on 08.08.18.
//

#ifndef CENTRALITY_BORDERSFINDER_H
#define CENTRALITY_BORDERSFINDER_H

#include "TH1.h"

namespace Centrality {
    
class BordersFinder {

public:
    
    BordersFinder(){}
    
    void FindBorders();
    void SaveBorders(std::string filename);

    
    void SetHisto(const TH1F &h)  { histo_ = h; }
    const TH1F& GetHisto() const  { return histo_; }
    
    void SetNormalization (long int norm) { norm_ = norm; }
    long int GetNormalization () const { return norm_; }
    
    void SetRanges(const std::vector<float> &ranges) { ranges_ = ranges; }
    void SetRanges(int n, float min, float max) 
    {
        ranges_.clear();
//         ranges_.reserve(n+1);
        
        for (int i=0; i<=n; ++i)
            ranges_.push_back( min + i*(max-min)/n );
    }
    
    void IsSpectator(bool is=true) { isspectator_ = is; }
    
private:
    
    TH1F histo_;
    long int norm_{-1};
        
    std::vector<float> ranges_;
    std::vector<double> borders_;
    
    bool isspectator_{false};
    
};
}

#endif //CENTRALITY_BORDERSFINDER_H