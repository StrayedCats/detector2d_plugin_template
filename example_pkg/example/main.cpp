#include "example_pkg/example.hpp"

int main(int argc, char** argv)
{
    if(argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_image>" << std::endl;
        return -1;
    }

    example_pkg::DetectorExample detector; /* TODO: Initialize the detector with default values */
    std::string image_path = argv[1];
    std::string image_path_out = image_path.substr(0, image_path.find_last_of(".")) + "_out.jpg";

    cv::Mat frame = cv::imread(image_path);
    vision_msgs::msg::Detection2DArray boxes;
    detector.detect(frame, boxes);

    cv::Mat frame_out = frame.clone();
    for (auto detection : boxes.detections)
    {
        cv::Rect bbox;
        bbox.x = detection.bbox.center.position.x - detection.bbox.size_x / 2;
        bbox.y = detection.bbox.center.position.y - detection.bbox.size_y / 2;
        bbox.width = detection.bbox.size_x;
        bbox.height = detection.bbox.size_y;
        cv::rectangle(frame_out, bbox, cv::Scalar(0, 255, 0), 2);
    }
    cv::imwrite(image_path_out, frame_out);

    return 0;
}