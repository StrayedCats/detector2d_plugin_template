#include "example_pkg_plugin/example_pkg_plugin.hpp"

namespace detector2d_plugins
{

void DetectorExample::init(const detector2d_parameters::ParamListener & param_listener)
{
  params_ = param_listener.get_params();
  // TODO: Initialize the detector with the parameters
  detector = std::make_shared<example_pkg::DetectorExample>();
}

vision_msgs::msg::Detection2DArray DetectorExample::detect(const cv::Mat & image)
{
  vision_msgs::msg::Detection2DArray objects;
  detector->detect(image, objects);

  if (this->params_.debug) {
    cv::imshow("detector", detector->draw_bboxes(image, objects));
    auto key = cv::waitKey(1);
    if (key == 27) {
      rclcpp::shutdown();
    }
  }
  return objects;
}
}// namespace detector2d_plugins

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(detector2d_plugins::DetectorExample, detector2d_base::Detector)
