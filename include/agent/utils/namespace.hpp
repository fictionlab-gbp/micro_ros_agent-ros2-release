// Copyright (c) 2025 Fictionlab sp. z o.o.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef UROS_AGENT_UTILS_NAMESPACE_HPP_
#define UROS_AGENT_UTILS_NAMESPACE_HPP_

#include <string>

namespace uros {
namespace agent {
namespace utils {

class Namespace
{
private:
    /**
     * @brief   Default constructor. Creating instances of this class is not allowed.
     */
    Namespace() = default;

    /**
     * @brief   Default destructor.
     */
    ~Namespace() = default;

public:
    /**
     * @brief   Check if a topic name is a ROS topic (starts with rq/, rt/, or rr/).
     * @param   topic_name Topic name to check.
     * @returns True if the topic is a ROS topic with service prefixes, false otherwise.
     */
    static bool is_ros_topic(
            const std::string& topic_name);

    /**
     * @brief   Check if a topic name is a topic that should have global namespace (eg. tf, rosout).
     * @param   topic_name Topic name to check.
     * @returns True if the topic is a global topic, false otherwise.
     */
    static bool is_global_topic(
            const std::string& topic_name);

    /**
     * @brief   Apply namespace to a ROS topic.
     * @param   topic_name Original topic name.
     * @param   namespace_prefix Namespace to apply (should start with /).
     * @returns The topic name with namespace applied.
     */
    static std::string apply_namespace_to_topic(
            const std::string& topic_name,
            const std::string& namespace_prefix);

    /**
     * @brief   Apply namespace to a ROS node.
     * @param   node_name Original node name.
     * @param   namespace_prefix Namespace to apply (should start with /).
     * @returns The node name with namespace applied.
     */
    static std::string apply_namespace_to_node(
            const std::string& node_namespace,
            const std::string& namespace_prefix);
};

}  // namespace utils
}  // namespace agent
}  // namespace uros

#endif  // UROS_AGENT_UTILS_NAMESPACE_HPP_
