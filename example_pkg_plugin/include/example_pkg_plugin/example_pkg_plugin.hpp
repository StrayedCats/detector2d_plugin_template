#pragma once

#include <detector2d_base/detector2d_base.hpp>
#include <detector2d_param/detector2d_param.hpp>
#include <vision_msgs/msg/detection2_d_array.hpp>
#include <opencv2/opencv.hpp>

#include "example_pkg/example.hpp"

namespace detector2d_plugins
{
class DetectorExample : public detector2d_base::Detector
{
public:
  void init(const detector2d_parameters::ParamListener &) override;
  vision_msgs::msg::Detection2DArray detect(const cv::Mat &) override;

private:
  std::shared_ptr<example_pkg::DetectorExample> detector;
  detector2d_parameters::Params params_;
};
}