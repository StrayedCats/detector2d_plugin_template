#include "example_pkg_plugin/example_pkg_plugin.hpp"

namespace detector2d_plugins
{

void DetectorExample::init(const detector2d_parameters::ParamListener & param_listener)
{
  this->params_ = param_listener.get_params();

  // TODO: Initialize the detector with the parameters
  this->detector = std::make_shared<example_pkg::DetectorExample>();
}

vision_msgs::msg::Detection2DArray DetectorExample::detect(const cv::Mat & image)
{
  vision_msgs::msg::Detection2DArray objects;
  this->detector->detect(image, objects);
  return objects;
}
}// namespace detector2d_plugins

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(detector2d_plugins::DetectorExample, detector2d_base::Detector)
