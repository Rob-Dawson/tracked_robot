#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/physics.hh>  // Include the physics header
#include <rclcpp/rclcpp.hpp>
namespace gazebo
{
class WorldPluginTutorial : public WorldPlugin
{
public:
  WorldPluginTutorial() : WorldPlugin()
  {
  }

  void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
  {
    // Initialize ROS 2
    rclcpp::init(0, nullptr);

    // Create a ROS 2 node
    auto node = std::make_shared<rclcpp::Node>("world_plugin_node");

    // Check if ROS 2 node initialization was successful
    if (!rclcpp::ok())
    {
      RCLCPP_ERROR(node->get_logger(), "ROS 2 node initialization failed");
      return;
    }

    RCLCPP_INFO(node->get_logger(), "Hello World!");

    // You can now use the ROS 2 node to publish or subscribe to topics or perform other ROS 2 operations.
  }

};
GZ_REGISTER_WORLD_PLUGIN(WorldPluginTutorial)
}  // namespace gazebo