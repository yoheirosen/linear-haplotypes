#ifndef EXTENSION_SET_H
#define EXTENSION_SET_H

#include "reference.hpp"
#include "DP_map.hpp"
#include "probability.hpp"
#include "penalty_set.hpp"
#include <vector>

using namespace std;

struct extensionSet{
private:
  vector<DPUpdateMap> current_map;
  vector<vector<size_t> > active_rows;
  vector<bool> match_is_rare;
public:
  extensionSet(haplotypeCohort* cohort, size_t site_index);
  bool get_match_is_rare(size_t i) const;
  alleleValue get_allele(size_t i) const;
  const vector<size_t>& get_active_rows(size_t i) const;
  void extend_probability_by_allele(fastFwdAlgState* hap_mat, size_t i);
};

#endif