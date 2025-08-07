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

#ifndef UROS_AGENT_UTILS_NAMESPACE_CPP_
#define UROS_AGENT_UTILS_NAMESPACE_CPP_

#include <agent/utils/namespace.hpp>

namespace uros {
namespace agent {
namespace utils {

bool Namespace::is_ros_topic(
        const std::string& topic_name)
{
    return (topic_name.length() >= 3 &&
            (topic_name.substr(0, 3) == "rq/" || 
             topic_name.substr(0, 3) == "rt/" || 
             topic_name.substr(0, 3) == "rr/"));
}

bool Namespace::is_global_topic(
        const std::string& topic_name)
{
    return (topic_name == "/tf" || 
            topic_name == "/tf_static" || 
            topic_name == "/diagnostics" || 
            topic_name == "/rosout" || 
            topic_name == "/parameter_events");
}

std::string Namespace::apply_namespace_to_topic(
        const std::string& topic_name,
        const std::string& namespace_prefix)
{
    if (namespace_prefix.empty() || 
        namespace_prefix == "/" || 
        !is_ros_topic(topic_name) || 
        is_global_topic(topic_name.substr(2)))
    {
        return topic_name;
    }

    std::string service_prefix = topic_name.substr(0, 2);
    std::string remaining_topic = topic_name.substr(2);
                
    return service_prefix + namespace_prefix + remaining_topic;
}

std::string Namespace::apply_namespace_to_node(
        const std::string& node_namespace,
        const std::string& namespace_prefix)
{
        if (node_namespace == "/")
        {
            return namespace_prefix;
        }
        else
        {
            return namespace_prefix + node_namespace;
        }
}

}  // namespace utils
}  // namespace agent
}  // namespace uros

#endif  // UROS_AGENT_UTILS_NAMESPACE_CPP_
