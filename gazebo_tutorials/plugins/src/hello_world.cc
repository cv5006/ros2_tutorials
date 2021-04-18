#include <gazebo/gazebo.hh>
#include <iostream>
#include "rclcpp/rclcpp.hpp"

namespace gazebo
{
    class WorldPluginTutorial : public WorldPlugin
    {
        public:
            WorldPluginTutorial() : WorldPlugin()
            {
                std::cout << "Hello World!" << std::endl;
            }

            void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
            {
                
            }
    };

    GZ_REGISTER_WORLD_PLUGIN(WorldPluginTutorial)
} // namespace gazebo
