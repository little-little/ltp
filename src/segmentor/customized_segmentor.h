#ifndef __LTP_SEGMENTOR_CUSTOMIZED_SEGMENTOR_H__
#define __LTP_SEGMENTOR_CUSTOMIZED_SEGMENTOR_H__

#include "segmentor/segmentor.h"
#include "segmentor/customized_options.h"

namespace ltp {
namespace segmentor {

namespace utils = ltp::utility;

/**
 * The class CustomizedSegmentor inherit from the class Segmentor.
 * It is designed for customized segment, which means users can 
 * use two models, baseline model and customized model to segment
 * words. Most of the function responsibility between Segmentor and
 * Customzied is the same, except for that CustomziedSegmentor takes
 * two parts, the baseline and the customzied, as input.
 *
 */
class CustomizedSegmentor : public Segmentor{
public:
  //!
  CustomizedSegmentor();

  //!
  CustomizedSegmentor(utils::ConfigParser & cfg);

  //!
  ~CustomizedSegmentor();

protected:
  //!
  bool parse_cfg(utils::ConfigParser & cfg);

  //!
  void build_configuration(void);

  //!
  void extract_features(const Instance * inst, bool create = false);

  //!
  void calculate_scores(const Instance * inst, bool use_avg);

  //!
  void collect_correct_and_predicted_features(Instance * inst);

  //!
  void build_lexicon_match_state(Instance* inst);

  //!
  void cleanup_decode_context();

  //
  bool train_setup(void);

  //!
  void train_passive_aggressive(int nr_errors);

  //!
  void train_averaged_perceptron(void);

  //!
  int get_timestamp(void);

  //!
  bool test_setup(void);

protected:
  Model * baseline_model;

  DecodeContext* baseline_decode_context;

  CustomizedTrainOptions train_opts;
  CustomizedTestOptions test_opts;
  //CustomizedDumpOptions dump_opts;
};

} // end for namespace segmentor
} // end for namespace ltp

#endif // end for __LTP_SEGMENTOR_PERSONAL_SEGMENTOR_H__
